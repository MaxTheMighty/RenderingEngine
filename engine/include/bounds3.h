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
    Point3<T> operator[](const int i) const {return (i == 0 ? pMin : pMax);}
    Point3<T> &operator[](const int i) { return (i == 0 ? pMin : pMax);}
    Point3<T> Corner(const int corner) const {
      return Point3<T>(
        (*this)[corner & 1].x,
        (*this)[corner & 2 ? 1 : 0].y,
        (*this)[corner & 4 ? 1 : 0].z
      );
    }

    static Bounds3<T> Union(const Bounds3<T> &b, const Point3<T> p) {
      Bounds3<T> boundsOut;
      boundsOut.pMin = Point3<T>::Min(p,b.pMin);
      boundsOut.pMax = Point3<T>::Max(p,b.pMax);
      return boundsOut;
    }

    static Bounds3<T> Union(const Bounds3<T> b1, const Bounds3<T> &b2) {
      Bounds3<T> boundsOut;
      boundsOut.pMin = Point3<T>::Min(b1.pMin,b2.pMin);
      boundsOut.pMax = Point3<T>::Max(b1.pMax,b2.pMax);
      return boundsOut;
    }


    static Bounds3<T> Intersection(const Bounds3<T> &b1, const Bounds3<T> &b2) {
      Bounds3<T> boundsOut;
      boundsOut.pMin = Point3<T>::Max(b1.pMin,b2.pMin);
      boundsOut.pMax = Point3<T>::Min(b1.pMax,b2.pMax);
      return boundsOut;
    }

    static bool Overlap(const Bounds3<T> &b1, const Bounds3<T> &b2) {
        bool xOverlap = (b2.pMin.x <= b1.pMax.x) && (b1.pMin.x <= b2.pMax.x);
        bool yOverlap = (b2.pMin.y <= b1.pMax.y) && (b1.pMin.y <= b2.pMax.y);
        bool zOverlap = (b2.pMin.z <= b1.pMax.z) && (b1.pMin.z <= b2.pMax.z);
        return xOverlap && yOverlap && zOverlap;
    }

    //



//    explicit Bounds3()

};

using Bounds3i = Bounds3<int>;
using Bounds3f = Bounds3<float>;
#endif //BOUNDS3_H
