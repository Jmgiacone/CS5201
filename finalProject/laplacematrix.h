/**
 *  @file laplacematrix.h
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

template<class T>
class LaplaceMatrix;

const double DIAGONAL_COEFFICIENT = -0.25;
template<class T>
class LaplaceMatrix  //public SquareMatrix<T>, public Invalidateable<T>
{
  private:
    size_t m_dim_n;
    size_t m_divisions;
    T coefficient;

  public:

    ///@brief initializes member variables for laplaceMatrix
    ///@pre T must be assignable to DIAGONAL_COEFFICIENT and d must be more than 1
    ///@post m_dim_n, m_divisions, and coefficient are initialized
    LaplaceMatrix(const size_t d = 4) :
        m_dim_n((d - 1) * (d - 1)), m_divisions(d), coefficient(
            DIAGONAL_COEFFICIENT)
    {
    }
    ///@brief returns the value at the given index.
    ///@pre T must be comparable/assignable with double values
    ///@post the value at the given index is returned
    const T operator()(const size_t row, const size_t column);
    ///@brief checks that the given row and column exist within the laplaceMatrix
    ///@pre none
    ///@post throws an error if row and column are invalid locations in the laplaceMatrix.
    void laplaceBoundCheck(const size_t row, const size_t column);
    GenericMatrix<T> toGenMat();
};
#include "laplacematrix.hpp"
#endif
