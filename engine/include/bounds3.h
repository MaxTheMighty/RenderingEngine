//
// Created by Maxwell Kozlov on 1/8/25.
//

#ifndef BOUNDS3_H
#define BOUNDS3_H
#include "point3.h"
#include "tuplelength.h"
#include "util.h"

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

    static bool Inside(const Bounds3<T> &b, const Point3<T> p) {
      return (p.x >= b.pMin.x && p.x <= b.pMax.x) &&
             (p.y >= b.pMin.y && p.y <= b.pMax.y) &&
             (p.z >= b.pMin.z && p.z <= b.pMax.z);
    }

    // Doesn't consider points within the upper boundary to count
    static bool InsideExclusive(const Bounds3<T> &b, const Point3<T> p) {
      return (p.x >= b.pMin.x && p.x < b.pMax.x) &&
        (p.y >= b.pMin.y && p.y < b.pMax.y) &&
        (p.z >= b.pMin.z && p.z < b.pMax.z);
    }


    template <typename U>
    static auto DistanceSquared(Point3<T> p, const Bounds3<U> &b) {
      using TD = decltype(T{} - U{});
      TD dx = std::max<TD>({0,b.pMin.x - p.x,p.x-b.pMax.x});
      TD dy = std::max<TD>({0,b.pMin.y - p.y,p.y-b.pMax.y});
      TD dz = std::max<TD>({0,b.pMin.z - p.z,p.z-b.pMax.z});
      return (dx * dx) + (dy * dy) + (dz * dz);
    }

    // This function has some type magic going on that I will try to explain
    // DistanceSquared returns some type according to type promotion rules
    // TupleLength is a templated struct that is used for storing which type
    // should be used as the length of a tuple. If double is passed to it as the template
    // its double. Otherwise its float. This basically means make everything a float
    // unless its a double. We then typecast the value to the TupleLength value and return its sqrt.
    template <typename U>
    static auto Distance(Point3<U> p, const Bounds3<T> &b) {
      auto distSqr = DistanceSquared(p,b);
      using TD = typename TupleLength<decltype(distSqr)>::type;
      return std::sqrt(TD(distSqr));
    }

    template <typename U>
    static Bounds3<T> Expand(const Bounds3<T> &b, U const delta) {
      Bounds3<T> boundsOut;
      boundsOut.pMin = (b.pMin - delta);
      boundsOut.pMax = (b.pMax + delta);
      return boundsOut;
    }

    Vector3<T> Diagonal() const {
      return pMax - pMin;
    }

    T SurfaceArea() const {
      Vector3<T> diagonal = Diagonal();
      return 2*((diagonal.x * diagonal.y) + (diagonal.y * diagonal.z) + (diagonal.x * diagonal.z));
    }

    T Volume() const {
      Vector3<T> diagonal = Diagonal();
      return diagonal.x * diagonal.y * diagonal.z;
    }

    int MaxDimension() const {
      Vector3<T> diagonal = Diagonal();
      if (diagonal.x > diagonal.y && diagonal.x > diagonal.z) { return 0;}
      if (diagonal.y > diagonal.z) {return 1;}
      return 2;
    }

    Point3<T> Lerp(Point3<T> t) {

      // we are going to lerp between all the corners
      // in x, y, and z
      // its going to be a point since its a specific location along the bounds
      return Point3<T>(
        util::Lerp(t.x,pMin.x,pMax.x),
        util::Lerp(t.y,pMin.y,pMax.y),
        util::Lerp(t.z,pMin.z,pMax.z)
        );
    }


    // assume that the point is actually in the box
    Point3<T> Offset(Point3<T> p) {
      return Point3<T>(
        (p.x-pMin.x )/ (pMax.x - pMin.x),
        (p.y-pMin.y) / (pMax.y - pMin.y),
        (p.z-pMin.z) / (pMax.z - pMin.z)
      );
    }

    void BoundingSphere(Point3<T> *center, float *radius) {
      (*center) = (pMin + pMax) / 2;
      // if the center is in the box, give the data
      if (Inside(*this,*center)) {
        *radius = Point3<T>::Distance(*center,pMax);
      } else {
        *radius = 0;
      }
    }

    bool IsEmpty() const{
      return pMin.x >= pMax.x || pMin.y >= pMax.y || pMin.z >= pMax.z;
    }

    bool IsDegenerate() const {
      return pMin.x > pMax.x || pMin.y > pMax.y || pMin.z > pMax.z;
    }

   //TODO implement the forward iterator for points







};

using Bounds3i = Bounds3<int>;
using Bounds3f = Bounds3<float>;
#endif //BOUNDS3_H
