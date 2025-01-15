//
// Created by Maxwell Kozlov on 12/1/24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../engine/include/util.h"
#include "../../engine/include/vector3.h"


BOOST_AUTO_TEST_SUITE(UtilTests);

BOOST_AUTO_TEST_CASE(DifferenceOfProductsErrorTest) {
    float a = 1.0f + 1e-5f;
    float b = 1.0f + 1e-5f;
    float c = 1.0f;
    float d = 1.0f + 2e-5f;
    float dopResult = util::DifferenceOfProducts(a,b,c,d);
    float badResult = (a*b) - (c*d);
    std::cout << dopResult - badResult << std::endl;
};

BOOST_AUTO_TEST_CASE(Lerp) {
    Vector3f v1 = Vector3f(1,1,1);
    Vector3f v2 = Vector3f(3,3,3);
    float t = 0.5;
    auto lerped = util::Lerp(t,v1,v2);
    BOOST_CHECK(lerped == Vector3f(2,2,2));
}





BOOST_AUTO_TEST_SUITE_END()




//
// Created by Maxwell Kozlov on 1/3/25.
//
