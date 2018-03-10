cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes naive-bayes.cpp FeatureVector.cpp FeatureVector.hpp TrainingData.hpp TrainingData.cpp
        DataFile.cpp DataFile.hpp)
add_executable(unit-tests tests.cpp)
