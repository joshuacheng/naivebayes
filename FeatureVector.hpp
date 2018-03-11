//
// Created by joshua cheng on 3/10/2018.
//

#ifndef NAIVEBAYES_FEATUREVECTOR_HPP
#define NAIVEBAYES_FEATUREVECTOR_HPP
#include <istream>
#include <vector>

class FeatureVector {

    static const int DIMENSIONS = 28;
    bool features_[DIMENSIONS][DIMENSIONS];
    std::vector<std::vector<bool>> features1_;

public:

    FeatureVector()=default;

    friend std::istream & operator>>(std::istream& input_stream, FeatureVector &featureVector);
    friend std::ostream & operator<<(std::ostream& output_stream, const FeatureVector &featureVector);
    std::vector<std::vector<bool>> getFeatureArray();

};

#endif //NAIVEBAYES_FEATUREVECTOR_HPP
