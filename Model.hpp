//
// Created by bjcheng on 3/10/2018.
//

#ifndef NAIVEBAYES_MODEL_HPP
#define NAIVEBAYES_MODEL_HPP

#include <string>
#include <istream>
#include <fstream>
#include "DataFile.hpp"

class Model {
public:
    Model()=default;
    explicit Model(std::string trainingImageFileName, std::string trainingImageLabelsName);
    explicit Model(std::string existingModelFileName);
    std::vector<std::vector<double>> classifyFile(std::string testImagesFileName, std::string testLabelsFileName);
    int classifyImage(FeatureVector image);
    void printPrototypicalExtrema(std::string testImagesFileName, std::string testLabelsFileName);
    void fillOutProbabilities();
    DataFile getDataFile();
    void printOutAppearances();
    friend std::ifstream & operator>>(std::ifstream& input_stream, Model &model);
    friend std::ofstream & operator<<(std::ofstream& output_stream, Model &model);


private:
    static constexpr double LAPLACEK = 1.0;
    static const int DIMENSIONS = 28;
    double probabilities_[DIMENSIONS][DIMENSIONS][10][2];
    std::vector<double> appearancesOfEachNumber;
    DataFile dataFile;
    std::vector<std::string> trueValues_;
    std::vector<double> calcAppearancesOfEachNumber();

};

#endif //NAIVEBAYES_MODEL_HPP
