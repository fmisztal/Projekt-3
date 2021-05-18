cmake_minimum_required(VERSION 3.5)

project(Project3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -RELEASE")

add_executable(Project3 main.cpp container.cpp element.cpp Hearing_aid.cpp electronic_device.cpp battery.cpp user.cpp parameters.cpp)
