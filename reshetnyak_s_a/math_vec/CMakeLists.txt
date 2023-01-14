cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 20)

project("gravity-modeling")

option(USE_STATIC "Use static library" ON)
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

include_directories(.)

# making executable for running tests
add_executable(
    run_tests
    vectors_test.cpp
)

# executable for main program
add_executable(
    entrypoint
    vectors_entrypoint.cpp
    vectors_models.cpp
)

add_library(vectors-obj
    OBJECT
        lib-vectors/vectors.cpp
        lib-vectors/vectors.hpp
)

target_compile_options(vectors-obj
    PRIVATE
        -Wall
)

if(USE_STATIC)
    add_library(vectors-a
        STATIC
            $<TARGET_OBJECTS:vectors-obj>
    )
    target_link_libraries(entrypoint vectors-a)
    target_link_libraries(run_tests vectors-a)

else()
    add_library(vectors-so
        SHARED
            $<TARGET_OBJECTS:vectors-obj>
    )
    target_link_libraries(entrypoint vectors-so)
    target_link_libraries(run_tests vectors-so)
endif()