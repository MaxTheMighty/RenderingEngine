//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/vector3.h"
#include "../../engine/include/normal3.h"


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

BOOST_AUTO_TEST_CASE(Vector3Multiplication) {
    Vector3f vec3f(10,20,30);
    BOOST_CHECK(vec3f*10 == Vector3f(100,200,300));
}

BOOST_AUTO_TEST_CASE(Vector3MultiplicationInplace) {
    Vector3f vec3f(10,20,30);
    vec3f*=10;
    BOOST_CHECK(vec3f == Vector3f(100,200,300));
}

BOOST_AUTO_TEST_CASE(Vector3Division) {
    Vector3f vec3f(10,20,30);
    BOOST_CHECK(vec3f/10 == Vector3f(1,2,3));
}

BOOST_AUTO_TEST_CASE(Vector3DivisionInplace) {
    Vector3f vec3f(10,20,30);
    vec3f/=10;
    BOOST_CHECK(vec3f == Vector3f(1,2,3));
}

BOOST_AUTO_TEST_CASE(PointToVector3) {
    Point3f point(1.1f,2.2f,3.3f);
    Vector3f vec3f(point);
    BOOST_CHECK(vec3f == Vector3f(1.1f,2.2f,3.3f));}

BOOST_AUTO_TEST_CASE(NormalToVector3) {
    Normal3f norm3f(1.1f,2.2f,3.3f);
    Vector3<int> vec3i(norm3f);
    BOOST_CHECK(vec3i == Vector3i(1,2,3));
}

BOOST_AUTO_TEST_CASE(Vector3Length) {
    float epsilon = 0.001;
    Vector3f vec3f(50.0,20.0,30.0);
    float length = Vector3<float>::Length(vec3f);
    BOOST_CHECK(fabs(length-sqrt(3800) <= epsilon));
}

BOOST_AUTO_TEST_CASE(Vector3Normalized) {
    Vector3f vec3f(10,20,30);
    BOOST_CHECK(Vector3f::Normalize(vec3f) == Vector3f(1/sqrt(14),2/sqrt(14),3/sqrt(14)));
}

BOOST_AUTO_TEST_CASE(Vector3Dot) {
    Vector3f vec3fa(10,20,30);
    Vector3f vec3fb(40,50,60);
    float dot = Vector3f::Dot(vec3fa,vec3fb);
    BOOST_CHECK_EQUAL(dot,3200);

}

BOOST_AUTO_TEST_CASE(Vector3Angle) {
    Vector3f vec3fa(1.0f,0.0f,0.0f);
    Vector3f vec3fb(0.0f,1.0f,0.0f);
    float expected = 90;
    float epsilon = 0.0001;
    float angle = Vector3f::CalculateAngleBetween(vec3fa,vec3fb) * (180 / 3.1415926f);
    BOOST_CHECK(std::fabs(expected-angle) <= epsilon);
}

BOOST_AUTO_TEST_CASE(Vector3Angle2) {
    Vector3f vec3fa(0.6,0.8,0);
    Vector3f vec3fb(0,0,1);
    float expected = 90;
    float epsilon = 0.0001;
    float angle = Vector3f::CalculateAngleBetween(vec3fa,vec3fb) * (180 / 3.1415926f);
    // std::cout << angle << std::endl;
    BOOST_CHECK(std::fabs(angle-expected) <= epsilon);
}

BOOST_AUTO_TEST_CASE(Vector3AbsDot) {
    Vector3f vec3fa(3,-4,0);
    Vector3f vec3fb(-1,2,0);
    float absDot = Vector3f::AbsDot(vec3fa,vec3fb);
    BOOST_CHECK_EQUAL(absDot,11);
}

// BOOST_AUTO_TEST_CASE(Vector3GramSchmidt) {
//     Vector3f vec3fa(3,4,0);
//     Vector3f vec3fb(0,0,1);
//     Vector3f vec3fc = Vector3f::GramSchmidt(vec3fa,vec3fb);
//     Vector3f vec3fexpected = Vector3f(0,0,1);
//     BOOST_CHECK(vec3fc == vec3fexpected);
//     std::cout << vec3fc << std::endl;
// }


BOOST_AUTO_TEST_CASE(Vector3CrossProduct) {
    Vector3f v = Vector3f(1,2,3);
    Vector3f w = Vector3f(4,5,6);
    Vector3f expected = Vector3f(-3,6,-3);
    Vector3f actual = Vector3f::CrossProduct(v,w);
    BOOST_CHECK(expected == actual);

}

BOOST_AUTO_TEST_SUITE_END()



