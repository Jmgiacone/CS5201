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
class DiagonalMatrix : public AbstractMatrix<T>
{
  private:
    int dimensions;
    Vector<T>* data;
    static T zero = 0;
  public:
    DiagonalMatrix() : DiagonalMatrix(DEFAULT_DIMENSIONS) {};
    DiagonalMatrix(int d);
    DiagonalMatrix(const DiagonalMatrix<T>& src);
    DiagonalMatrix(DiagonalMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}
    ~DiagonalMatrix();

    virtual int numRows() const {return dimensions;}
    virtual int numColumns() const {return dimensions;}
    virtual AbstractMatrix<T>& operator+= (const AbstractMatrix<T>& rhs);
    virtual AbstractMatrix<T>& operator-= (const AbstractMatrix<T>& rhs);
    virtual T& operator()(const int row, const int column);
    virtual T& operator()(const int row, const int column) const;
    virtual AbstractMatrix<T>* clone() const;
    virtual Vector<T> gaussianElimination(Vector<T> bVector) const;

    //Friends
    friend DiagonalMatrix<T> operator+ <>(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);
    friend DiagonalMatrix<T> operator- <>(const DiagonalMatrix<T>& rhs);
    friend DiagonalMatrix<T> operator- <>(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);
protected:
    virtual Vector<T> vectorMultiplication(const Vector<T>& bVector) const;
};
#include "DiagonalMatrix.hpp"
#endif
