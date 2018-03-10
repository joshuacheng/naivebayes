//
// Created by bjcheng on 3/10/2018.
//

#include "DataFile.hpp"
#include <fstream>
#include <iostream>

DataFile::DataFile(std::string fileName) {
    std::ifstream file(fileName);

    if (!file) {
        std::cout << "failure to open" << std::endl;
    }

    FeatureVector featureVector{};

    while (file) {
        file >> featureVector;


        images_.push_back(featureVector);
    }


}

void DataFile::printGivenFeatureVector(int index) {
    std::cout << images_[index];
}

int DataFile::getSize() {
    return images_.size();
}

vector<FeatureVector> DataFile::getImages() {
    return images_;
}



