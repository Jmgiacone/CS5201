/**
 *  @file invalidateable.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 20, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef INVALIDATEABLE_H_
#define INVALIDATEABLE_H_
#include "genericmatrix.h"
#include "boundedreferencevector.h"

///@brief represents a matrix that can be invalidiated
template<typename T>
class Invalidateable: public virtual AbstractMatrix<T>
{
  public:
    // virtual void InvalidateError() = 0;
    virtual ~Invalidateable()
    {
    }
    ;
};

///@brief add operator for any abstract matrix
///@pre T += T defined
/// @post returns a new created general matrix result of the operation
template<typename T>
GenericMatrix<T> operator +(const Invalidateable<T>& lhs,
    const AbstractMatrix<T>& rhs);
///@brief subtract operator for any abstract matrix
///@pre T -= T defined
/// @post returns a new created general matrix result of the operation
template<typename T>
GenericMatrix<T> operator -(const Invalidateable<T>& lhs,
    const AbstractMatrix<T>& rhs);
///@brief multiply operator for any abstract matrix
///@pre T *= T defined
/// @post returns a new created general matrix result of the operation
template<typename T>
GenericMatrix<T> operator *(const Invalidateable<T>& lhs,
    const AbstractMatrix<T>& rhs);
///@brief check to see if the data used in any type of matrix which uses trangular data is valid
///@pre none
/// @post throws an error if the given data does not follow triangularity
template<typename T>
void triangularConsistencyCheck(
    const DynamicArray<AlgebraVector<T> >& tri_data);

#include "invalidateable.hpp"

#endif /* INVALIDATEABLE_H_ */
