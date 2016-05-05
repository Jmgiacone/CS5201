//
// Created by Jordan on 5/4/2016.
//

#ifndef LAPLACEMATRIX_H
#define LAPLACEMATRIX_H

#include "squarematrix.h"
#include "invalidateable.h"

template <class T>
class LaplaceMatrix;

template <class T>
const LaplaceMatrix<T> operator* (const T& scalar, const LaplaceMatrix<T>& matrix);

const float DIAGONAL_COEFFICIENT = .25;
template <class T>
class LaplaceMatrix : public SquareMatrix<T>, public Invalidateable<T>
{
  private:
    int dimensions;
    T coefficient;

  public:
    LaplaceMatrix(const int d = 4) : dimensions(d), coefficient(DIAGONAL_COEFFICIENT) {}

    const T& operator() (const size_t row, const size_t column);
    friend const LaplaceMatrix<T> operator* <>(const T& scalar, const LaplaceMatrix<T>& matrix);
};
#include "LaplaceMatrix.hpp"
#endif
