cmake_minimum_required(VERSION 3.10)
project(linux_project_master)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(linux_project_master
        DB/dbInit.c
        DB/main.c
        Home.cpp
        Home.h
        RequestManager.cpp
        RequestManager.h
        Socket.cpp
        Socket.h
        User.cpp
        User.h Database.cpp Database.h main.cpp)
