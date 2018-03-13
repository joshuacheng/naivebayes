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

    if (featureVector.features_.size() > 0) {
        featureVector.features_.clear();
    }

    std::string str;

    for (int i = 0; i < FeatureVector::DIMENSIONS; ++i) {
        getline(input_stream, str);
        for (int k = 0; k < str.size(); ++k) {
            featureVector.features_.push_back(str[k] == '#' || str[k] == '+');
        }
    }

    return input_stream;

}

/**
 * Overloaded << operator just for printing out a feature vector with 1's and 0's.
 */
std::ostream & operator<<(std::ostream& output_stream, const FeatureVector &featureVector) {

    for (int i = 0; i < featureVector.features_.size(); ++i) {
        if (featureVector.features_[i]) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }

        // Start next line after 28 columns.
        if ((i + 1) % 28 == 0 && i != 0) {
            std::cout << std::endl;
        }
    }

    return output_stream;
}

std::vector<bool> FeatureVector::getFeatureArray() const {
    return features_;
}








