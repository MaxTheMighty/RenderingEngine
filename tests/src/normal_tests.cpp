//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/normal3.h"
#include "../../engine/include/vector3.h"


BOOST_AUTO_TEST_SUITE(NormalTests);

BOOST_AUTO_TEST_CASE(Normal3DefaultConstructor) {
    Normal3<float> norm3;
    BOOST_CHECK_EQUAL(norm3.x,0.0f);
    BOOST_CHECK_EQUAL(norm3.y,0.0f);
    BOOST_CHECK_EQUAL(norm3.z,0.0f);
}

BOOST_AUTO_TEST_CASE(Normal3Constructor) {
    Normal3<float> norm3(1.1f,2.2f,3.3f);
    BOOST_CHECK_EQUAL(norm3.x,1.1f);
    BOOST_CHECK_EQUAL(norm3.y,2.2f);
    BOOST_CHECK_EQUAL(norm3.z,3.3f);
}

BOOST_AUTO_TEST_CASE(Normal3FromVector3) {
    Normal3f norm3(Vector3i(1,2,3));
    BOOST_CHECK_EQUAL(norm3.x, 1.0f);
    BOOST_CHECK_EQUAL(norm3.y, 2.0f);
    BOOST_CHECK_EQUAL(norm3.z, 3.0f);


}

BOOST_AUTO_TEST_CASE(Normal3DotWithVector3) {
    Normal3f norm3fa(10,20,30);
    Vector3f vec3fb(40,50,60);
    float dot = Normal3<float>::Dot(norm3fa,vec3fb);
    BOOST_CHECK_EQUAL(dot,3200);
}

BOOST_AUTO_TEST_CASE(Normal3DotWithNormal3) {
    Normal3f norm3fa(10,20,30);
    Normal3f norm3fb(40,50,60);
    float dot = Normal3<float>::Dot(norm3fa,norm3fb);
    BOOST_CHECK_EQUAL(dot,3200);
}

BOOST_AUTO_TEST_CASE(Normal3AbsDotWithVector3) {
    Normal3f norm3fa(10,20,30);
    Vector3f vec3fb(-40,-50,-60);
    float dot = Normal3<float>::AbsDot(norm3fa,vec3fb);
    BOOST_CHECK_EQUAL(dot,3200);
}

BOOST_AUTO_TEST_CASE(Normal3AbsDotWithNormal3) {
    Normal3f norm3fa(10,20,30);
    Normal3f norm3fb(-40,-50,-60);
    float dot = Normal3<float>::AbsDot(norm3fa,norm3fb);
    BOOST_CHECK_EQUAL(dot,3200);
}

BOOST_AUTO_TEST_CASE(Normal3Length) {
    float epsilon = 0.001;
    Normal3f norm3f(50.0,20.0,30.0);
    float length = Normal3f::Length(norm3f);
    BOOST_CHECK(fabs(length-sqrt(3800) <= epsilon));
}

BOOST_AUTO_TEST_CASE(Normal3Normalized) {
    Normal3f norm3f(10,20,30);
    BOOST_CHECK(Normal3f::Normalize(norm3f) == Normal3f(1/sqrt(14),2/sqrt(14),3/sqrt(14)));
}

BOOST_AUTO_TEST_CASE(Normal3AngleBetween) {
    Normal3f norm3fa(1.0f,0.0f,0.0f);
    Normal3f norm3fb(0.0f,1.0f,0.0f);
    float expected = 90;
    float epsilon = 0.0001;
    float angle = Normal3f::CalculateAngleBetween(norm3fa,norm3fb) * (180 / 3.1415926f);
    BOOST_CHECK(std::fabs(expected-angle) <= epsilon);
}

BOOST_AUTO_TEST_CASE(Normal3FaceForward) {
    Normal3f norm3fa(1.0,1.0,1.0);
    Vector3f vec3fb(-1.0,-1.0,-1.0);
    Normal3f facingNorm3fb = Normal3f::FaceForward(norm3fa,vec3fb);
    BOOST_CHECK(facingNorm3fb == -norm3fa);
}

BOOST_AUTO_TEST_CASE(Normal3FaceForward2) {
    Normal3f norm3fa(1.0,1.0,1.0);
    Vector3f vec3fb(5.0,51.0,0.0001);
    Normal3f facingNorm3fb = Normal3f::FaceForward(norm3fa,vec3fb);
    BOOST_CHECK(facingNorm3fb == norm3fa);
}


BOOST_AUTO_TEST_SUITE_END()




