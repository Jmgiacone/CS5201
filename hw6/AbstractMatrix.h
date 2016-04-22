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
class AbstractMatrix
{
  public:
    virtual int numRows() const = 0;
    virtual int numColumns() const = 0;
    virtual const Vector<T> getColumn(const int column) const = 0;
    virtual T& operator()(const int row, const int column) = 0;
    virtual const T& operator()(const int row, const int column) const = 0;
    virtual AbstractMatrix<T>* clone() const = 0;
    virtual ~AbstractMatrix() {}

    //Friends
    friend ostream& operator<< <>(ostream& out, const AbstractMatrix<T>& rhs);
};
#include "AbstractMatrix.hpp"
#endif
