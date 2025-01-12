//
// Created by Maxwell Kozlov on 1/11/25.
//

#include <boost/test/unit_test.hpp>
#include "../../engine/include/bounds3.h"
#define BOOST_TEST_DYN_LINK


BOOST_AUTO_TEST_SUITE(BoundsTests);

BOOST_AUTO_TEST_CASE(BoundsDefaultConstructor) {
    Bounds3f bounds{};
    BOOST_CHECK(bounds.pMin.x == std::numeric_limits<float>::lowest());
    BOOST_CHECK(bounds.pMax.x == std::numeric_limits<float>::max());
}

BOOST_AUTO_TEST_CASE(BoundsTwoPointConstructor) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(1000.0,1000.0,1000.0);
    Bounds3f bounds = Bounds3f(pMax,pMin);
    BOOST_CHECK(bounds.pMin == pMin);
    BOOST_CHECK(bounds.pMax == pMax);
}

BOOST_AUTO_TEST_CASE(BoundsOnePointConstructor) {
    Point3f p = Point3f(100.0,200.0,300.0);
    Bounds3f bounds = Bounds3f(p);
    BOOST_CHECK(bounds.pMax == p);

}

BOOST_AUTO_TEST_CASE(BoundsIndexOperator) {
    Point3f pMin = Point3f(0,0,0);
    Point3f pMax = Point3f(100,100,100);
    Bounds3f bounds  = Bounds3f(pMin,pMax);
    BOOST_CHECK(bounds[0] == pMin);
    BOOST_CHECK(bounds[1] == pMax);
}

BOOST_AUTO_TEST_CASE(BoundsCorner) {
    Point3f pMin = Point3f(0,0,0);
    Point3f pMax = Point3f(100,100,100);
    Bounds3f bounds  = Bounds3f(pMin,pMax);
    BOOST_CHECK(bounds.Corner(0) == pMin);
    BOOST_CHECK(bounds.Corner(1) == Point3f(100,0,0));
    BOOST_CHECK(bounds.Corner(6) == Point3f(0,100,100));
    BOOST_CHECK(bounds.Corner(7) == pMax);
}

BOOST_AUTO_TEST_CASE(BoundsUnion) {
    Bounds3f bounds = Bounds3f(Point3f(0,0,0),Point3f(100,100,100));
    Point3f p = Point3f(-100.0,250.0,500.0);
    bounds = Bounds3f::Union(bounds,p);
    BOOST_CHECK(bounds[0] == Point3f(-100,0.0,0.0));
    BOOST_CHECK(bounds[1] == Point3f(100.0,250.0,500.0));
}

BOOST_AUTO_TEST_CASE(BoundsUnionNoChange) {
    Bounds3f bounds = Bounds3f(Point3f(0,0,0),Point3f(100,100,100));
    Point3f p = Point3f(50.0,50.0,50.0);
    bounds = Bounds3f::Union(bounds,p);
    BOOST_CHECK(bounds[0] == Point3f(0.0,0.0,0.0));
    BOOST_CHECK(bounds[1] == Point3f(100.0,100.0,100.0));
}

BOOST_AUTO_TEST_CASE(BoundsUnionBounds) {
    Bounds3f bounds = Bounds3f(Point3f(0,0,0),Point3f(100,100,100));
    Bounds3f bounds2 = Bounds3f(Point3f(20,20,20),Point3f(150,150,150));
    Bounds3f boundsUnion = Bounds3f::Union(bounds,bounds2);
    BOOST_CHECK(boundsUnion[0] == Point3f(0,0,0));
    BOOST_CHECK(boundsUnion[1] == Point3f(150,150,150));
}

BOOST_AUTO_TEST_CASE(BoundsIntersection) {
    Bounds3f b1(Point3f(0,0,0),Point3f(4,4,0));
    Bounds3f b2(Point3f(1,-1,0),Point3f(5,3,0));
    Bounds3f intersection = Bounds3f::Intersection(b1,b2);
    BOOST_CHECK(intersection[0] == Point3f(1,0,0));
    BOOST_CHECK(intersection[1] == Point3f(4,3,0));
}

BOOST_AUTO_TEST_CASE(BoundsOverlap) {
    Bounds3f b1(Point3f(0,0,0),Point3f(4,4,0));
    Bounds3f b2(Point3f(1,-1,0),Point3f(5,3,0));
    BOOST_CHECK(Bounds3f::Overlap(b1,b2));
}

BOOST_AUTO_TEST_CASE(BoundsDontOverlap) {
    Bounds3f b1(Point3f(0,0,2),Point3f(4,4,4));
    Bounds3f b2(Point3f(1,-1,0),Point3f(5,3,0));
    BOOST_CHECK(!Bounds3f::Overlap(b1,b2));
}

BOOST_AUTO_TEST_CASE(BoundsDontOverlap2) {
    Bounds3f b1(Point3f(0,0,0),Point3f(4,4,0));
    Bounds3f b2(Point3f(1,6,0),Point3f(5,8,0));
    BOOST_CHECK(!Bounds3f::Overlap(b1,b2));
}
BOOST_AUTO_TEST_SUITE_END()

