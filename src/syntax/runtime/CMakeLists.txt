
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/atn
  ${CMAKE_CURRENT_SOURCE_DIR}/src/dfa
  ${CMAKE_CURRENT_SOURCE_DIR}/src/misc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/support
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tree
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/pattern
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tree/xpath
)


file(GLOB libantlrcpp_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/atn/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/dfa/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/misc/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/support/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tree/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tree/pattern/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tree/xpath/*.cpp"
)

add_library(antlr4_shared SHARED ${libantlrcpp_SRC})

set(LIB_OUTPUT_DIR "${CMAKE_HOME_DIRECTORY}/dist") # put generated libraries here.
message(STATUS "Output libraries to ${LIB_OUTPUT_DIR}")

# make sure 'make' works fine even if ${LIB_OUTPUT_DIR} is deleted.
add_custom_target(make_lib_output_dir ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${LIB_OUTPUT_DIR}
    )

add_dependencies(antlr4_shared make_lib_output_dir)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  target_link_libraries(antlr4_shared ${UUID_LIBRARIES})
  target_link_libraries(antlr4_shared -ltcmalloc)
endif()

set(disabled_compile_warnings "-Wno-overloaded-virtual")
set(extra_share_compile_flags "")
set(extra_static_compile_flags "")

set(static_lib_suffix "")
set_target_properties(antlr4_shared
                      PROPERTIES VERSION   ${ANTLR_VERSION}
                                 SOVERSION ${ANTLR_VERSION}
                                 OUTPUT_NAME antlr4-runtime
                                 LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
                                 # TODO: test in windows. DLL is treated as runtime.
                                 # see https://cmake.org/cmake/help/v3.0/prop_tgt/LIBRARY_OUTPUT_DIRECTORY.html
                                 RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
                                 ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
                                 COMPILE_FLAGS "${disabled_compile_warnings} ${extra_share_compile_flags}")

install(TARGETS antlr4_shared
        DESTINATION lib 
        EXPORT antlr4-targets)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/" 
        DESTINATION "include/antlr4-runtime"
        COMPONENT dev 
        FILES_MATCHING PATTERN "*.h"
        )

