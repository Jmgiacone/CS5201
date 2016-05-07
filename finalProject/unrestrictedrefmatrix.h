/**
 *  @file unrestrictedrefmatrix.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 18, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef UNRESTRICTEDREFMATRIX_H_
#define UNRESTRICTEDREFMATRIX_H_
#include "unrestricteddimmatrix.h"
#include "refbasedmatrix.h"

///@brief represents a matrix that is unrestricted and reference
template<typename T>
class UnrestrictedRefMatrix: public virtual UnrestrictedDimMatrix<T>,
    public virtual RefBasedMatrix<T>
{
    //protected:
  public:

    ///@brief general add operator
    /// @pre T += T defined
    /// @post returns a reference to the calling object
    virtual const UnrestrictedRefMatrix<T>& operator +=(
        const AbstractMatrix<T>& rhs);
    ///@brief general subtract operator
    /// @pre T -= T defined
    /// @post returns a reference to the calling object
    virtual const UnrestrictedRefMatrix<T>& operator -=(
        const AbstractMatrix<T>& rhs);
    ///@brief transposes calling object
    /// @pre T = T defined
    /// @post returns a reference to the calling object
    virtual const AbstractMatrix<T>& transpose();

    ///@brief default constructs
    /// @pre T = T defined
    /// @post initializes both reference base and unrestricted base
    UnrestrictedRefMatrix() :
        UnrestrictedDimMatrix<T>(), RefBasedMatrix<T>()
    {
    }
    virtual ~UnrestrictedRefMatrix()
    {
    }
    ;

};

#include "unrestrictedrefmatrix.hpp"

#endif /* UNRESTRICTEDREFMATRIX_H_ */
