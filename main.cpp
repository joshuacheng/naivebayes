//
// Created by bjcheng on 3/9/2018.
//
#include <iostream>
#include <fstream>
#include "FeatureVector.hpp"
#include "DataFile.hpp"
#include "TrainingData.hpp"
#include "Model.hpp"

using std::string;

int main() {
//    std::ifstream file("digitdata/trainingimages");
//    DataFile dataFile("digitdata/trainingimages");
//    dataFile.printGivenFeatureVector(4999);
//    std::cout << dataFile.getSize() << std::endl;

    Model model("digitdata/trainingimages", "digitdata/traininglabels");

    DataFile file = model.getDataFile();

    file.printGivenFeatureVector(5);


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
