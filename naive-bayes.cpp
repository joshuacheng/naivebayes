//
// Created by bjcheng on 3/9/2018.
//
#include <iostream>
#include <fstream>
#include "featurevector.hpp"

using std::string;

int main() {
//    string input;
    std::ifstream file("trainingimages");
    FeatureVector featureVector;


    if (!file) {
        std::cout << "failure" << std::endl;
        return 0;
    }

    file >> featureVector;
    std::cout << featureVector << std::endl;

    file >> featureVector;
    std::cout << featureVector << std::endl;


    //    bool data[29][29];
//    char currentChar;
//
//        for (int i = 0; i < 29; ++i) {
//            for (int j = 0; j < 29; ++j) {
//                file.get(currentChar);
//                data[i][j] = currentChar == '#' || currentChar == '+';
//                if (data[i][j]) {
//                    std::cout << 1;
//                } else {
//                    std::cout << 0;
//                }
//            }
//            std::cout << std::endl;
//        }



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
