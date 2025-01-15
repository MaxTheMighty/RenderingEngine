//
// Created by Maxwell Kozlov on 12/27/24.
//

#ifndef POINT3_H
#define POINT3_H


#include "tuple3.h"
template <typename T>
class Vector3;

template <typename T>
class Point3: public Tuple3<Point3, T> {
public:
    using Tuple3<Point3, T>::x;
    using Tuple3<Point3, T>::y;
    using Tuple3<Point3, T>::z;
    using Tuple3<Point3, T>::operator+;
    using Tuple3<Point3, T>::operator-;

    Point3(): Tuple3<Point3,T>(){};
    Point3(T x, T y, T z): Tuple3<Point3,T>(x,y,z){};

    template<typename U>
    explicit Point3(Point3<U> p) : Tuple3<Point3,T>(T(p.x),T(p.y),T(p.z)){};

    template<typename U>
    explicit Point3(Vector3<U> v) : Tuple3<Point3,T>(T(v.x),T(v.y),T(v.z)){};

    template<typename U>
    auto operator+(Vector3<U> v) const -> Point3<decltype(T{} + U{})> {
        return {x + v.x,y + v.y, z + v.z};
    }

    template<typename U>
    Point3 &operator+=(Vector3<U> v) {
        x+=v.x;
        y+=v.y;
        z+=v.z;
        return *this;
    }

    template<typename U>
    auto operator-(Point3<U> v) const -> Vector3<decltype(T{} + U{})> {
        return {x - v.x, y - v.y, z - v.z};
    }

    static auto Distance(Point3<T> p1, Point3<T> p2) {
        return Vector3<T>::Length(p1-p2);
    }

    static auto DistanceSquared(Point3<T> p1, Point3<T> p2) {
        return Vector3<T>::LengthSquared(p1-p2);
    }

};

using Point3i = Point3<int>;
using Point3f = Point3<float>;

#endif //POINT3_H
