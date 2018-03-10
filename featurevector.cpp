//
// Created by joshua cheng on 3/10/2018.
//
#include <vector>
#include <iostream>
#include "featurevector.hpp"

std::istream & operator>>(std::istream& input_stream, FeatureVector &featureVector) {
    if (!input_stream) {
        std::cout << "failure" << std::endl;
        return input_stream;
    }

    char currentChar;


    for (int i = 0; i < FeatureVector::DIMENSIONS; ++i) {
        for (int j = 0; j < FeatureVector::DIMENSIONS; ++j) {
            input_stream.get(currentChar);

            featureVector.features_[i][j] = currentChar == '#' || currentChar == '+';
        }
    }

    return input_stream;

}

std::ostream & operator<<(std::ostream& output_stream, const FeatureVector &featureVector) {
    for (int i = 0; i < FeatureVector::DIMENSIONS; ++i) {
        for (int j = 0; j < FeatureVector::DIMENSIONS; ++j) {
            if (featureVector.features_[i][j]) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    }
}





