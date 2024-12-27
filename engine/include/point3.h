//
// Created by Maxwell Kozlov on 12/27/24.
//

#ifndef POINT3_H
#define POINT3_H

#include "tuple3.h"

template <typename T>
class Point3: public Tuple3<Point3, T> {
    public:
      Point3(): Tuple3<Point3,T>(){};
      Point3(T x, T y, T z): Tuple3<Point3,T>(x,y,z){};

};

using Point3i = Point3<int>;
using Point3f = Point3<float>;

#endif //POINT3_H
