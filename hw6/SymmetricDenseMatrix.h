//
// Created by jordan on 4/9/16.
//

#ifndef SYMMETRICDENSEMATRIX_H
#define SYMMETRICDENSEMATRIX_H
#include "AbstractMatrix.h"
template <class T>
class SymmetricDenseMatrix;

template <class T>
SymmetricDenseMatrix<T> operator+ (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);

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
    virtual T& operator()(const int row, const int column);
    virtual T& operator()(const int row, const int column) const;
    virtual AbstractMatrix<T>* clone() const;
    virtual Vector<T> gaussianElimination(Vector<T> bVector) const;
    void swap(SymmetricDenseMatrix<T>& lhs, SymmetricDenseMatrix<T>& rhs);
  protected:
    virtual Vector<T> vectorMultiplication(const Vector<T>& bVector) const;
    virtual ostream& output(ostream& out) const;
};
#include "SymmetricDenseMatrix.hpp"
#endif
