/**
 *  @file squarematrix.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 21, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef SQUAREMATRIX_H_
#define SQUAREMATRIX_H_

#include "abstractmatrix.h"

///@brief matrix whos rows = columns
template<typename T>
class SquareMatrix: public virtual AbstractMatrix<T>
{
  protected:
    size_t m_dim_n;
  public:
    ///@brief default constructs dimension
    /// @pre
    /// @post sets dimension to zero
    SquareMatrix() :
        m_dim_n(0)
    {
    }
    ///@brief param constructs dimension
    /// @pre
    /// @post sets m_dim_n to dim
    SquareMatrix(const size_t dim) :
        m_dim_n(dim)
    {
    }
    ///@brief copy constructs dimension
    /// @pre
    /// @post sets dimension to sm_m_dim_n
    SquareMatrix(const SquareMatrix<T>& sm) :
        m_dim_n(sm.m_dim_n)
    {
    }
    //virtual void squareSizeError(const )
    ///@brief returns rows
    /// @pre
    /// @post returns number of rows by value
    virtual size_t rows() const;
    ///@brief returns columns
    /// @pre
    /// @post returns number of columns by value
    virtual size_t columns() const;
    virtual ~SquareMatrix()
    {
    }
};

#include "squarematrix.hpp"
#endif /* SQUAREMATRIX_H_ */
