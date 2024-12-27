//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/vector3.h"
#include "../../engine/include/normal3.h"
#pragma once

BOOST_AUTO_TEST_SUITE(VectorTests);

BOOST_AUTO_TEST_CASE(Vector3DefaultConstructor) {
    Vector3<float> vec3;
    BOOST_CHECK_EQUAL(vec3.x, 0);
    BOOST_CHECK_EQUAL(vec3.y, 0);
    BOOST_CHECK_EQUAL(vec3.z, 0);

};

BOOST_AUTO_TEST_CASE(Vector3Constructor) {
    Vector3<float> vec3f(1.1f,1.2f,1.3f);
    BOOST_CHECK_EQUAL(vec3f.x,1.1f);
    BOOST_CHECK_EQUAL(vec3f.y,1.2f);
    BOOST_CHECK_EQUAL(vec3f.z,1.3f);

    Vector3<int> vec3i(1,2,3);
    BOOST_CHECK_EQUAL(vec3i.x,1);
    BOOST_CHECK_EQUAL(vec3i.y,2);
    BOOST_CHECK_EQUAL(vec3i.z,3);

}

BOOST_AUTO_TEST_CASE(Vector3ConvertConstructor) {
    Vector3<float> vec3f(1.1f,1.2f,1.3f);
    Vector3<int> vec3i(vec3f);
    BOOST_CHECK(vec3i == Vector3i(1,1,1));

}

BOOST_AUTO_TEST_CASE(Vector3Comparison) {
    Vector3f vec3f(1.0f,2.0f,3.0f);
    Vector3f vec3f2(1.0f,2.0f,3.0f);
    Vector3f vec3f3(1.1f,2.0f,3.0f);
    BOOST_CHECK(vec3f==vec3f2);
    BOOST_CHECK(vec3f3!=vec3f);
}

BOOST_AUTO_TEST_CASE(Vector3Addition) {
    Vector3f vec3i(1,2,2);
    Vector3f vec3f2(1.5f,1.0f,0.5f);
    Vector3f vec3f3 = vec3i + vec3f2;
    BOOST_CHECK(vec3f3 == Vector3f(2.5f,3.0f,2.5f));
}

BOOST_AUTO_TEST_CASE(Vector3AdditionInplace) {
    Vector3f vec3f(1.0,2.0,3.0);
    Vector3f vec3i(1,1,1);
    vec3f+=vec3i;
    BOOST_CHECK(vec3f == Vector3f(2.0f,3.0f,4.0f));
}

BOOST_AUTO_TEST_CASE(Vector3Subtraction) {
    Vector3f vec3i(10,20,20);
    Vector3f vec3f2(1.5f,1.0f,0.5f);
    Vector3f vec3f3 = vec3i - vec3f2;
    BOOST_CHECK(vec3f3 == Vector3f(8.5f,19.0f,19.5f));
}

BOOST_AUTO_TEST_CASE(PointToVector3) {
    Point3f point(1.1f,2.2f,3.3f);
    Vector3f vec3f(point);
    BOOST_CHECK(vec3f == Vector3f(1.1f,2.2f,3.3f));
}

BOOST_AUTO_TEST_CASE(NormalToVector3) {
    Normal3f norm3f(1.1f,2.2f,3.3f);
    Vector3<int> vec3i(norm3f);
    BOOST_CHECK(vec3i == Vector3i(1,2,3));
}

BOOST_AUTO_TEST_SUITE_END()



