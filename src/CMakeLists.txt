cmake_minimum_required(VERSION 3.12)
project(classesTwitter)

set(CMAKE_CXX_STANDARD 11)

    add_executable(classesTwitter Feed.cpp Feed.hpp Usuario.cpp Usuario.hpp Mencao.cpp Mencao.hpp main.cpp Tweet.cpp Tweet.hpp)