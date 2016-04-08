//
// Created by Jordan on 4/7/2016.
//

#ifndef TRIDIAGONALMATRIX_H
#define TRIDIAGONALMATRIX_H
#include "AbstractMatrix.h"
#include "Matrix.h"
#include "SmartVector.h"

template <class T>
class TriDiagonalMatrix;

template <class T>
const TriDiagonalMatrix<T> operator+ (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const TriDiagonalMatrix<T> operator- (const TriDiagonalMatrix<T>& rhs);

template <class T>
const TriDiagonalMatrix<T> operator- (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const Matrix<T> operator* (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const Vector<T> operator* (const TriDiagonalMatrix<T>& lhs, const Vector<T>& rhs);

template <class T>
const bool operator== (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const bool operator!= (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

const int NUM_DIAGONALS = 3;//, DEFAULT_ROWS = 2, DEFAULT_COLUMNS = 2;
template <class T>
class TriDiagonalMatrix : public AbstractMatrix<T>
{
  private:
    Vector<T>* data;
    int rows, columns;

  public:
    TriDiagonalMatrix() : TriDiagonalMatrix(DEFAULT_ROWS, DEFAULT_COLUMNS) {}
    TriDiagonalMatrix(int r, int c);
    TriDiagonalMatrix(int r, int c, const Vector<T>& diag1, const Vector<T>& diag2, const Vector<T>& diag3);
    TriDiagonalMatrix(const TriDiagonalMatrix<T>& rhs);
    TriDiagonalMatrix(TriDiagonalMatrix<T>&& rhs) : rows(rhs.rows), columns(rhs.columns),
                                                    data(rhs.data) {rhs.data = NULL;}
    ~TriDiagonalMatrix();
    TriDiagonalMatrix<T>& operator= (TriDiagonalMatrix<T> rhs);
    void swap(TriDiagonalMatrix<T>& x, TriDiagonalMatrix<T>& y);
    TriDiagonalMatrix<T>& operator+= (const TriDiagonalMatrix<T>& rhs);
    TriDiagonalMatrix<T>& operator-= (const TriDiagonalMatrix<T>& rhs);
    const SmartVector<T> operator[] (int x) const;
    const SmartVector<T> operator[] (int x);

    //AbstractMatrix interface functions
    virtual int numRows() const {return rows;}
    virtual int numColumns() const {return columns;}
    virtual std::ostream& output(std::ostream& out) const;

    //Friend functions
    friend const TriDiagonalMatrix<T> operator+ <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);
    friend const TriDiagonalMatrix<T> operator- <>(const TriDiagonalMatrix<T>& rhs);
    friend const TriDiagonalMatrix<T> operator- <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);
    friend const Matrix<T> operator* <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);
    friend const Vector<T> operator* <>(const TriDiagonalMatrix<T>& lhs, const Vector<T>& rhs);
    friend const bool operator== <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);
    friend const bool operator!= <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);
};
#include "TriDiagonalMatrix.hpp"
#endif
