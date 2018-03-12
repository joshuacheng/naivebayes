//
// Created by bjcheng on 3/10/2018.
//

#ifndef NAIVEBAYES_MODEL_HPP
#define NAIVEBAYES_MODEL_HPP

#include "TrainingData.hpp"
#include <string>
#include <istream>
#include <fstream>

class Model {
public:
    explicit Model(std::string trainingImageFileName, std::string trainingImageLabelsName);
    explicit Model(std::string existingModelFileName);
    void fillOutProbabilities();
    int classifyFeatureVector(FeatureVector vector);
    DataFile getDataFile();
    void testPrint() const;
    friend std::ifstream & operator>>(std::ifstream& input_stream, Model &model);
    friend std::ofstream & operator<<(std::ofstream& output_stream, const Model &model);


private:
    static constexpr double LAPLACEK = 1.0;
    static const int DIMENSIONS = 28;
    double probabilities_[DIMENSIONS][DIMENSIONS][10][2];
    DataFile dataFile;
    std::vector<std::string> trueValues_;
    std::vector<double> calcAppearancesOfEachNumber();

};

#endif //NAIVEBAYES_MODEL_HPP
