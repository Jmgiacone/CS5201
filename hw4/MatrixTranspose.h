//
// Created by jordan on 3/3/16.
//

#ifndef MATRIXTRANSPOSE_H
#define MATRIXTRANSPOSE_H
#include "Matrix.h"

template <class T>
class MatrixTranspose
{
  public:
    Matrix<T> operator() (const Matrix<T>& m);
};
#include "MatrixTranspose.hpp"
#endif
