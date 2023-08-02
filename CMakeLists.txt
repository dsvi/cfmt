cmake_minimum_required(VERSION 3.11)
include(FetchContent)

project(cfmt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
    fmt
    URL https://github.com/fmtlib/fmt/archive/refs/tags/10.0.0.tar.gz
    URL_HASH SHA256=ede1b6b42188163a3f2e0f25ad5c0637eca564bd8df74d02e31a311dd6b37ad8
)
FetchContent_MakeAvailable(fmt)

add_executable(cfmt main.c++ cfmt.h)

target_link_libraries(
    cfmt
    PRIVATE
        fmt::fmt
)
