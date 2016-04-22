/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: LowerTriangularMatrix.h
 * Description: This is the header for the LowerTriangularMatrix class
 */

#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "AbstractMatrix.h"
template <class T>
class LowerTriangularMatrix;

template <class T>
LowerTriangularMatrix<T> operator+ (const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

template <class T>
LowerTriangularMatrix<T> operator- (const LowerTriangularMatrix<T>& rhs);

template <class T>
LowerTriangularMatrix<T> operator- (const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

template <class T>
void swap(LowerTriangularMatrix<T>& x, LowerTriangularMatrix<T>& y);

template <class T>
class LowerTriangularMatrix : public AbstractMatrix<T>
{
  private:
    static T zero = 0;
    int dimensions;
    Vector<T>* data;

  public:
    LowerTriangularMatrix() : LowerTriangularMatrix(DEFAULT_TERMS) {}
    LowerTriangularMatrix(const int d);
    LowerTriangularMatrix(const LowerTriangularMatrix<T>& src);
    LowerTriangularMatrix(LowerTriangularMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}
    ~LowerTriangularMatrix();

    LowerTriangularMatrix<T>& operator= (LowerTriangularMatrix<T> rhs);
    LowerTriangularMatrix<T>& operator+= (const LowerTriangularMatrix<T>& rhs);
    LowerTriangularMatrix<T>& operator-= (const LowerTriangularMatrix<T>& rhs);

    virtual T& operator()(const int row, const int column) const;
    virtual T& operator()(const int row, const int column);
    virtual AbstractMatrix<T>* clone() const;

    //Friends
    friend LowerTriangularMatrix<T> operator+ <>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
    friend LowerTriangularMatrix<T> operator- <>(const LowerTriangularMatrix<T>& rhs);
    friend LowerTriangularMatrix<T> operator- <>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
    friend void swap <>(LowerTriangularMatrix<T>& x, LowerTriangularMatrix<T>& y);
};
#include "LowerTriangularMatrix.hpp"
#endif
