cmake_minimum_required(VERSION 3.6)
project(uex1010Base)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/entorno.cpp
        src/entorno.h
        src/TADjuego.cpp
        src/TADjuego.h
        src/TADpieza.cpp
        src/TADpieza.h
        src/TADtablero.cpp
        src/TADtablero.h
        src/uex1010base2.cpp)

add_executable(uex1010Base ${SOURCE_FILES})