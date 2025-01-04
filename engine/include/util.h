//
// Created by Maxwell Kozlov on 12/31/24.
//

#include <cmath>
#include <algorithm>
#ifndef UTIL_H
#define UTIL_H


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
#endif //UTIL_H
