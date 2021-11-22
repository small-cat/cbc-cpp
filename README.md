# cbc-cpp
用 c++ 实现的一个 c-like 的编译器前端，参考 cbc 的实现。使用 antlr4 作为词法语法分析器。

# build
直接执行根目录下的 `build.sh` 进行编译。默认是 debug 模式进行编译。

```shell
./build.sh
```

# usage
编译完成后，可以使用 `-h` 或者 `--help` 查看帮助信息，当前的帮助信息中，很多功能暂时还没有实现。后续会一点点添加上。

已经实现了 `Global Options` 中的如下功能：

- check-syntax
- dump-tokens
- dump-ast
- dump-semantic

需要使用 `-I path` 指定 import 的头文件的路径。

比如下面这个测试文件 `Hello.cb`

```
import stdio;

int
main(int argc, char **argv)
{
    int a = 4 + 8 / (1 + 2) * 4;
    printf("Hello, World!\n");
    return 0;
}
```
使用 `--dump-ast` 打印该程序的抽象语法树
```
# ./sesame --dump-ast -I test/import hello.cb
...

variables:
functions:
  FunctionName: main
  IsPrivate: false
  Parameters: 
    Params:
      Name: argc
      TypeNode: int
      Name: argv
      TypeNode: char**
  FunctionBody: 
    <<BlockNode>> (hello.cb, line 5, column 0)
    variables:
      VariableName: a
      IsPrivate: false
      TypeNode: int
      Initializer: 
        <<BinaryOpNode>> (hello.cb, line 6, column 12)
        Operator: +
        Left: 
          <<IntegerLiteralNode>> (hello.cb, line 6, column 12)
          TypeNode: int
          Value: 4
        Right: 
          <<BinaryOpNode>> (hello.cb, line 6, column 16)
          Operator: *
          Left: 
            <<BinaryOpNode>> (hello.cb, line 6, column 16)
            Operator: /
            Left: 
              <<IntegerLiteralNode>> (hello.cb, line 6, column 16)
              TypeNode: int
              Value: 8
            Right: 
              <<BinaryOpNode>> (hello.cb, line 6, column 21)
              Operator: +
              Left: 
                <<IntegerLiteralNode>> (hello.cb, line 6, column 21)
                TypeNode: int
                Value: 1
              Right: 
                <<IntegerLiteralNode>> (hello.cb, line 6, column 25)
                TypeNode: int
                Value: 2
          Right: 
            <<IntegerLiteralNode>> (hello.cb, line 6, column 30)
            TypeNode: int
            Value: 4
    statements:
      <<ExprStmtNode>> (hello.cb, line 7, column 4)
      expr: 
        <<FunctioncallNode>> (hello.cb, line 7, column 4)
        Expr: 
          <<VariableNode>> (hello.cb, line 7, column 4)
          name: printf
        Arguments:
          <<StringLiteralNode>> (hello.cb, line 7, column 11)
          Value: "Hello, World!\n"
      <<ReturnStmtNode>> (hello.cb, line 8, column 4)
      Expr: 
        <<IntegerLiteralNode>> (hello.cb, line 8, column 11)
        TypeNode: int
        Value: 0
```
如果想检查语义，可以使用 `--dump-semantic`
```
# ./sesame --dump-semantic -I test/import hello.cb
...

"sesame" warn at ../test/import/stddef.hb, line 3, column 6 >> unused variable: NULL
"sesame" warn at hello.cb, line 4, column 5 >> unused variable: argc
"sesame" warn at hello.cb, line 4, column 15 >> unused variable: argv
"sesame" warn at hello.cb, line 6, column 4 >> unused variable: a
```
如上所示，找出了代码中所有申明但是没有使用的变量，包括头文件中申明的变量。提示信息还有待改进(囧！)