//
// Created by joshua cheng on 3/10/2018.
//

#ifndef NAIVEBAYES_FEATUREVECTOR_HPP
#define NAIVEBAYES_FEATUREVECTOR_HPP

#include <istream>

class FeatureVector {
    static const int DIMENSIONS = 29;
    bool features_[DIMENSIONS][DIMENSIONS];

public:

    FeatureVector()=default;


    friend std::istream & operator>>(std::istream& input_stream, FeatureVector &featureVector);
    friend std::ostream & operator<<(std::ostream& output_stream, const FeatureVector &featureVector);

};

#endif //NAIVEBAYES_FEATUREVECTOR_HPP
