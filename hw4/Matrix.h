#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"

using std::ostream;
using std::istream;
template<class T>
class Matrix;

template <class T>
ostream& operator<< (ostream& out, const Matrix<T>& rhs);

template <class T>
istream& operator>> (istream& in, Matrix<T>& rhs);

template <class T>
Matrix<T> operator+ (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator- (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator- (const Matrix<T>& rhs);

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Vector<T> operator* (const Matrix<T>& lhs, const Vector<T>& rhs);

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const Matrix<T>& rhs);

template <class T>
T operator* (const T& lhs, const Matrix<T>& rhs);

template <class T>
T operator* (const Matrix<T>& lhs, const T& rhs);

template <class T>
bool operator== (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
bool operator!= (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
void swap (Matrix<T>& x, Matrix<T>& y);

const int DEFAULT_ROWS = 5, DEFAULT_COLUMNS = 5;
template <class T>
class Matrix
{
  private:
    int rows;
    int columns;
    Vector<T>* data;

  public:
    Matrix ();
    Matrix (int r, int c);
    Matrix (const Matrix<T>& src);
    Matrix (Matrix<T>&& src);
    ~Matrix ();
    const T& operator[] (int x) const;
    T& operator[] (int x);
    Matrix<T>& operator= (Matrix<T> rhs);
    Matrix<T>& operator= (Matrix<T>&& rhs);
    Matrix<T>& operator+= (const Matrix<T>& rhs);
    Matrix<T>& operator+= (Matrix<T>&& rhs);
    Matrix<T>& operator-= (const Matrix<T>& rhs);
    Matrix<T>& operator-= (Matrix<T>&& rhs);
    int getRows () const;
    int getColumns () const;
    
    //Friends
    friend ostream& operator<< <>(ostream& out, const Matrix<T>& rhs);
    friend istream& operator>> <>(istream& in, Matrix<T>& rhs);
    friend Matrix<T> operator+ <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend Matrix<T> operator- <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend Matrix<T> operator- <>(const Matrix<T>& rhs);
    friend Matrix<T> operator* <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend Vector<T> operator* <>(const Matrix<T>& lhs, const Vector<T>& rhs);
    friend Vector<T> operator* <>(const Vector<T>& lhs, const Matrix<T>& rhs);
    friend T operator* <>(const T& lhs, const Matrix<T>& rhs);
    friend T operator* <>(const Matrix<T>& lhs, const T& rhs);
    friend bool operator== <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend bool operator!= <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend void swap <>(Matrix<T>& x, Matrix<T>& y);
};
#include "Matrix.hpp"
#endif
