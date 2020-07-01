cmake_minimum_required(VERSION 3.17)

set(This UnitTests)

set(Sources
    ExampleTests.cpp
    ExampleTests2.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

add_test(
    NAME ${This}
    COMMAND ${This}
)