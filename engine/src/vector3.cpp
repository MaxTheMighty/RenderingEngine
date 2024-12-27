//
// Created by Maxwell Kozlov on 12/26/24.
//

#include "../include/vector3.h"
#include <cmath>

template<typename T>
T Vector3<T>::LengthSquared(Vector3<T> v) {
    return (v.x*v.x) + (v.y*v.y) + (v.z * v.z);
}

template<typename T>
auto Vector3<T>::Length(Vector3<T> v) -> typename TupleLength<T>::type {
    return std::sqrt(LengthSquared(v));
}