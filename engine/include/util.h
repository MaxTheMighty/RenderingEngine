//
// Created by Maxwell Kozlov on 12/31/24.
//
#pragma once

#include <cmath>
#include <algorithm>
#include "tuple3.h"
#ifndef UTIL_H
#define UTIL_H

namespace util {
  inline float SafeASin(float n){
    return std::asin(std::clamp(n,-1.0f,1.0f));
  }

  inline float FMA(float a, float b, float c) {
    return std::fma(a,b,c);
  }

  // a*b - c*d
  inline float DifferenceOfProducts(float a, float b, float c, float d) {
    const float cd = c*d;
    const float difference = fma(a,b,-cd);
    const float error = fma(-c,d,cd);
    return difference + error;
  }

  template <typename T>
  inline auto Lerp(float t, T t1, T t2) -> decltype(T{} * float{}) {
    return (1-t) * t1 + t*t2;
  }

}
#endif //UTIL_H
