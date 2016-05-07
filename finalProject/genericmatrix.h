/**
 *  @file genericmatrix.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Mar 13, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef GENERICMATRIX_H_
#define GENERICMATRIX_H_
#include "unrestrictedrefmatrix.h"

template<typename T>
class GenericMatrix;

template<typename T>
class GaussianSolver;

template<typename T>
GenericMatrix<T> operator +(const GenericMatrix<T>& lhs,
    const AbstractMatrix<T>& rhs);
template<typename T>
GenericMatrix<T> operator -(const GenericMatrix<T>& lhs,
    const AbstractMatrix<T>& rhs);
template<typename T>
GenericMatrix<T> operator *(const GenericMatrix<T>& lhs,
    const AbstractMatrix<T>& rhs);
template<typename T>
GenericMatrix<T> operator *(const GenericMatrix<T>& lhs, const T& rhs);
template<typename T>
GenericMatrix<T> operator /(const GenericMatrix<T>& lhs, const T& rhs);
template<typename T>
GenericMatrix<T> operator *(const T& rhs, const GenericMatrix<T>& lhs);

template<typename T>
GenericMatrix<T> vandermonde(const AlgebraVector<T>& x);

///@brief represents a genericmatrix of vectors with operations
template<typename T>
class GenericMatrix: public virtual UnrestrictedRefMatrix<T>
{
  protected:
    DynamicArray<AlgebraVector<T> > m_data;
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

    friend class GaussianSolver<T> ;

    ///@brief default constructor
    /// @pre
    /// @post default constructs base classes
    GenericMatrix() :
        UnrestrictedDimMatrix<T>(), RefBasedMatrix<T>()
    {
    }

    /// @brief copy constructor
    /// @pre T = T defined
    /// @post calling objects member variables deep copied from rhs, if
    /// transpose == true the items are copied in transposed order
    GenericMatrix(const GenericMatrix<T>& rhs);

    /// @brief move constructor
    /// @pre T = T defined
    /// @post calling objects member variables deep copied from rhs, if
    /// transpose == true the items are copied in transposed order
    GenericMatrix(GenericMatrix<T> && rhs);

    /// @brief generalized copy constructor
    /// @pre T = T is defined
    /// @post copies all data from rhs into calling object

    GenericMatrix(const AbstractMatrix<T>& rhs);

    /// @brief parameterized data constructor
    /// @pre T = T is defined
    /// @post initializes class members based off of data
    GenericMatrix(const DynamicArray<AlgebraVector<T> >& data);

    /// @brief parameterized constructor
    /// @pre T = T is defined
    /// @post initializes class members
    GenericMatrix(const size_t rows, const AlgebraVector<T>& row);

    ///@TODO ADD TO UML
    /// @brief parameterized constructor
    /// @pre T = T is defined
    /// @post initializes class members to item with given size constraints
    GenericMatrix(const size_t rows, const size_t cols, const T& item = T());

    ///@TODO ADD TO UML
    /// @brief parameterized constructor
    /// @pre T = T is defined
    /// @post initializes class members to item with given size constraints
    GenericMatrix(const size_t dim_n, const T& item = T()) : GenericMatrix(dim_n, dim_n, item) {}

    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const GenericMatrix<T>& operator =(const GenericMatrix<T>& rhs);

    /// @brief move assignment operator, calling object set to rhs
    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const GenericMatrix<T>& operator =(GenericMatrix<T> && rhs);

    /// @brief base class assignment
    /// @pre T = T defined
    /// @post returns the callling object by reference
    const GenericMatrix<T>& operator =(const AbstractMatrix<T> & rhs);

    /// @brief returns transpose of calling object
    /// @pre T = T defined
    /// @post returns transpose by value
    virtual GenericMatrix<T> getTranspose();

    virtual ~GenericMatrix()
    {
    }

    /// @brief performs matrix multiplication
    /// @pre T = T is defined
    /// T *= T is defined
    /// T + T
    /// @post returns the value of the mulitplication

    friend GenericMatrix<T> operator *<T>(const GenericMatrix<T>& lhs,
        const AbstractMatrix<T>& rhs);
    /// @brief performs same type addition
    /// @pre T = T is defined
    /// T += T is defined
    /// @post returns value of addition
    friend GenericMatrix<T> operator +<T>(const GenericMatrix<T>& lhs,
        const AbstractMatrix<T>& rhs);

    /// @brief performs same type subtraction
    /// @pre T = T is defined
    /// T += T is defined
    /// @post returns value of subtraction
    friend GenericMatrix<T> operator -<T>(const GenericMatrix<T>& lhs,
        const AbstractMatrix<T>& rhs);

    /// @brief performs a scalar multiplication on rhs
    /// @pre T = T is defined
    /// T *= T is defined
    /// @post returns the scalar multiplication of lhs and rhs by value
    friend GenericMatrix<T> operator *<T>(const GenericMatrix<T>& lhs,
        const T& rhs);

    /// @brief performs a scalar division on rhs
    /// @pre T = T is defined
    /// T /= T is defined
    /// @post returns the scalar division of lhs and rhs by value
    friend GenericMatrix<T> operator /<T>(const GenericMatrix<T>& lhs,
        const T& rhs);

    /// @brief performs a scalar multiplication on rhs
    /// @pre T = T is defined
    /// T *= T is defined
    /// @post returns the scalar multiplication of lhs and rhs by value
    friend GenericMatrix<T> operator *<T>(const T& rhs,
        const GenericMatrix<T>& lhs);

    friend GenericMatrix<T> vandermonde<T>(const AlgebraVector<T>& x);

};

#include "genericmatrix.hpp"

//#include "guassiansolver.h"

#endif /* GENERICMATRIX_H_ */
