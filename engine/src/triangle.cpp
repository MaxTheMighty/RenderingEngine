//
// Created by Maxwell Kozlov on 1/27/25.
//
#include "../include/triangle.h"
#include "../include/point3.h"
Triangle::Triangle(Point3f pointA, Point3f pointB, Point3f pointC) {
   this->vertices[0] = pointA;
   this->vertices[1] = pointB;
   this->vertices[2] = pointC;
}

