//
// Created by joshua cheng on 3/10/2018.
//
#include <vector>
#include <iostream>
#include <string>
#include "FeatureVector.hpp"


/** Overloaded >> operator for writing to a feature vector from a file.
 *
 * @param input_stream      input stream for file, usually ifstream
 * @param featureVector     feature vector to write to
 * @return                  istream
 */
std::istream & operator>>(std::istream& input_stream, FeatureVector &featureVector) {
    if (!input_stream) {
        std::cout << "failure" << std::endl;
        return input_stream;
    }

    std::string str;
    std::vector<std::vector<bool>> features(FeatureVector::DIMENSIONS, std::vector<bool>(FeatureVector::DIMENSIONS));

    for (int i = 0; i < FeatureVector::DIMENSIONS; ++i) {
        getline(input_stream, str);
        for (int k = 0; k < str.size(); ++k) {
//            featureVector.features_[i][k] = str[k] == '#' || str[k] == '+';
            features[i][k] = str[k] == '#' || str[k] == '+';
        }
    }

    featureVector.features1_ = features;


    return input_stream;

}

// Overloaded << operator just for printing out a feature vector with 1's and 0's.
std::ostream & operator<<(std::ostream& output_stream, const FeatureVector &featureVector) {
    for (int i = 0; i < FeatureVector::DIMENSIONS; ++i) {
        for (int j = 0; j < FeatureVector::DIMENSIONS; ++j) {
            if (featureVector.features1_[i][j]) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<bool>> FeatureVector::getFeatureArray() {
    return features1_;
}






