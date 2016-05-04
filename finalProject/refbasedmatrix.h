/**
 *  @file refbasedmatrix.h
 *  @author shae, CS5201 Section A
 *  @date Apr 18, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef REFBASEDMATRIX_H_
#define REFBASEDMATRIX_H_

#include "abstractmatrix.h"

///@brief a matrix based on references
template<typename T>
class RefBasedMatrix: public virtual AbstractMatrix<T>
{
  protected:
    ///@brief creates the reference row objects
    ///@pre T = T defined
    ///@post row reference objects created
    virtual void createReferenceRows() = 0;
    ///@brief creates the reference column objects
    ///@pre T = T defined
    ///@post column reference objects created
    virtual void createReferenceCols() = 0;
    ///@brief creates the reference row and column objects
    ///@pre T = T defined
    ///@post row column reference objects created
    virtual void initReferenceDims();
    ///@brief prints matrix to terminal
    ///@pre T << defined for os
    ///@post prints matrix to screen and os reference returned
    virtual std::ostream& print(std::ostream& os) const;

    bool m_transposed;
    DynamicArray<BoundedReferenceVector<T> > m_rows;
    DynamicArray<BoundedReferenceVector<T> > m_cols;
  public:
    ///@brief returns vector multiplication
    ///@pre T *T and T *= T defined
    ///@post resultat product returned by value
    virtual AlgebraVector<T> vectorMultiply(
        const AbstractVector<T>& vector) const;
    ///@brief sets the transpose to false
    ///@pre none
    ///@post sets the transpose to false
    RefBasedMatrix() :
        m_transposed(false)
    {
    }
    ;
    ///@brief paramaterized constructor
    ///@pre non
    ///@post initializes transpose from parameter
    RefBasedMatrix(const RefBasedMatrix<T>& rbm) :
        m_transposed(rbm.m_transposed)
    {
    }
    ///@brief multiplies by value
    /// @pre T *= T defined
    /// T = T defined
    /// @post matrix is multiplied and returned by reference
    virtual const AbstractMatrix<T>& operator *=(const T& rhs);
    ///@brief divides by value
    /// @pre T /= T defined
    /// T = T defined
    /// @post matrix is divided and returned by reference
    virtual const AbstractMatrix<T>& operator /=(const T& rhs);
    ///@brief indexes into matrix
    /// @pre none
    /// @post bounded reference vector is returned by reference
    virtual BoundedReferenceVector<T>& operator [](const size_t index);
    ///@brief indexes into matrix
    /// @pre none
    /// @post bounded reference vector is returned by reference
    virtual const BoundedReferenceVector<T>& operator [](
        const size_t index) const;
    ///@brief indexes by row into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to row returned by reference
    virtual const BoundedReferenceVector<T>& getRow(const size_t index) const;
    ///@brief indexes by row into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to row returned by reference
    virtual BoundedReferenceVector<T>& getRow(const size_t index);
    ///@brief indexes by column into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to column returned by reference
    virtual const BoundedReferenceVector<T>& getColumn(
        const size_t index) const;
    ///@brief indexes by column into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to column returned by reference
    virtual BoundedReferenceVector<T>& getColumn(const size_t index);
    ///@brief transposes the matrix
    /// @pre T = T defined
    /// @post returns a reference to the calling object
    virtual const AbstractMatrix<T>& transpose();

    ///@brief
    ///@pre
    ///@post
    virtual ~RefBasedMatrix()
    {
    }
    ;
};

#include "refbasedmatrix.hpp"

#endif /* REFBASEDMATRIX_H_ */
