cmake_minimum_required(VERSION 3.26)
project(Olympic)

set(CMAKE_CXX_STANDARD 23)


add_executable(Olympic main.cpp
        httplib.h)

target_link_libraries(Olympic PRIVATE Ws2_32)