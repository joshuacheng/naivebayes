//
// Created by bjcheng on 3/9/2018.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FeatureVector.cpp"
#include "DataFile.cpp"
#include "Model.cpp"

TEST_CASE("Test FeatureVector Size") {
    // FeatureVector size should always be 28x28, or 784 after it reads from a file.
    const int EXPECTED_SIZE = 784;
    std::ifstream fileToRead("digitdata/testimages");
    FeatureVector image{};

    for (int i = 0; i < 20; ++i) {
        fileToRead >> image;

        REQUIRE(image.getFeatureArray().size() == EXPECTED_SIZE);
    }

}

TEST_CASE("Test correct number of training images") {
    const int EXPECTED_NUM_OF_IMAGES = 5000;

    DataFile imageFile("digitdata/trainingimages");

    REQUIRE(imageFile.getNumberOfImages() == EXPECTED_NUM_OF_IMAGES);
}



