//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/vector3.h"
#include "../../engine/include/point3.h"
#pragma once

BOOST_AUTO_TEST_SUITE(PointTests);

BOOST_AUTO_TEST_CASE(Point3DefaultConstructor) {
    Point3<float> p3f;
    BOOST_CHECK_EQUAL(p3f.x,0.0f);
    BOOST_CHECK_EQUAL(p3f.y,0.0f);
    BOOST_CHECK_EQUAL(p3f.z,0.0f);
};

BOOST_AUTO_TEST_CASE(Point3Constructor) {
    Point3<float> p3f(101.1,202.2,303.3);
    BOOST_CHECK_EQUAL(p3f.x,101.1f);
    BOOST_CHECK_EQUAL(p3f.y,202.2f);
    BOOST_CHECK_EQUAL(p3f.z,303.3f);
};





BOOST_AUTO_TEST_SUITE_END()




