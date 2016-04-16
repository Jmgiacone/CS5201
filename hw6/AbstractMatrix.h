#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H
#include <iostream>
#include "Vector.h"
using std::ostream;
template <class T>
class AbstractMatrix;

template <class T>
ostream& operator<< (ostream& out, const AbstractMatrix<T>& rhs);

template <class T>
bool operator== (const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs);

template <class T>
bool operator != (const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs);

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
    friend bool operator== <>(const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs);
    friend bool operator!= <>(const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs);

  protected:
    virtual bool isEqual(const AbstractMatrix<T>& rhs) const = 0;
    virtual ostream& output(ostream& out) const = 0;
};
#include "AbstractMatrix.hpp"
#endif
