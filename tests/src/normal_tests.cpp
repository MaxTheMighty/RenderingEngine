//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/normal3.h"
#pragma once

BOOST_AUTO_TEST_SUITE(NormalTests);

BOOST_AUTO_TEST_CASE(Normal3DefaultConstructor) {
    Normal3<float> norm3;
    BOOST_CHECK_EQUAL(norm3.x,0.0f);
    BOOST_CHECK_EQUAL(norm3.y,0.0f);
    BOOST_CHECK_EQUAL(norm3.z,0.0f);
};

BOOST_AUTO_TEST_CASE(Normal3Constructor) {
    Normal3<float> norm3(1.1f,2.2f,3.3f);
    BOOST_CHECK_EQUAL(norm3.x,1.1f);
    BOOST_CHECK_EQUAL(norm3.y,2.2f);
    BOOST_CHECK_EQUAL(norm3.z,3.3f);
};



BOOST_AUTO_TEST_SUITE_END()




