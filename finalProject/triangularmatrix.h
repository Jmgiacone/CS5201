/**
 *  @file triangularmatrix.h
 *  @author shae, CS5201 Section A
 *  @date Apr 19, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef TRIANGULARMATRIX_H_
#define TRIANGULARMATRIX_H_
#include "invalidateable.h"
#include "squarerefmatrix.h"

enum TRIANGLE_TYPE
{
  UPPER, LOWER
};

template<typename T>
class TriangularMatrix;

template<typename T>
TriangularMatrix<T> operator +(const TriangularMatrix<T>& lhs,
    const TriangularMatrix<T>& rhs);
template<typename T>
TriangularMatrix<T> operator -(const TriangularMatrix<T>& lhs,
    const TriangularMatrix<T>& rhs);
template<typename T>
TriangularMatrix<T> operator *(const TriangularMatrix<T>& lhs, const T& rhs);
template<typename T>
TriangularMatrix<T> operator /(const TriangularMatrix<T>& lhs, const T& rhs);
template<typename T>
TriangularMatrix<T> operator *(const T& rhs, const TriangularMatrix<T>& lhs);

template<typename T>
class TriangularMatrix: public virtual Invalidateable<T>,
    public virtual SquareRefMatrix<T>
{
  protected:

    DynamicArray<AlgebraVector<T> > m_tri_data;
    TRIANGLE_TYPE m_type;
    /// @brief will generate m_rows
    /// @pre T = T is defined
    /// @post generates m_rows to create an array of
    /// bounded references for use in bracket indexing
    virtual void createReferenceRows();
    /// @brief will generate m_cols
    /// @pre T = T is defined
    /// @post generates m_rows to create an array of
    /// bounded references for use in bracket indexing
    virtual void createReferenceCols();
    ///@brief  reads a given matrix provided it is readable
    /// @pre rhs must be readable, T = T defined  is >> T defined
    /// @post reads rhs and returns istream object by reference
    virtual std::istream& readin(std::istream& is);
  public:
    ///@brief default constructor
    /// @pre
    /// @post default constructs base classes
    TriangularMatrix() :
        UnrestrictedDimMatrix<T>(), RefBasedMatrix<T>(), m_type(UPPER)
    {

    }

    /// @brief copy constructor
    /// @pre T = T defined
    /// @post calling objects member variables deep copied from rhs, if
    /// transpose == true the items are copied in transposed order
    TriangularMatrix(const TriangularMatrix<T>& rhs);

    /// @brief move constructor
    /// @pre T = T defined
    /// @post calling objects member variables deep copied from rhs, if
    /// transpose == true the items are copied in transposed order
    TriangularMatrix(TriangularMatrix<T> && rhs);

    /// @brief parameterized constructor
    /// @pre T = T is defined
    /// @post initializes class members
    TriangularMatrix(const TRIANGLE_TYPE type,
        const DynamicArray<AlgebraVector<T> >& tri_data);

    TriangularMatrix(const size_t dim_n, const TRIANGLE_TYPE type, const T& item = T());

    /// @brief assignment operator, calling object set to rhs
    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const TriangularMatrix<T>& operator =(const TriangularMatrix<T>& rhs);

    /// @brief move assignment operator, calling object set to rhs
    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const TriangularMatrix<T>& operator =(TriangularMatrix<T> && rhs);

    /// @brief performs same type addition assignment
    /// @pre T = T is defined
    /// T += T is defined
    /// @post returns reference to calling object
    virtual const TriangularMatrix<T>& operator +=(
        const TriangularMatrix<T>& rhs);
    /// @brief performs same type subtraction assignment
    /// @pre T = T is defined
    /// T -= T is defined
    /// @post returns reference to calling object
    virtual const TriangularMatrix<T>& operator -=(
        const TriangularMatrix<T>& rhs);

    /// @brief returns transpose of calling object
    /// @pre T = T defined
    /// @post returns transpose by value
    TriangularMatrix<T> getTranspose() const;

    virtual ~TriangularMatrix()
    {
    }

    /// @brief performs same type addition
    /// @pre T = T is defined
    /// T += T is defined
    /// @post returns value of addition
    friend TriangularMatrix<T> operator +<T>(const TriangularMatrix<T>& lhs,
        const TriangularMatrix<T>& rhs);

    /// @brief performs same type subtraction
    /// @pre T = T is defined
    /// T += T is defined
    /// @post returns value of subtraction
    friend TriangularMatrix<T> operator -<T>(const TriangularMatrix<T>& lhs,
        const TriangularMatrix<T>& rhs);

    /// @brief performs a scalar multiplication on rhs
    /// @pre T = T is defined
    /// T *= T is defined
    /// @post returns the scalar multiplication of lhs and rhs by value
    friend TriangularMatrix<T> operator *<T>(const TriangularMatrix<T>& lhs,
        const T& rhs);

    /// @brief performs a scalar division on rhs
    /// @pre T = T is defined
    /// T /= T is defined
    /// @post returns the scalar division of lhs and rhs by value
    friend TriangularMatrix<T> operator /<T>(const TriangularMatrix<T>& lhs,
        const T& rhs);

    /// @brief performs a scalar multiplication on rhs
    /// @pre T = T is defined
    /// T *= T is defined
    /// @post returns the scalar multiplication of lhs and rhs by value
    friend TriangularMatrix<T> operator *<T>(const T& rhs,
        const TriangularMatrix<T>& lhs);

    /// @brief transposes the current matrix
    /// @pre T = T is defined
    /// @post transposes the current matrix
    virtual const AbstractMatrix<T>& transpose();
    /// @brief returns the triangular type of the matrix
    /// @pre none
    /// @post returns the triangular type by value
    TRIANGLE_TYPE getType() const;
};

/// @brief checks for adding and subtracting consistency on a triangular matrix
/// @pre T = T is defined
/// @post throws error if un addable
template<typename T>
void triangularAddSubCheck(const TriangularMatrix<T>& lhs,
    const TriangularMatrix<T>& rhs);

/// @brief checks for consistency on data with type
/// @pre none
/// @post if the type is upper, but the data does not match upper format throws error, and vice versa.
template<typename T>
void triangularTypeConsistencyCheck(const TRIANGLE_TYPE type,
    const DynamicArray<AlgebraVector<T> >& tri_data);

#include "triangularmatrix.hpp"
#endif /* TRIANGULARMATRIX_H_ */
