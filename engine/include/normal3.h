//
// Created by Maxwell Kozlov on 12/27/24.
//

#ifndef NORMAL3_H
#define NORMAL3_H

#include "tuple3.h"

template <typename T>
class Normal3 : public Tuple3<Normal3, T> {
    public:
      Normal3(): Tuple3<Normal3, T>(){};
      Normal3(T x, T y, T z): Tuple3<Normal3,T>(x,y,z){};
};


using Normal3f = Normal3<float>;
using Normal3i = Normal3<int>;



#endif //NORMAL3_H
