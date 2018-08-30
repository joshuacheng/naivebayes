//
// Created by bjcheng on 3/10/2018.
//

#include "DataFile.hpp"
#include <fstream>
#include <iostream>

/** Constructor for a data file, which just contains all the feature vectors (images)
 *  of a given file.
 *
 * @param fileName
 */
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

// Prints the feature vector at given index, used for testing
void DataFile::printGivenFeatureVector(int index) {
    std::cout << images_[index];
}

int DataFile::getNumberOfImages() {
    return static_cast<int>(images_.size());
}

vector<FeatureVector> DataFile::getImages() {
    return images_;
}



