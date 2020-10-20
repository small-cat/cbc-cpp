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

set(CMAKE_CXX_FLAGS_DEBUG     "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -DDEBUG_0")
set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(
  ${PROJECT_SOURCE_DIR}/src/compiler
  ${PROJECT_SOURCE_DIR}/src/parser
  ${PROJECT_SOURCE_DIR}/src/sysdep
  ${PROJECT_SOURCE_DIR}/src/utils
  )

file(GLOB_RECURSE COMPILE_SRC "src/compiler/*.cpp")
file(GLOB_RECURSE MAIN_SRC "src/main/main.cpp")
file(GLOB_RECURSE SYSDEP_SRC "src/sysdep/*.cpp")
file(GLOB_RECURSE UTILS_SRC "src/utils/*.cpp")

add_executable(sesame
  ${COMPILE_SRC}
  ${MAIN_SRC}
  ${SYSDEP_SRC}
  ${UTILS_SRC})

target_link_libraries(sesame sesame_parser)

add_subdirectory(src)
