//
// Created by Maxwell Kozlov on 1/6/25.
//
#include <boost/test/unit_test.hpp>
#include "../../engine/include/ray.h"
#define BOOST_TEST_DYN_LINK


BOOST_AUTO_TEST_SUITE(RayTests);

BOOST_AUTO_TEST_CASE(RayConstructor) {
    Ray r(Point3f(0.0,0.0,0.0),Vector3f(2.0,2.0,2.0));
    BOOST_CHECK(r.o == Point3f(0.0,0.0,0.0));
    BOOST_CHECK(r.d == Vector3f(2.0,2.0,2.0));
    BOOST_CHECK(r.time == 0.0f);
}

BOOST_AUTO_TEST_CASE(RayDefaultConstructor) {
    Ray r;
    BOOST_CHECK(r.o == Point3f(0.0,0.0,0.0));
    BOOST_CHECK(r.d == Vector3f(0.0,0.0,0.0));
    BOOST_CHECK(r.time == 0.0f);
}

BOOST_AUTO_TEST_CASE(RayParametric) {
    Ray r(Point3f(0.0,0.0,0.0),Vector3f(2.0,2.0,2.0));
    Point3f p = r(1.0);
    BOOST_CHECK(p == Point3f(2.0,2.0,2.0));
}


BOOST_AUTO_TEST_SUITE_END()
