//
// Created by Maxwell Kozlov on 12/26/24.
//

#ifndef VECTOR3_H
#define VECTOR3_H

#include "tuple3.h"
#include "point3.h"
#include "normal3.h"
#include "util.h"
#include "tuplelength.h"
#include <cmath>
template <typename T>

class Vector3 : public Tuple3<Vector3, T> {
    public:
        Vector3(): Tuple3<Vector3, T>(){};
        Vector3(T x, T y, T z): Tuple3<Vector3, T>(x,y,z){};

        template <typename U>
        explicit Vector3(Vector3<U> v) : Tuple3<Vector3, T>(T(v.x), T(v.y), T(v.z)){};

        template <typename U>
        explicit Vector3(Point3<U> p) : Tuple3<Vector3,T>(T(p.x),T(p.y),T(p.z)){};

        template <typename U>
        explicit Vector3(Normal3<U> n) : Tuple3<Vector3,T>(T(n.x),T(n.y),T(n.z)){};

        static T LengthSquared(Vector3<T> v) {
          return (v.x*v.x) + (v.y*v.y) + (v.z * v.z);
        }

        static auto Length(const Vector3<T> v) -> typename TupleLength<T>::type{
          return std::sqrt(LengthSquared(v));
        }

        // In this situation, we use AUTO because the return type is defined by the division operator
        // For the underlying Tuple3 class (using decltype magic)
        static auto Normalize(const Vector3<T> v) {
          return v / Length(v);
        }

        static T Dot(Vector3<T> v, Vector3<T> w) {
          return (v.x * w.x) + (v.y * w.y) + (v.z * w.z);
        }

        // Works only for normalized vectors
        static T CalculateAngleBetween(Vector3<T> v, Vector3<T> w) {
          // Look into why PBRT does it differently
          // return (std::acos(Dot(v,w) / (Length(v) * Length(w)))) * (180/M_PI);
          if (Dot(v, w) < 0)
              return M_PI - 2 * SafeASin(Length(v + w) / 2);
          else
              return 2 * SafeASin(Length(w - v) / 2);
        }

        static T AbsDot(Vector3<T> v, Vector3<T> w) {
          return std::abs(Dot(v,w));
        }

        // Vector W must be normalized
        static Vector3<T> GramSchmidt(Vector3<T> v, Vector3<T> w) {
          return v - Dot(v, w) * w;
        }

        static Vector3<T> FMA(Vector3<T> a, Vector3<T> b, Vector3<T> c) {
          return (a*b) + c;
        }
        static Vector3<T> CrossProduct() {

        }







};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;


#endif //VECTOR3_H
