cmake_minimum_required(VERSION 3.15)
project(bonoexamen C)

set(CMAKE_C_STANDARD 99)

include_directories(libreria)
add_executable(bonoexamenmain bonoexamen/bonoexamenmain.c bonoexamen/bonoexamen.c bonoexamen/bonoexamen.h)
add_executable(bonoexamenminunit3 bonoexamen/bonoexamenminunit3.c bonoexamen/bonoexamen.c bonoexamen/bonoexamen.h)
add_executable(bonoexamenminunit4 bonoexamen/bonoexamenminunit4.c bonoexamen/bonoexamen.c bonoexamen/bonoexamen.h)
add_executable(bonoexamenminunit5 bonoexamen/bonoexamenminunit5.c bonoexamen/bonoexamen.c bonoexamen/bonoexamen.h)
add_executable(bonoexamenminunit6 bonoexamen/bonoexamenminunit6.c bonoexamen/bonoexamen.c bonoexamen/bonoexamen.h)