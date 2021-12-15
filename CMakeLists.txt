cmake_minimum_required (VERSION 2.8)

project (jack)

include_directories (domain/socket_wrapper/inc common/inc common/data_struct/inc domain/data_struct_test/inc)

aux_source_directory (domain/socket_wrapper/src SRC_LIST_SOCKET)
aux_source_directory (common/data_struct/src SRC_LIST_DATA)
aux_source_directory (domain/data_struct_test/src SRC_LIST_DATA_TEST)

SET(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")
add_compile_options(-g)

add_executable (main app/test_main.c ${SRC_LIST_SOCKET} ${SRC_LIST_DATA} ${SRC_LIST_DATA_TEST})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
