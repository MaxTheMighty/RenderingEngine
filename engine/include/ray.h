//
// Created by Maxwell Kozlov on 1/6/25.
//
#pragma once

#include "tuple3.h"
#include "point3.h"
#include "vector3.h"
#include "medium.h"

#ifndef RAY_H
#define RAY_H
class Ray {
    public:
        Point3f o;
        Vector3f d;
        float time = 0;
        Medium medium; // implemented later
        Ray(const Point3f o, const Vector3f d) : o(o), d(d) {};
        Ray(): o(), d(), time(){};

        Point3f operator()(const float t) const {
            return o + (t * d);
        }



};


#endif //RAY_H
