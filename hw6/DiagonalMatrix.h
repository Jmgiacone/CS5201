#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H
#include "AbstractMatrix.h"

template <class T>
class DiagonalMatrix;

template <class T>
DiagonalMatrix<T> operator+ (const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);

template <class T>
DiagonalMatrix<T> operator- (const DiagonalMatrix<T>& rhs);

template <class T>
DiagonalMatrix<T> operator- (const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);

template <class T>
DiagonalMatrix<T> operator* (const DiagonalMatrix<T>& lhs, DiagonalMatrix<T>& rhs);
template <class T>
class DiagonalMatrix : public AbstractMatrix<T>
{
  private:
    int dimensions;
    Vector<T> data;
    T zero = 0;
  public:
    DiagonalMatrix() : DiagonalMatrix(DEFAULT_DIMENSIONS) {};
    DiagonalMatrix(int d);
    DiagonalMatrix(const DiagonalMatrix<T>& src);
    DiagonalMatrix(DiagonalMatrix<T>&& src) : dimensions(src.dimensions), data(std::move(src.data)) {}
    DiagonalMatrix<T>& operator+= (const DiagonalMatrix<T>& rhs);
    DiagonalMatrix<T>& operator-= (const DiagonalMatrix<T>& rhs);
    virtual int numRows() const {return dimensions;}
    virtual int numColumns() const {return dimensions;}
    virtual const Vector<T> getColumn(const int column) const;
    virtual T& operator()(const int row, const int column);
    virtual const T& operator()(const int row, const int column) const;
    virtual AbstractMatrix<T>* clone() const;

    //Friends
    friend DiagonalMatrix<T> operator+ <>(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);
    friend DiagonalMatrix<T> operator- <>(const DiagonalMatrix<T>& rhs);
    friend DiagonalMatrix<T> operator- <>(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);
    friend DiagonalMatrix<T> operator* <>(const DiagonalMatrix<T>& lhs, DiagonalMatrix<T>& rhs);
};
#include "DiagonalMatrix.hpp"
#endif
