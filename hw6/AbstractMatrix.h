#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H
#include <iomanip>
#include <iostream>
#include "Vector.h"
using std::ostream;
using std::endl;
template <class T>
class AbstractMatrix;

template <class T>
ostream& operator<< (ostream& out, const AbstractMatrix<T>& rhs);

template <class T>
Vector<T> operator* (const AbstractMatrix<T>& lhs, const Vector<T>& rhs);

template <class T>
class AbstractMatrix
{
  public:
    virtual int numRows() const = 0;
    virtual int numColumns() const = 0;
    virtual AbstractMatrix<T>& operator+= (const AbstractMatrix<T>& rhs) = 0;
    virtual AbstractMatrix<T>& operator-= (const AbstractMatrix<T>& rhs) = 0;
    virtual T& operator()(const int row, const int column) = 0;
    virtual T& operator()(const int row, const int column) const = 0;
    virtual AbstractMatrix<T>* clone() const = 0;
    virtual Vector<T> gaussianElimination(Vector<T> bVector) const = 0;
    virtual ~AbstractMatrix() {}

    //Friends
    friend ostream& operator<< <>(ostream& out, const AbstractMatrix<T>& rhs);
    friend Vector<T> operator* <>(const AbstractMatrix<T>& lhs, const Vector<T>& rhs);

  protected:
    virtual Vector<T> vectorMultiplication(const Vector<T>& bVector) const = 0;
    virtual ostream& output(ostream& out) const = 0;
};
#include "AbstractMatrix.hpp"
#endif
