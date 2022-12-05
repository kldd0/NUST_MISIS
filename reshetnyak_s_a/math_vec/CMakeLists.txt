cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

# if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.12.25835)
#     set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
#     set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
# endif()

project("vectors")

add_subdirectory(vectors) # for vectors library

# add_subdirectory(models) # for models

include_directories(.)

# add_executable(
#     vectors_models
#     vectors_models.cpp
# )

# target_link_libraries(vectors_models vectors)

add_executable(
    vectors_test
    vectors_test.cpp
)

target_link_libraries(vectors_test vectors)

add_executable(
    vectors_entrypoint
    vectors_entrypoint.cpp
    vectors_models.cpp
)

target_link_libraries(vectors_entrypoint vectors)