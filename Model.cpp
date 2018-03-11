//
// Created by bjcheng on 3/10/2018.
//

#include "Model.hpp"
#include <fstream>
#include <iostream>

Model::Model(std::string trainingImageFileName, std::string trainingLabelsFileName) :
                dataFile(trainingImageFileName) {

    std::ifstream trainingLabelsFile(trainingLabelsFileName);
    std::string currLine;

    while (trainingLabelsFile) {
        getline(trainingLabelsFile, currLine);

        trueValues_.push_back(currLine);
    }

    // Pop last value because for some reason it was being copied twice.
    trueValues_.pop_back();

    // CALCULATING PROBABILITIES BEGINS HERE

    std::vector<double> appearancesOfEachNumber = calculatePercentageOfEachNumber();
    std::vector<FeatureVector> testImages = dataFile.getImages();
    int numberOfImages = static_cast<int>(testImages.size());

    // double for loop to iterate through all pixels in probabilities_ array
    for (int i = 0; i < DIMENSIONS; ++i) {
        for (int j = 0; j < DIMENSIONS; ++j) {

            // go through the entire data file for that one pixel
            for (int k = 0; k < numberOfImages; ++k) {
                int realValueOfCurrentImage = std::stoi(trueValues_[k]);
                std::vector<bool> currentFeature1Array = testImages[k].getFeatureArray();

                // If the kth image's (i, j) pixel is black, increment counter in probabilities_
                if (currentFeature1Array[i*28 + j]) {
                    probabilities_[i][j][realValueOfCurrentImage][1]++;
                }

            }

            for (int l = 0; l < 10; ++l) {

                // Divide probability by appearances of each number.
                probabilities_[i][j][l][1] /= appearancesOfEachNumber[l];

                // (i,j,l,0) is just the complement to (i,j,l,1). Since there are
                // only two outcomes, one is just 1 minus the other.
                probabilities_[i][j][l][0] = 1 - probabilities_[i][j][l][1];
            }

            std::cout << "Pixel (" << i << ", " << j << ") done" << std::endl;
        }
    }

}

DataFile Model::getDataFile() {
    return dataFile;
}

std::vector<double> Model::calculatePercentageOfEachNumber() {
    std::vector<double> percentages(10);
    for (int l = 0; l < trueValues_.size(); ++l) {
        int index = std::stoi(trueValues_[l]);
        percentages[index]++;
    }

//    for (double &m : percentages) {
//        m /= 5000.0;
//    }

    return percentages;

}

