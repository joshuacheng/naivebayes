//
// Created by joshua cheng on 3/10/2018.
//

#ifndef NAIVEBAYES_FEATUREVECTOR_HPP
#define NAIVEBAYES_FEATUREVECTOR_HPP
#include <istream>
#include <vector>
#include "catch.hpp"

/*
 * FeatureVector is just a fancy name for a 28x28 image of a number that we will be using.
 */

class FeatureVector {

    static const int DIMENSIONS = 28;

    /* This 1D vector represents a 2D image by
       just placing everything in one row.
       Converting from indices a -> (b, c) is (a / 28, a % 28).
    */
    std::vector<bool> features_;
public:

    FeatureVector()=default;

    friend std::istream & operator>>(std::istream& input_stream, FeatureVector &featureVector);
    friend std::ostream & operator<<(std::ostream& output_stream, const FeatureVector &featureVector);
    std::vector<bool> getFeatureArray() const;


};

#endif //NAIVEBAYES_FEATUREVECTOR_HPP
