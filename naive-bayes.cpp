//
// Created by bjcheng on 3/9/2018.
//
#include <iostream>
#include <fstream>
#include "FeatureVector.hpp"
#include "DataFile.hpp"
#include "TrainingData.hpp"

using std::string;

int main() {
//    std::ifstream file("digitdata/trainingimages");
    DataFile dataFile("digitdata/trainingimages");
    dataFile.printGivenFeatureVector(4999);
//    std::cout << dataFile.getSize() << std::endl;

    TrainingData trainingData("digitdata/trainingimages", "digitdata/traininglabels");




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
