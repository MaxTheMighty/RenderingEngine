//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_MODULE EngineTests
#include <boost/test/unit_test.hpp>
#include <iostream>

// Global setup fixture
struct GlobalTestFixture {
    GlobalTestFixture() {
        std::cout << "Starting test suite..." << std::endl;
        // Global initialization code
    }

    ~GlobalTestFixture() {
        std::cout << "Cleaning up test suite..." << std::endl;
        // Global cleanup code
    }
};


// Register global fixture
BOOST_GLOBAL_FIXTURE(GlobalTestFixture);

//
