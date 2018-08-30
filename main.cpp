//
// Created by bjcheng on 3/9/2018.
//
#include <iostream>
#include <fstream>
#include "FeatureVector.hpp"
#include "DataFile.hpp"
#include "Model.hpp"
#include <cmath>
#include <iomanip>

using std::string;
using std::vector;
using std::cout;

void classifyFileAndReportMatrix(Model model);
void printConfusionMatrix(vector<vector<double>> confusionMatrix);

//TODO: be able to show the user some of the guesses that the model made.

int main() {
    std::cout << "Hello World" << std::endl;

    std::cout << "To start, enter one of the two: \n" <<
                 "'train': Trains a model based on the images in data/trainingimages and" <<
                 " labels in data/traininglabels. \n" <<
                 "'load' : Loads the model in currentModel.\n" <<
                    std::endl;

    string input;
    do {
        getline(std::cin, input);
    } while (input != "train" && input != "load");


    if (input == "train") {
        Model model("../data/trainingimages", "../data/traininglabels");
        std::cout << "Model trained. Now you can:\n" <<
                  "'write' : Writes this model to the currentModel file.\n" <<
                  "'classify' : Classifies the images in data/testimages and reports confusion matrix.\n" <<
                  "'exit'     : Exit." << std::endl;
        while (true) {
            getline(std::cin, input);
            if (input == "write") {
                std::ofstream modelFile("../data/currentModel");
                modelFile << model;
                std::cout << "Model written to file." << std::endl;
            } else if (input == "classify") {
                classifyFileAndReportMatrix(model);
            } else if (input == "exit") {
                return 0;
            } else {
                std::cout << "Command not understood." << std::endl;
            }
        }
    } else {
        Model model("../data/currentModel");
        std::cout << "Model pulled from file. Now you can:\n" <<
                     "'classify' : Classifies the images in data/testimages and reports confusion matrix.\n" <<
                     "'exit'     : Exit." << std::endl;
        while (true) {
             getline(std::cin, input);
             if (input == "classify") {
                 classifyFileAndReportMatrix(model);
             } else if (input == "exit") {
                 return 0;
             } else {
                 std::cout << "Command not understood." << std::endl;
             }
        }

    }

}

void classifyFileAndReportMatrix(Model model) {
    vector<vector<double>> matrix = model.classifyFile("../data/testimages", "../data/testlabels");
    printConfusionMatrix(matrix);
}

void printConfusionMatrix(vector<vector<double>> confusionMatrix) {
    std::cout << std::left;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << std::setw(4) << confusionMatrix[i][j] << " ";
        }
        std::cout << std::endl << std::endl;
    }
}

