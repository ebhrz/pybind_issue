cmake_minimum_required(VERSION 3.0)
project(test)

find_package(pybind11 CONFIG REQUIRED)



include_directories("/usr/include/python3.8" "/home/hrz/.penv/pytorch/lib/python3.8/site-packages/pybind11/include" "${PROJECT_SOURCE_DIR}")

add_library(test MODULE test.cpp impl.cpp)
target_link_libraries(test PUBLIC pybind11::module m pthread)

