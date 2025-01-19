//
// Created by Maxwell Kozlov on 1/19/25.
//


#include <boost/test/unit_test.hpp>
#include "../../engine/include/sphericalgeometry.h"
#define BOOST_TEST_DYN_LINK


BOOST_AUTO_TEST_SUITE(SphericalGeometryTests);

BOOST_AUTO_TEST_CASE(SphericalTriangleAreaTest) {
    float expected = 0.110997;
    float epsilon = 1e-3;
    Vector3f a = Vector3f(1,2,3);
    Vector3f b = Vector3f(2,5,6);
    Vector3f c = Vector3f(3,2,4);
    float area = SphericalTriangleArea(a,b,c);
    std::cout << area << std::endl;
    BOOST_CHECK(std::fabs(area - expected) < epsilon);
}

BOOST_AUTO_TEST_CASE(SphericalQuadAngleTest) {
    Vector3f a = Vector3f(1,0,0);
    Vector3f b = Vector3f(0,1,0);
    Vector3f c = Vector3f(-1,0,0);
    Vector3f d = Vector3f(0,-1,0);
    float area = SphericalQuadArea(a,b,c,d);
    std::cout << area << std::endl;
}



BOOST_AUTO_TEST_SUITE_END()




