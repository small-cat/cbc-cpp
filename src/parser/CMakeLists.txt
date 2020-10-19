cmake_minimum_required(VERSION 3.8)
project(parser)
# -*- mode:cmake -*-
if(NOT UNIX)
  message(WARNING "Unsupported operating system")
endif()

set(antlr4-parser-GENERATED_SRC
   ${PROJECT_SOURCE_DIR}/generated/SesameLexer.cpp 
   ${PROJECT_SOURCE_DIR}/generated/SesameParser.cpp
   ${PROJECT_SOURCE_DIR}/generated/SesameParserBaseListener.cpp
   ${PROJECT_SOURCE_DIR}/generated/SesameParserBaseVisitor.cpp
   ${PROJECT_SOURCE_DIR}/generated/SesameParserListener.cpp
   ${PROJECT_SOURCE_DIR}/generated/SesameParserVisitor.cpp
 )

foreach(src_file ${antlr4-parser-GENERATED_SRC})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach(src_file ${antlr4-parser-GENERATED_SRC})

add_custom_target(GenerateParser DEPENDS ${antlr4-parser-GENERATED_SRC})
# add_custom_command(OUTPUT ${antlr4-parser-GENERATED_SRC}
#    COMMAND 
#    ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/parser/generated/
#    COMMAND
#    "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${PROJECT_SOURCE_DIR}/src/parser/generated/ -package parser ${PROJECT_SOURCE_DIR}/src/parser/SesameLexer.g4 ${PROJECT_SOURCE_DIR}/src/parser/SesameParser.g4
#    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
#    DEPENDS ${PROJECT_SOURCE_DIR}/src/parser/SesameLexer.g4 ${PROJECT_SOURCE_DIR}/src/parser/SesameParser.g4
#    )

include_directories(
  ${PROJECT_SOURCE_DIR}/runtime/src
  ${PROJECT_SOURCE_DIR}/runtime/src/misc
  ${PROJECT_SOURCE_DIR}/runtime/src/atn
  ${PROJECT_SOURCE_DIR}/runtime/src/dfa
  ${PROJECT_SOURCE_DIR}/runtime/src/tree
  ${PROJECT_SOURCE_DIR}/runtime/src/support
  ${PROJECT_SOURCE_DIR}/generated
  )

#file(GLOB antlr4-src/parser_SRC "${PROJECT_SOURCE_DIR}/src/parser/generated/*")
set(antlr4-parser_SRC 
  ${antlr4-parser-GENERATED_SRC}
  )

foreach(src_file ${antlr4-parser_SRC})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach(src_file ${antlr4-parser_SRC})

# executable file name
add_executable(antlr4-parser
  main.cpp
  ${antlr4-parser_SRC}
  )

add_dependencies(antlr4-parser GenerateParser)

target_link_libraries(antlr4-parser antlr4_static)

install(TARGETS antlr4-parser 
        DESTINATION "share" 
        COMPONENT dev 
        )

add_subdirectory(runtime)
