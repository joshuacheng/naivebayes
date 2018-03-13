//
// Created by bjcheng on 3/9/2018.
//
#include <iostream>
#include <fstream>
#include "FeatureVector.hpp"
#include "DataFile.hpp"
#include "TrainingData.hpp"
#include "Model.hpp"
#include <cmath>

using std::string;

int main() {
    std::ifstream file("digitdata/testimages");
//    std::ofstream modelFile("currentModel");
    FeatureVector featureVector;

//    Model model1("digitdata/trainingimages", "digitdata/traininglabels");
//    modelFile << model1;
    Model model("currentModel");
//    model.testPrint();

    for (int i = 0; i < 20; ++i) {
        file >> featureVector;

        std::cout << featureVector;

        int guess = model.classifyImage(featureVector);

        std::cout << guess << std::endl;
    }

//    std::cout << log(0.00204082) << std::endl;



//    }
//    std::cout << "HELLOW WORLD" << std::endl;



    return 0;
}

void writeToFile() {
    string input;

    std::ofstream file("thing");

    while (std::cin >> input) {
        file << input << std::endl;
    }

    file.close();
}
