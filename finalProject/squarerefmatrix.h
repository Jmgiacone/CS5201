/**
 *  @file squarerefmatrix.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 21, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef SQUAREREFMATRIX_H_
#define SQUAREREFMATRIX_H_
#include "squarematrix.h"
#include "refbasedmatrix.h"

///@brief a matrix who's rows number the same as columns and reference
template<typename T>
class SquareRefMatrix: public virtual SquareMatrix<T>,
    public virtual RefBasedMatrix<T>
{
  public:
    ///@brief generalized add assignment
    /// @pre T += T
    /// @post returns reference to calling object
    virtual const SquareRefMatrix<T>& operator +=(const AbstractMatrix<T>& rhs);
    ///@brief generalized subtract assignment
    /// @pre T -= T
    /// @post returns reference to calling object
    virtual const SquareRefMatrix<T>& operator -=(const AbstractMatrix<T>& rhs);
    ///@brief default constructing
    /// @pre T += T
    /// @post rcalls the default constructors for base classes
    SquareRefMatrix() :
        SquareMatrix<T>(), RefBasedMatrix<T>()
    {
    }
    virtual ~SquareRefMatrix()
    {
    }

};
#include "squarerefmatrix.hpp"
#endif /* SQUAREREFMATRIX_H_ */
