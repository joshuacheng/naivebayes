cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes main.cpp FeatureVector.cpp FeatureVector.hpp DataFile.cpp DataFile.hpp Model.cpp Model.hpp)
add_executable(unit-tests tests.cpp)
