//
// Created by jordan on 4/9/16.
//

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
class UpperTriangularMatrix : AbstractMatrix<T>
{
  private:
    static T zero = 0;
    int dimensions;
    Vector<T>* data;

  public:
    UpperTriangularMatrix() : UpperTriangularMatrix(DEFAULT_TERMS) {}
    UpperTriangularMatrix(const int d);
    UpperTriangularMatrix(const UpperTriangularMatrix<T>& src);
    UpperTriangularMatrix(UpperTriangularMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}
    ~UpperTriangularMatrix();

    UpperTriangularMatrix<T>& operator= (UpperTriangularMatrix<T> rhs);
    UpperTriangularMatrix<T>& operator+= (UpperTriangularMatrix<T>& rhs);
    UpperTriangularMatrix<T>& operator-= (UpperTriangularMatrix<T>& rhs);

    void swap(UpperTriangularMatrix<T>& x, UpperTriangularMatrix<T>& y);

    virtual T& operator()(const int row, const int column) const;
    virtual T& operator()(const int row, const int column);
    virtual AbstractMatrix<T>* clone() const;
    virtual Vector<T> gaussElimination(Vector<T> bVector) const;
    virtual Vector<T> vectorMultiplication(const Vector<T>& bVector) const;

    //Friends
    friend UpperTriangularMatrix<T> operator+ <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);
    friend UpperTriangularMatrix<T> operator- <>(const UpperTriangularMatrix<T>& rhs);
    friend UpperTriangularMatrix<T> operator- <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);
  

};
#include "UpperTriangularMatrix.hpp"
#endif
