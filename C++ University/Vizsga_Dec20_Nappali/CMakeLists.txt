cmake_minimum_required(VERSION 3.23)
project(Vizsga_Dec20_Nappali)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Vizsga_Dec20_Nappali
        foglalas.cpp
        foglalas.h
        handler.cpp
        handler.h
        main.cpp
        szoba.cpp
        szoba.h)
