//
// Created by Jordan on 2/24/2016.
//

#ifndef TWONORM_H
#define TWONORM_H
template <class T>
class TwoNorm
{
  public:
    const T operator() (const Vector<T>& src);
};
#include "TwoNorm.hpp"
#endif
