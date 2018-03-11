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
    DataFile getDataFile();
    void testPrint() const;
    friend std::istream & operator>>(std::istream& input_stream, Model &model);
    friend std::ostream & operator<<(std::ostream& output_stream, const Model &model);


private:
    static constexpr double LAPLACEK = 1.0;
    static const int DIMENSIONS = 28;
    double probabilities_[DIMENSIONS][DIMENSIONS][10][2];
    DataFile dataFile;
    std::vector<std::string> trueValues_;
    std::vector<double> calculatePercentageOfEachNumber();

};

#endif //NAIVEBAYES_MODEL_HPP
