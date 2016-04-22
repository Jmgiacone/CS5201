/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: UpperTriangularMatrix.h
 * Description: This is the header for the UpperTriangularMatrix class
 */
#ifndef UPPERTRIAGONALMATRIX_H
#define UPPERTRIAGONALMATRIX_H
#include "AbstractMatrix.h"
template <class T>
class UpperTriangularMatrix;

template <class T>
UpperTriangularMatrix<T> operator+ (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

template <class T>
UpperTriangularMatrix<T> operator- (const UpperTriangularMatrix<T>& rhs);

template <class T>
UpperTriangularMatrix<T> operator- (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

template <class T>
void swap(UpperTriangularMatrix<T>& x, UpperTriangularMatrix<T>& y);

template <class T>
DenseMatrix<T> operator* (const UpperTriangularMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
UpperTriangularMatrix<T> operator* (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

template <class T>
class UpperTriangularMatrix : public AbstractMatrix<T>
{
   private:
    int dimensions;
    Vector<T>* data;
    T zero = 0;

  public:
    UpperTriangularMatrix() : UpperTriangularMatrix(DEFAULT_TERMS) {}
    UpperTriangularMatrix(const int d);
    UpperTriangularMatrix(const UpperTriangularMatrix<T>& src);
    UpperTriangularMatrix(UpperTriangularMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}
    ~UpperTriangularMatrix();

    UpperTriangularMatrix<T>& operator= (UpperTriangularMatrix<T> rhs);
    UpperTriangularMatrix<T>& operator+= (const UpperTriangularMatrix<T>& rhs);
    UpperTriangularMatrix<T>& operator-= (const UpperTriangularMatrix<T>& rhs);

    virtual const T& operator()(const int row, const int column) const;
    virtual T& operator()(const int row, const int column);
    virtual AbstractMatrix<T>* clone() const;
    virtual const Vector<T> getColumn(int column) const;
    virtual int numColumns() const {return dimensions;}
    virtual int numRows() const {return dimensions;}

    //Friends
    friend DenseMatrix<T> operator* <>(const UpperTriangularMatrix<T>& lhs, const DenseMatrix<T>& rhs);
    friend UpperTriangularMatrix<T> operator* <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);
    friend UpperTriangularMatrix<T> operator+ <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);
    friend UpperTriangularMatrix<T> operator- <>(const UpperTriangularMatrix<T>& rhs);
    friend UpperTriangularMatrix<T> operator- <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);
    friend void swap <>(UpperTriangularMatrix<T>& x, UpperTriangularMatrix<T>& y);
  

};
#include "UpperTriangularMatrix.hpp"
#endif
