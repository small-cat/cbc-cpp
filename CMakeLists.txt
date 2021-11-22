cmake_minimum_required(VERSION 2.8)
project(sesame)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_CONFIGURATION_TYPES "DEBUG;Release;RelWithDebInfo" CACHE STRING "" FORCE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "set -DCMAKE_BUILD_TYPE=Debug if needed" FORCE)

  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(STRINGS "VERSION" SVERSION)
add_definitions(-Wall -Wno-unused-function -DSVERSION=${SVERSION})

# set MACROS for program
execute_process(COMMAND bash "-c" "gcc --version | head -n1 | tr -d '\n'" OUTPUT_VARIABLE COMPILE_TOOL_VERSION)
execute_process(COMMAND bash "-c" "uname -r | tr -d '\n'" OUTPUT_VARIABLE COMPILE_OS)
execute_process(COMMAND bash "-c" "git log | head -n1 | awk '{print $2}' | tr -d '\n'" OUTPUT_VARIABLE COMMIT_ID)
execute_process(COMMAND bash "-c" "date '+%Y-%m-%d %H:%M:%S' | tr -d '\n'" OUTPUT_VARIABLE BUILD_DATE)

set(MY_CXX_FLAGS "-DCOMPILE_TOOL_VERSION=\"${COMPILE_TOOL_VERSION}\" \
                  -DCOMPILE_OS=\"${COMPILE_OS}\" \
                  -DBUILD_DATE=\"${BUILD_DATE}\" \
                  -DCOMMIT_ID=\"${COMMIT_ID}\"")

#set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -DDEBUG_0 -DDEBUG_ATN=1 -DDEBUG_LIST_ATN_DECISIONS=1 -DDEBUG_ANTLR=true")
set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -DDEBUG_0 ${MY_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -O3 ${MY_CXX_FLAGS}")

include_directories(
  # ${PROJECT_SOURCE_DIR}/src/compiler
  # ${PROJECT_SOURCE_DIR}/src/parser
  # ${PROJECT_SOURCE_DIR}/src/sysdep
  # ${PROJECT_SOURCE_DIR}/src/utils
  # ${PROJECT_SOURCE_DIR}/src/ast
  # ${PROJECT_SOURCE_DIR}/src/type
  # ${PROJECT_SOURCE_DIR}/src/entity
  # ${PROJECT_SOURCE_DIR}/src/parser
  # ${PROJECT_SOURCE_DIR}/src/syntax/
  # ${PROJECT_SOURCE_DIR}/src/syntax/runtime

  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/src/syntax/runtime/src
  )

file(GLOB_RECURSE COMPILE_SRC "src/compiler/*.cpp")
file(GLOB_RECURSE MAIN_SRC "src/main/main.cpp")
file(GLOB_RECURSE SYSDEP_SRC "src/sysdep/*.cpp")
file(GLOB_RECURSE UTILS_SRC "src/utils/*.cpp")
file(GLOB_RECURSE AST_SRC "src/ast/*.cpp")
file(GLOB_RECURSE TYPE_SRC "src/type/*.cpp")
file(GLOB_RECURSE ENTITY_SRC "src/entity/*.cpp")
file(GLOB_RECURSE PARSER_SRC "src/parser/*.cpp")

add_executable(sesame
  ${ENTITY_SRC}
  ${AST_SRC}
  ${TYPE_SRC}
  ${UTILS_SRC}
  ${SYSDEP_SRC}
  ${PARSER_SRC}
  ${COMPILE_SRC}
  ${MAIN_SRC}
)

target_link_libraries(sesame sesame_syntax)

add_subdirectory(src)
