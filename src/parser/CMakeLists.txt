cmake_minimum_required(VERSION 3.8)
# -*- mode:cmake -*-
if(NOT UNIX)
  message(WARNING "Unsupported operating system")
endif()

set(antlr4-parser-GENERATED_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/SesameLexer.cpp 
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/SesameParser.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/SesameParserBaseListener.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/SesameParserBaseVisitor.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/SesameParserListener.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/generated/SesameParserVisitor.cpp
 )

foreach(src_file ${antlr4-parser-GENERATED_SRC})
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach(src_file ${antlr4-parser-GENERATED_SRC})

add_custom_target(GenerateParser DEPENDS ${antlr4-parser-GENERATED_SRC})

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/misc
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/atn
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/dfa
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/tree
  ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/support
  ${CMAKE_CURRENT_SOURCE_DIR}/generated
  ${CMAKE_CURRENT_SOURCE_DIR}/parsing/
  )

#file(GLOB antlr4-src/parser_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/generated/*")
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
add_library(sesame_parser SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/parsing/parser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/parsing/build_ast.cpp
  ${antlr4-parser_SRC}
  )

add_dependencies(sesame_parser GenerateParser)

target_link_libraries(sesame_parser antlr4_shared)

install(TARGETS sesame_parser 
        DESTINATION "share" 
        COMPONENT dev 
        )

add_subdirectory(runtime)
