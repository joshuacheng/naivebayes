//
// Created by bjcheng on 3/10/2018.
//

#include "Model.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>

Model::Model(std::string trainingImageFileName, std::string trainingLabelsFileName) :
                dataFile(trainingImageFileName), probabilities_{0}, appearancesOfEachNumber(10) {

    std::ifstream trainingLabelsFile(trainingLabelsFileName);
    std::string currLine;

    while (trainingLabelsFile) {
        getline(trainingLabelsFile, currLine);

        trueValues_.push_back(currLine);
    }

    // Pop last value because for some reason it was being copied twice.
    trueValues_.pop_back();

    fillOutProbabilities();

}

// Creates a new Model object with an existing model file.
Model::Model(std::string existingModelFileName) : dataFile(), probabilities_{0}, appearancesOfEachNumber(10) {
    std::ifstream input_stream(existingModelFileName);

    input_stream >> *this;
}

int Model::classifyImage(const FeatureVector vector) {
    std::vector<bool> image = vector.getFeatureArray();
    std::vector<double> priors(10);

    // Check every possible class this number could be.
    for (int num = 0; num < 10; ++num) {

        // Probability of the class in the entire file.
        priors[num] += (log(appearancesOfEachNumber[num]));

        // Iterate from pixel (1,1) to (28,28) for this specific number class.
        for (int i = 0; i < DIMENSIONS; ++i) {
            for (int j = 0; j < DIMENSIONS; ++j) {
                if (image[i*28 + j]) {
                    priors[num] += log(probabilities_[i][j][num][1]);
                } else {
                    priors[num] += log(probabilities_[i][j][num][0]);
                }
            }
        }
    }

//    for (int k = 0; k < 10; ++k) {
//        std::cout << appearancesOfEachNumber[k] << std::endl;
//    }

    int closestMatch = std::distance(priors.begin(), std::max_element(priors.begin(), priors.end()));

    return closestMatch;
}


/** This method fills out the 4D probabilities array by using all
 *  the member objects which have been instantiated at this point.
 *
 */
void Model::fillOutProbabilities() {
    calcAppearancesOfEachNumber(false);
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



DataFile Model::getDataFile() {
    return dataFile;
}

void Model::printOutAppearances() {
    for (int i = 0; i < 10; ++i) {
        std::cout << appearancesOfEachNumber[i] << std::endl;
    }
}

/** Calculates how many times each number appears in
 *
 * @param probabilitiesInstead
 * @return
 */
std::vector<double> Model::calcAppearancesOfEachNumber(bool probabilitiesInstead) {
    for (int l = 0; l < trueValues_.size(); ++l) {
        int index = std::stoi(trueValues_[l]);
        appearancesOfEachNumber[index] += 1.0;
    }

    if (probabilitiesInstead) {
        for (int i = 0; i < 10; ++i) {
            appearancesOfEachNumber[i] /= 5000.0;
        }
    }

    return appearancesOfEachNumber;

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


    double percentageOfAppearance;
    for (int l = 0; l < 10; ++l) {
        input_stream >> percentageOfAppearance;
        model.appearancesOfEachNumber[l] = percentageOfAppearance;
    }

    return input_stream;
}

/** Writes a model to a file by printing out all
 *  Only call this method if the model was initialized by taking
 *  training images and labels, otherwise its true values size is 0.
 *
 * @param output_stream file to write to
 * @param model         model to write from
 * @return              the file stream
 */
std::ofstream& operator<<(std::ofstream& output_stream, Model &model) {
    if (!output_stream) {
        return output_stream;
    }

    if (model.trueValues_.size() == 0) {
        return output_stream;
    }

    for (int i = 0; i < Model::DIMENSIONS; ++i) {
        for (int j = 0; j < Model::DIMENSIONS; ++j) {
            for (int k = 0; k < 10; ++k) {
                output_stream << model.probabilities_[i][j][k][0] << " " << model.probabilities_[i][j][k][1] << " ";
            }
            output_stream << std::endl;
        }
    }

    std::vector<double> percentageOfEachNumber = model.appearancesOfEachNumber;

    for (int l = 0; l < 10; ++l) {
        output_stream << percentageOfEachNumber[l] << " ";
    }



    output_stream.close();

    return output_stream;
}


