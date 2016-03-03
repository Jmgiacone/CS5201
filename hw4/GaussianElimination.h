#ifndef GAUSSIANELIMINATION_H
#define GAUSSIANELIMINATION_H
#include "Matrix.h"
template <class T>
class GaussianElimination
{
  public:
    Vector<T> operator() (Matrix<T> a, Vector<T> b, bool pivoting);
};
#include "GaussianElimination.hpp"
#endif
