cmake_minimum_required(VERSION 3.8)

project("vectors")

add_subdirectory(vectors)

include_directories(.)

add_executable(
    vectors.test
    vectors.test.cpp
)

target_link_libraries(vectors.test vectors)