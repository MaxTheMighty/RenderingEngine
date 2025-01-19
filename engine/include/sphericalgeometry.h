//
// Created by Maxwell Kozlov on 1/19/25.
//

#include "vector3.h"
#include <cmath>
#ifndef SPHERICALGEOMETRY_H
#define SPHERICALGEOMETRY_H



inline float SphericalTriangleArea(Vector3f &a, Vector3f &b, Vector3f &c){
    return std::abs(2 * std::atan2(Vector3f::Dot(a,Vector3f::CrossProduct(b,c)), 1 + Vector3f::Dot(a,b) + Vector3f::Dot(a,c) + Vector3f::Dot(b,c)));
}

inline float SphericalQuadArea(Vector3f &a, Vector3f &b, Vector3f &c, Vector3f &d) {
    // get cross products of adjacent vectors
    Vector3f axb = Vector3f::CrossProduct(a,b);
    Vector3f bxc = Vector3f::CrossProduct(b,c);
    Vector3f cxd = Vector3f::CrossProduct(c,d);
    Vector3f dxa = Vector3f::CrossProduct(d,a);

    // if any length is 0, return 0
    if (Vector3f::LengthSquared(axb) == 0 || Vector3f::LengthSquared(bxc) == 0 || Vector3f::LengthSquared(cxd) == 0 || Vector3f::LengthSquared(dxa) == 0) {
        return 0;
    }

    // normalize
    axb = Vector3f::Normalize(axb);
    bxc = Vector3f::Normalize(bxc);
    cxd = Vector3f::Normalize(cxd);
    dxa = Vector3f::Normalize(dxa);


    // calculate angles (alpha, beta, etc...)
    float alpha = Vector3f::CalculateAngleBetween(axb,-bxc);
    float beta = Vector3f::CalculateAngleBetween(bxc,-cxd);
    float gamma = Vector3f::CalculateAngleBetween(cxd,-dxa);
    float delta = Vector3f::CalculateAngleBetween(dxa,-axb);

    std::cout << alpha+beta+gamma+delta << std::endl;
    return std::fabs(alpha + beta + delta + gamma - 2 * M_PI);
    // apply gerards theorm
}
#endif //SPHERICALGEOMETRY_H
