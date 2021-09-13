cmake_minimum_required(VERSION 3.1)

project(service_discovery)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall)

include_directories($ENV{ASIO_PATH})
add_executable(example example.cpp)
