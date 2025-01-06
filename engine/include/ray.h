//
// Created by Maxwell Kozlov on 1/6/25.
//
#pragma once

#include "tuple3.h"
#include "point3.h"
#include "vector3.h"

#ifndef RAY_H
#define RAY_H
class Ray {
    public:
        Point3f o;
        Vector3f d;
        Ray(const Point3f o, Vector3f d) : o(o), d(o) {};




};


#endif //RAY_H
