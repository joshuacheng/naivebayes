//
// Created by bjcheng on 3/10/2018.
//

#include "Model.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

Model::Model(std::string trainingImageFileName, std::string trainingLabelsFileName) :
                dataFile(trainingImageFileName), probabilities_{0} {

    std::ifstream trainingLabelsFile(trainingLabelsFileName);
    std::string currLine;

    while (trainingLabelsFile) {
        getline(trainingLabelsFile, currLine);

        trueValues_.push_back(currLine);
    }

    // Pop last value because for some reason it was being copied twice.
    trueValues_.pop_back();

    std::vector<double> appearancesOfEachNumber = calculatePercentageOfEachNumber();
    std::vector<FeatureVector> testImages = dataFile.getImages();
    int numberOfImages = static_cast<int>(trueValues_.size());

    // double for loop to iterate through all pixels in probabilities_ array
    for (int i = 0; i < DIMENSIONS; ++i) {
        for (int j = 0; j < DIMENSIONS; ++j) {

            // go through the entire data file for that one pixel
            for (int k = 0; k < numberOfImages; ++k) {

                int realValueOfCurrentImage = std::stoi(trueValues_[k]);
                std::vector<bool> currentFeatureArray = testImages[k].getFeatureArray();

                // If the kth image's (i, j) pixel is black, increment counter in probabilities_
                // The index calculation is to convert (i, j) into 1 dimension.
                if (currentFeatureArray[i*28 + j]) {

                    // This represents P(pixel is black/white and class)
                    probabilities_[i][j][realValueOfCurrentImage][1] += 1.0;
                }
            }

            if (i == 27 && j == 17) {
                std::cout << probabilities_[i][j][1][0] << " " << probabilities_[i][j][1][1];
            }

            for (int number = 0; number < 10; ++number) {

                // Turn number of appearances into Laplace smoothed probability.
                probabilities_[i][j][number][1] = (probabilities_[i][j][number][1] + LAPLACEK) /
                                                    (appearancesOfEachNumber[number] + (2 * LAPLACEK));

                // (i,j,l,0) is just the complement to (i,j,l,1). Since there are
                // only two outcomes, one is just 1 minus the other.
                probabilities_[i][j][number][0] = 1.0 - probabilities_[i][j][number][1];
            }

            std::cout << "Pixel (" << i << ", " << j << ") done" << std::endl;
        }
    }

}

// Creates a new Model object with an existing model file.
Model::Model(std::string existingModelFileName) : dataFile(), probabilities_{0} {
    std::ifstream input_stream(existingModelFileName);

    double probability;
    for (int i = 0; i < Model::DIMENSIONS; ++i) {
        for (int j = 0; j < Model::DIMENSIONS; ++j) {
            for (int k = 0; k < 10; ++k) {
                input_stream >> probability;
                probabilities_[i][j][k][0] = probability;
                input_stream >> probability;
                probabilities_[i][j][k][1] = probability;
            }
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

    return percentages;

}

void Model::testPrint() const {
    for (int i = 0; i < 10; ++i) {
        std::cout << probabilities_[15][15][i][1] << std::endl;
    }
}

// Read a model from a file.
std::ifstream& operator>>(std::ifstream& input_stream, Model &model) {
    double probability;
    for (int i = 0; i < Model::DIMENSIONS; ++i) {
        for (int j = 0; j < Model::DIMENSIONS; ++j) {
            for (int k = 0; k < 10; ++k) {
                input_stream >> probability;
                model.probabilities_[i][j][k][0] = probability;
                input_stream >> probability;
                model.probabilities_[i][j][k][1] = probability;
            }
        }
    }

    return input_stream;
}

// Write a model to a file
std::ofstream& operator<<(std::ofstream& output_stream, const Model &model) {
    for (int i = 0; i < Model::DIMENSIONS; ++i) {
        for (int j = 0; j < Model::DIMENSIONS; ++j) {
            for (int k = 0; k < 10; ++k) {
                output_stream << model.probabilities_[i][j][k][0] << " " << model.probabilities_[i][j][k][1] << " ";
            }
            if (i != Model::DIMENSIONS - 1 || j != Model::DIMENSIONS - 1) {
                output_stream << std::endl;
            }
        }
    }

    output_stream.close();

    return output_stream;
}


