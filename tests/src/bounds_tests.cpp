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



BOOST_AUTO_TEST_SUITE_END()

