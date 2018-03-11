//
// Created by bjcheng on 3/10/2018.
//

#ifndef NAIVEBAYES_DATAFILE_HPP
#define NAIVEBAYES_DATAFILE_HPP

#include <vector>
#include <string>
#include "FeatureVector.hpp"

using std::vector;

class DataFile {
public:
    explicit DataFile(std::string fileName);
    void printGivenFeatureVector(int index);
    int getNumberOfImages();
    vector<FeatureVector> getImages();
private:
    vector<FeatureVector> images_;



};

#endif //NAIVEBAYES_DATAFILE_HPP
