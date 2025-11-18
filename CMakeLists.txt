cmake_minimum_required(VERSION 4.0)
project(labo_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(labo_cpp main.cpp)


add_executable(main theorie/h2/main.cpp)

# Maak executables oefening0 t.e.m. oefening8
foreach(i RANGE 0 8)
    add_executable(oefening${i} labo1/oefening${i}.cpp)
endforeach()
