//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/vector3.h"
#include "../../engine/include/point3.h"


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

BOOST_AUTO_TEST_CASE(Point3FromPoint3) {
    Point3i p3i = Point3i(Point3f(1.2f,2.6f,5.0f));
    BOOST_CHECK_EQUAL(p3i.x,1);
    BOOST_CHECK_EQUAL(p3i.y,2);
    BOOST_CHECK_EQUAL(p3i.z,5);
}

BOOST_AUTO_TEST_CASE(Vector3ToPoint) {
    Vector3f v3f(1.1,2.2,3.3);
    Point3f p3f(v3f);
    BOOST_CHECK(p3f == Point3f(1.1,2.2,3.3));
}

BOOST_AUTO_TEST_CASE(Point3Addition) {
    Point3f p3f(1.1,2.2,3.3);
    Point3f p3f2(500.0,0.5,100.0);
    Point3f p3f3 = p3f + p3f2;
    BOOST_CHECK(p3f3 == Point3f(501.1,2.7,103.3));
}

BOOST_AUTO_TEST_CASE(Point3InplaceAddition) {
    Point3f p3f(1.0,2.5,3.9);
    Vector3i v3i(1,2,3);
    p3f+=v3i;
    BOOST_CHECK(p3f==Point3f(2.0,4.5,6.9));
}

BOOST_AUTO_TEST_CASE(Point3Subtraction) {
    Vector3f v3f = Point3f(5.0,4.0,3.0) - Point3f(1.0,2.0,3.0);
    BOOST_CHECK(v3f == Vector3f(4.0,2.0,0.0));
}

BOOST_AUTO_TEST_CASE(Point3Distance) {
    Point3f p3fa(4.0,3.0,7.0);
    Point3f p3fb(9.0,100.0,200.0);
    float distance = Point3f::Distance(p3fa,p3fb);
    float expected = 216.06249096037;
    float epsilon = 0.0001;
    BOOST_CHECK(fabs(distance-expected) <= epsilon);

}

BOOST_AUTO_TEST_CASE(Point3DistanceSquared) {
    Point3f p3fa(4.0,3.0,7.0);
    Point3f p3fb(9.0,100.0,200.0);
    float distanceSquared = Point3f::DistanceSquared(p3fa,p3fb);
    float expected = 46682.9995850001;
    float epsilon = 0.00001;
    BOOST_CHECK(fabs(distanceSquared-expected) <= epsilon);
}





BOOST_AUTO_TEST_SUITE_END()




