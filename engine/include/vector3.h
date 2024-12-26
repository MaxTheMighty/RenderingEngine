//
// Created by Maxwell Kozlov on 12/26/24.
//

#ifndef VECTOR3_H
#define VECTOR3_H

#include "tuple3.h"

template <typename T>

class Vector3 : public Tuple3<Vector3, T> {
    public:
      Vector3(): Tuple3<Vector3, T>(){};
      Vector3(T x, T y, T z): Tuple3<Vector3, T>(x,y,z){};

      template <typename U>
      explicit Vector3(Vector3<U> v) : Tuple3<Vector3, T>(T(v.x), T(v.y), T(v.z)){};
};

using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;

#endif //VECTOR3_H
