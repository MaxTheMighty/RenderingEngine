//
// Created by Maxwell Kozlov on 1/27/25.
//
#include <array>

#include "point3.h"
#include "vector3.h"


#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle {
public:
    std::array<Point3f, 3> vertices;
    Triangle(Point3f pointA, Point3f pointB, Point3f pointC);
};
#endif //TRIANGLE_H

