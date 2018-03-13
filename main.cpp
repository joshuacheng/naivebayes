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

void printConfusionMatrix(vector<vector<double>> confusionMatrix);


int main() {
    std::ifstream file("digitdata/testimages");
//    std::ofstream modelFile("currentModel");
    FeatureVector featureVector{};

//    Model model1("digitdata/trainingimages", "digitdata/traininglabels");
//    modelFile << model1;
    Model model("currentModel");
//    model.testPrint();

//    for (int i = 0; i < 20; ++i) {
//        file >> featureVector;
//
//        std::cout << featureVector;
//
//        int guess = model.classifyImage(featureVector);
//
//        std::cout << guess << std::endl;
//    }
    vector<vector<double>> matrix = model.classifyFile("digitdata/testimages", "digitdata/testlabels");

    printConfusionMatrix(matrix);


    return 0;
}

void printConfusionMatrix(vector<vector<double>> confusionMatrix) {
    std::cout << std::left;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << std::setw(4) << confusionMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

