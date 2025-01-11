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
        Ray(const Point3f o, const Vector3f d, float time = 0.f) : o(o), d(d), time(time) {};
        Ray() = default;
        Point3f operator()(const float t) const {
            return o + (t * d);
        }



};

class RayDifferential : public Ray {
    public:
        bool hasDifferentials = false;
        Point3f rxOrigin, ryOrigin;
        Vector3f rxDirection, ryDirection;
        RayDifferential(const Point3f o, const Vector3f d, float time = 0.f): Ray(o,d,time){};
        explicit RayDifferential(const Ray &ray) : Ray(ray) {};

        void ScaleDifferentials(float s) {
            rxOrigin = o + (rxOrigin - o) * s;
            ryOrigin = o + (ryOrigin - o) * s;
            rxDirection = d + (rxDirection - d) * s;
            ryDirection = d + (ryDirection - d) * s;
        }
};


#endif //RAY_H
