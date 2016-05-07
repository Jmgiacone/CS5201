/**
 *  @file abstractmatrix.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Mar 30, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef ABSTRACTMATRIX_H_
#define ABSTRACTMATRIX_H_
#include "algebravector.h"
#include "boundedreferencevector.h"
#include <iomanip>

template<typename T>
class AbstractMatrix;

template<typename T>
class AlgebraVector;

template<typename T>
void multMatCheck(const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs);

template<typename T>
void addSubMatCheck(const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs);

template<typename T>
void matVecDimCheck(const AbstractMatrix<T>& lhs, const AbstractVector<T>& rhs);

template<typename T>
std::ostream& operator <<(std::ostream& os, const AbstractMatrix<T>& rhs);

template<typename T>
std::istream& operator >>(std::istream& is, AbstractMatrix<T>& rhs);

template<typename T>
AlgebraVector<T> operator *(const AbstractMatrix<T>& lhs,
    const AbstractVector<T>& vector);

///@brief represents a matrix with no special definition considerations.
template<typename T>
class AbstractMatrix
{
  protected:

    ///@brief prints out the parent matrix
    ///@pre none
    ///@post object printed to the screen
    virtual std::ostream& print(std::ostream& os) const = 0;

    ///@brief If the matrix is readable, read in, if not prints out error
    ///@pre reads in data from file to fill a given matrix
    ///@post initializes the matrix based on is file data
    virtual std::istream& readin(std::istream& is) = 0;

  public:
    ///@brief multiplies by vector
    /// @pre T * T defined
    /// T = T defined
    /// @post resultant vector returned by value
    virtual AlgebraVector<T> vectorMultiply(
        const AbstractVector<T>& vector) const = 0;
    ///@brief multiplies by value
    /// @pre T *= T defined
    /// T = T defined
    /// @post matrix is multiplied and returned by reference
    virtual const AbstractMatrix<T>& operator *=(const T& rhs) = 0;
    ///@brief divides by value
    /// @pre T /= T defined
    /// T = T defined
    /// @post matrix is divided and returned by reference
    virtual const AbstractMatrix<T>& operator /=(const T& rhs) = 0;
    //virtual BoundedReferenceVector<T>& operator [](const size_t index) = 0;

    ///@brief indexes into matrix
    /// @pre none
    /// @post bounded reference vector is returned by reference
    virtual const BoundedReferenceVector<T>& operator [](
        const size_t index) const = 0;
    ///@brief indexes by row into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to row returned by reference
    virtual const BoundedReferenceVector<T>& getRow(
        const size_t index) const = 0;
    ///@brief indexes by row into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to row returned by reference
    virtual BoundedReferenceVector<T>& getRow(const size_t index) = 0;
    ///@brief indexes by column into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to column returned by reference
    virtual const BoundedReferenceVector<T>& getColumn(
        const size_t index) const = 0;
    ///@brief indexes by column into a matrix
    /// @pre none
    /// @post bounded reference vector corresponding to column returned by reference
    virtual BoundedReferenceVector<T>& getColumn(const size_t index) = 0;
    ///@brief transposes the matrix
    /// @pre T = T defined
    /// @post returns a reference to the calling object
    virtual const AbstractMatrix<T>& transpose() = 0;

    ///@brief returns the number of rows in a given matrix
    /// @pre none
    /// @post number of rows returned by value
    virtual size_t rows() const = 0;

    ///@brief returns the number of columns in a given matrix
    /// @pre none
    /// @post number of columnss returned by value
    virtual size_t columns() const = 0;
    virtual ~AbstractMatrix()
    {
    }
    ///@brief  prints a given matrix
    /// @pre  os << T defined
    /// @post prints the given matrix to the terminal and returns os object
    friend std::ostream& operator <<<T>(std::ostream& os,
        const AbstractMatrix<T>& rhs);
    ///@brief  reads a given matrix provided it is readable
    /// @pre rhs must be readable, T = T defined  is >> T defined
    /// @post reads rhs and returns istream object by reference
    friend std::istream& operator >><T>(std::istream& is,
        AbstractMatrix<T>& rhs);
    ///@brief  multiplies a matrix by a vector
    /// @pre T = T is defined, T *= T defined
    /// @post returns the resulting vector from multiplication
    friend AlgebraVector<T> operator *<T>(const AbstractMatrix<T>& lhs,
        const AbstractVector<T>& rhs);

};

#include "abstractmatrix.hpp"

#endif /* ABSTRACTMATRIX_H_ */
