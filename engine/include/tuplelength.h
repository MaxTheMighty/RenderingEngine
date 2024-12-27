//
// Created by Maxwell Kozlov on 12/27/24.
//

#ifndef TUPLELENGTH_H
#define TUPLELENGTH_H

template <typename T>
struct TupleLength{
  using type = float;
};

template<>
struct TupleLength<double>{
  using type = double;
};

#endif //TUPLELENGTH_H
