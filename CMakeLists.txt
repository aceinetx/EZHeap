cmake_minimum_required(VERSION 3.8)
project(ezheap)

# uncomment this to debug ezheap
# add_compile_definitions("EZHEAP_DBG")

include_directories("include")

set(SOURCES_LIB "src/ezheap.c")
add_library("ezheap" ${SOURCES_LIB})

set(SOURCES_EXE "src/test.c")
add_executable("test" ${SOURCES_EXE})
target_link_libraries("test" "ezheap")
