//
// Created by Jordan on 4/5/2016.
//

#ifndef TRIDIAGONALMATRIX_H
#define TRIDIAGONALMATRIX_H
#include "Matrix.h"

const int DEFAULT_ROWS = 2, DEFAULT_COLUMNS = 2;
template <class T>
class TriDiagonalMatrix : public Matrix<T>
{
  private:
    int rows, columns;
    Vector<T>* data;

  public:
    TriDiagonalMatrix() : TriDiagonalMatrix(DEFAULT_ROWS, DEFAULT_COLUMNS) {}
    TriDiagonalMatrix(int r, int c);
    TriDiagonalMatrix(const TriDiagonalMatrix<T>& rhs);
    TriDiagonalMatrix(TriDiagonalMatrix&& rhs) : rows(rhs.rows), columns(rhs.columns), data(rhs.data) {rhs.data = NULL;}

    virtual Matrix<T>& operator= (Matrix<T>& rhs);
    virtual Vector<T> operator[] (const int x) const;
    virtual Vector<T> operator[] (const int x);

    //operator<<
    virtual ostream& operatorOutput(ostream& out, const Matrix<T>& rhs) const;
  
    //operator+
    virtual Matrix<T> operatorPlus(const Matrix<T>& lhs, const Matrix<T>& rhs) const;
  
    //operator-
    virtual Matrix<T> operatorMinus(const Matrix<T>& lhs, const Matrix<T>& rhs) const;
  
    //operator- unary
    virtual Matrix<T> operatorMinus(const Matrix<T>& rhs) const;
  
    //operator* - Scalar-Matrix mult
    virtual Matrix<T> operatorAsterisk(const T& lhs, const Matrix<T>& rhs) const;
  
    //operator* - Matrix-Scalar mult
    virtual Matrix<T> operatorAsterisk(const Matrix<T>& lhs, const T& rhs) const;
  
    //Operator* - Matrix-Matrix mult
    virtual Matrix<T> operatorAsterisk(const Matrix<T>& lhs, const Matrix<T>& rhs) const;
  
    //operator* - Matrix-Vector mult
    virtual Vector<T> operatorAsterisk(const Matrix<T>& lhs, const Vector<T>& rhs) const;
  
    //operator* - Vector-Matrix mult
    virtual Vector<T> operatorAsterisk(const Vector<T>& lhs, const Vector<T>& rhs) const;
  
    //operator== - Equality
    virtual bool operatorDoubleEqual(const Matrix<T>& lhs, const Matrix<T>& rhs) const;
  
    //operator!= - Inequality
    virtual bool operatorBangEqual(const Matrix<T>& lhs, const Matrix<T>& rhs) const;
};
#include "TriDiagonalMatrix.hpp"
#endif
