//
// Created by Maxwell Kozlov on 1/11/25.
//

#include <boost/test/unit_test.hpp>
#include "../../engine/include/bounds3.h"
#include "../../engine/include/vector3.h"

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

BOOST_AUTO_TEST_CASE(BoundsInside) {
    Bounds3f bounds = Bounds3f(Point3f(0,0,0),Point3f(100,100,100));
    Point3f p = Point3f(50,50,50);
    Point3f p2 = Point3f(1,1,1);
    Point3f p3 = Point3f(99,1,20);
    BOOST_CHECK(Bounds3f::Inside(bounds,p));
    BOOST_CHECK(Bounds3f::Inside(bounds,p2));
    BOOST_CHECK(Bounds3f::Inside(bounds,p3));
}

BOOST_AUTO_TEST_CASE(BoundsNotInside) {
    Bounds3f bounds = Bounds3f(Point3f(0,0,0),Point3f(100,100,100));
    Point3f p = Point3f(101,50,50);
    Point3f p2 = Point3f(1,101,101);
    Point3f p3 = Point3f(-1,10,30);
    Point3f p4 = Point3f(-1,-1,-1);
    BOOST_CHECK(!Bounds3f::Inside(bounds,p));
    BOOST_CHECK(!Bounds3f::Inside(bounds,p2));
    BOOST_CHECK(!Bounds3f::Inside(bounds,p3));
    BOOST_CHECK(!Bounds3f::Inside(bounds,p4));
}

BOOST_AUTO_TEST_CASE(BoundsInsideExclusive) {
    Bounds3f bounds = Bounds3f(Point3f(0,0,0),Point3f(100.0,100.0,100.0));
    Point3f p = Point3f(100.0,0.0,0.0);
    Point3f p2 = Point3f(100.0,100.0,100.0);
    BOOST_CHECK(!Bounds3f::InsideExclusive(bounds,p));
    BOOST_CHECK(!Bounds3f::InsideExclusive(bounds,p2));
}

BOOST_AUTO_TEST_CASE(BoundsPointDistance) {
    float epsilon = 0.0001;
    auto expected = 1.0f;
    Point3f pMin = Point3f(-1.0,-1.0,-1.0);
    Point3f pMax = Point3f(1.0,1.0,1.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Point3f p = Point3f(2.0,0.0,-1.0);
    auto distance = Bounds3f::Distance(p,bounds);
    BOOST_CHECK(fabs(distance-expected) <= epsilon);
}

BOOST_AUTO_TEST_CASE(BoundsExpand) {
    Point3f pMin = Point3f(-1.0,-1.0,-1.0);
    Point3f pMax = Point3f(1.0,1.0,1.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Bounds3f boundsExpanded = Bounds3f::Expand(bounds,1.0f);
    BOOST_CHECK(boundsExpanded.pMin == Point3f(-2,-2,-2));
    BOOST_CHECK(boundsExpanded.pMax == Point3f(2,2,2));
}

BOOST_AUTO_TEST_CASE(BoundsDiagonal) {
    Point3f pMin = Point3f(-1.0,-1.0,-1.0);
    Point3f pMax = Point3f(1.0,1.0,1.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Vector3f diagonal = bounds.Diagonal();
    BOOST_CHECK(diagonal == Vector3f(2.0,2.0,2.0));
}

BOOST_AUTO_TEST_CASE(BoundsSurfaceArea) {
    float expected = 150.0;
    float epsilon = 0.0001;
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(5.0,5.0,5.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    float surfaceArea = bounds.SurfaceArea();
    BOOST_CHECK(fabs(surfaceArea-expected) <= epsilon);
}

BOOST_AUTO_TEST_CASE(BoundsVolume) {
    float expected = 125.0;
    float epsilon = 0.0001;
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(5.0,5.0,5.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    float volume = bounds.Volume();
    BOOST_CHECK(fabs(volume-expected) <= epsilon);
}

BOOST_AUTO_TEST_CASE(BoundsMaxDimension1) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(5.0,4.0,3.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    BOOST_CHECK_EQUAL(bounds.MaxDimension(),0);
}

BOOST_AUTO_TEST_CASE(BoundsMaxDimension2) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(5.0,6.0,3.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    BOOST_CHECK_EQUAL(bounds.MaxDimension(),1);
}

BOOST_AUTO_TEST_CASE(BoundsMaxDimension3) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(5.0,4.0,30.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    BOOST_CHECK_EQUAL(bounds.MaxDimension(),2);
}

BOOST_AUTO_TEST_CASE(BoundsLerp) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(10.0,10.0,10.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Point3f pT = Point3f(0.3,0.4,0.5);
    Point3f pLerped = bounds.Lerp(pT);
    BOOST_CHECK(pLerped == Point3f(3,4,5));

}

BOOST_AUTO_TEST_CASE(BoundsPointOffset) {
    const Vector3<float> epsilon = Vector3f(0.001, 1.001, 1.001);
    Point3f expected = Point3f(0,0.3333,1.0);
    Point3f pMin = Point3f(7.0,7.0,7.0);
    Point3f pMax = Point3f(10.0,10.0,10.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Point3f p = Point3f(7,8,10);
    Point3f pOffset = bounds.Offset(p);
    std::cout << pOffset << std::endl;
    BOOST_CHECK((pOffset - expected) <= epsilon);
}

BOOST_AUTO_TEST_CASE(BoundsPointOffset2) {
    const Vector3<float> epsilon = Vector3f(0.001, 1.001, 1.001);
    Point3f expected = Point3f(0,0.3333,1.0);
    Point3f pMin = Point3f(7.0,7.0,7.0);
    Point3f pMax = Point3f(10.0,10.0,10.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Point3f p = Point3f(7,8,10);
    Point3f pOffset = bounds.Offset(p);
    std::cout << pOffset << std::endl;
    BOOST_CHECK((pOffset - expected) <= epsilon);
}

BOOST_AUTO_TEST_CASE(BoundsBoundingSphere) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(2.0,2.0,2.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    Point3f center;
    float radius;
    bounds.BoundingSphere(&center,&radius);
    // BOOST_CHECK_EQUAL(radius,1.0);
    BOOST_CHECK(center == Point3f(1,1,1));
}

BOOST_AUTO_TEST_CASE(BoundingIsEmpty) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(2.0,2.0,2.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    BOOST_CHECK(!bounds.IsEmpty());
    Point3f pMin2 = Point3f(2.0,2.0,2.0);
    Point3f pMax2 = Point3f(2.0,2.0,2.0);
    Bounds3f bounds2 = Bounds3f(pMin2,pMax2);
    BOOST_CHECK(bounds2.IsEmpty());
}

BOOST_AUTO_TEST_CASE(BoundingIsDegenerate) {
    Point3f pMin = Point3f(0.0,0.0,0.0);
    Point3f pMax = Point3f(2.0,2.0,2.0);
    Bounds3f bounds = Bounds3f(pMin,pMax);
    BOOST_CHECK(!bounds.IsDegenerate());
    Point3f pMin2 = Point3f(2.0,2.0,2.0);
    Point3f pMax2 = Point3f(2.0,2.0,2.0);
    Bounds3f bounds2 = Bounds3f(pMin2,pMax2);
    BOOST_CHECK(!bounds2.IsDegenerate());
    Point3f pMin3 = Point3f(3.0,3.0,3.0);
    Point3f pMax3 = Point3f(2.0,2.0,2.0);
    Bounds3f bounds3;
    bounds3.pMin = pMin3;
    bounds3.pMax = pMax3;
    BOOST_CHECK(bounds3.IsDegenerate());
}


BOOST_AUTO_TEST_SUITE_END()

