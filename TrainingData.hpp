//
// Created by bjcheng on 3/10/2018.
//

#ifndef NAIVEBAYES_TRAININGDATA_HPP
#define NAIVEBAYES_TRAININGDATA_HPP

#include <vector>
#include <istream>
#include <string>
#include "FeatureVector.hpp"
#include "DataFile.hpp"

using std::vector;

class TrainingData {
private:
    DataFile images_;
    vector<int> trueValues_;

public:
    explicit TrainingData(std::string trainingImagesFileName, std::string trainingLabelsFileName);

};


#endif //NAIVEBAYES_TRAININGDATA_HPP
