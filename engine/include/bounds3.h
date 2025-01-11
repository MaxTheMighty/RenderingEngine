//
// Created by Maxwell Kozlov on 1/8/25.
//

#ifndef BOUNDS3_H
#define BOUNDS3_H
#include "point3.h"
template <typename T>
class Bounds3{
  public:
    Point3<T> pMin;
    Point3<T> pMax;
    Bounds3(){
      T min = std::numeric_limits<T>::lowest();
      T max = std::numeric_limits<T>::max();
      pMin = Point3<T>(min,min,min);
      pMax = Point3<T>(max,max,max);
    }
    explicit Bounds3(Point3<T> p1, Point3<T> p2) : pMin(Point3<T>::Min(p1,p2)), pMax(Point3<T>::Max(p1,p2)) {};
    explicit Bounds3(Point3<T> p) : pMin(p), pMax(p) {};



//    explicit Bounds3()

};

using Bounds3i = Bounds3<int>;
using Bounds3f = Bounds3<float>;
#endif //BOUNDS3_H
