/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: SymmetricDenseMatrix.h
 * Description: This is the header for the SymmetricDenseMatrix class
 */
#ifndef SYMMETRICDENSEMATRIX_H
#define SYMMETRICDENSEMATRIX_H
#include "AbstractMatrix.h"
template <class T>
class SymmetricDenseMatrix;

template <class T>
SymmetricDenseMatrix<T> operator+ (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);

template <class T>
SymmetricDenseMatrix<T> operator- (const SymmetricDenseMatrix<T>& rhs);

template <class T>
SymmetricDenseMatrix<T> operator- (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);

static const int DEFAULT_DIMENSIONS = 2;
template <class T>
class SymmetricDenseMatrix : public AbstractMatrix<T>
{
  private:
    int dimensions;
    Vector<T>* data;
  public:
    SymmetricDenseMatrix() : SymmetricDenseMatrix(DEFAULT_DIMENSIONS){}
    SymmetricDenseMatrix(const int d);
    SymmetricDenseMatrix(const SymmetricDenseMatrix<T>& src);
    SymmetricDenseMatrix(SymmetricDenseMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}
    ~SymmetricDenseMatrix();
    virtual int numRows() const {return dimensions;}
    virtual int numColumns() const {return dimensions;}
    virtual SymmetricDenseMatrix<T>& operator= (SymmetricDenseMatrix<T> rhs);
    virtual AbstractMatrix<T>& operator+= (const AbstractMatrix<T>& rhs);
    virtual AbstractMatrix<T>& operator-= (const AbstractMatrix<T>& rhs);
    virtual T& operator() (const int row, const int column);
    virtual T& operator() (const int row, const int column) const;
    virtual AbstractMatrix<T>* clone() const;
    void swap(SymmetricDenseMatrix<T>& lhs, SymmetricDenseMatrix<T>& rhs);

    //Friends
    friend SymmetricDenseMatrix<T> operator+ <>(const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);
    friend SymmetricDenseMatrix<T> operator- <>(const SymmetricDenseMatrix<T>& rhs);
    friend SymmetricDenseMatrix<T> operator- <>(const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);
};
#include "SymmetricDenseMatrix.hpp"
#endif
