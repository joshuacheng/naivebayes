//
// Created by bjcheng on 3/10/2018.
//

#include <fstream>
#include <iostream>
#include <regex>
#include "TrainingData.hpp"


/** Initializes a training data object, which contains all the training images
 *  and their corresponding actual numbers.
 *
 * @param trainingImagesFileName    file path of training images
 * @param trainingLabelsFileName    file path of training labels
 */
TrainingData::TrainingData(std::string trainingImagesFileName, std::string trainingLabelsFileName) :
                                images_(trainingImagesFileName) {

    std::ifstream trainingLabelsFile(trainingLabelsFileName);
    std::string currLine;

    std::cout<< "initial size: " << trueValues_.size() << std::endl;

    while (trainingLabelsFile) {
        getline(trainingLabelsFile, currLine);

        trueValues_.push_back(currLine);
    }

    // Pop last value because for some reason it was being copied twice.
    trueValues_.pop_back();

}

