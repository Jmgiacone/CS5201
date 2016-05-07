/**
 *  @file LaplaceBVector.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date May 4, 2016
 *  @brief Description: PDE laplace matrix class for use
 *  in PDE estimation
 *  @details Details:
 */

#ifndef LAPLACEMATRIX_H
#define LAPLACEMATRIX_H

#include "squarematrix.h"
#include "invalidateable.h"

template <class T>
class LaplaceMatrix;

const double DIAGONAL_COEFFICIENT = -0.25;
template <class T>
class LaplaceMatrix  //public SquareMatrix<T>, public Invalidateable<T>
{
  private:
    size_t m_dim_n;
    size_t m_divisions;
    T coefficient;

  public:

    LaplaceMatrix(const size_t d = 4) : m_dim_n((d-1) * (d-1)), m_divisions(d), coefficient(DIAGONAL_COEFFICIENT) {}
    ///@brief returns the value at the given index.
    ///@pre T must be comparable/assignable with double values
    ///@post the value at the given index is returned
    const T operator() (const size_t row, const size_t column);
    void laplaceBoundCheck (const size_t row, const size_t column);
    GenericMatrix<T> toGenMat();
};
#include "LaplaceMatrix.hpp"
#endif
