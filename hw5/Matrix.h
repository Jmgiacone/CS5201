/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: Matrix.h
 * Description: This is an Interface Base for an abstract Matrix
 */


#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Vector.h"

using std::ostream;

//Forward-declare Matrix class
template <class T>
class Matrix;

template <class T>
ostream& operator<< (ostream& out, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator+ (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator- (const Matrix<T>& rhs);

template <class T>
Matrix<T> operator* (const T& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const T& rhs);

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Vector<T> operator* (const Matrix<T>& lhs, const Vector<T>& rhs);

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const Vector<T>& rhs);

template <class T>
bool operator== (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
bool operator!= (const Matrix<T>& lhs, const Matrix<T>& rhs);

template<class T>
class Matrix
{
  public:
    //Public pure-virtual member functions
    virtual Matrix<T>& operator= (Matrix<T>& rhs) = 0;
    virtual Vector<T> operator[] (const int x) const = 0;
    virtual Vector<T> operator[] (const int x) = 0;

    //Non-virtual member operators
    Matrix<T>& operator+= (const Matrix<T>& rhs);
    Matrix<T>& operator-= (const Matrix<T>& rhs);

    //Non-virtual friends
    friend ostream& operator<< <>(ostream& out, const Matrix<T>& rhs);
    friend Matrix<T> operator+ <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend Matrix<T> operator- <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend Matrix<T> operator- <>(const Matrix<T>& rhs);
    friend Matrix<T> operator* <>(const T& lhs, const Matrix<T>& rhs);
    friend Matrix<T> operator* <>(const Matrix<T>& lhs, const T& rhs);
    friend Matrix<T> operator* <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend Vector<T> operator* <>(const Matrix<T>& lhs, const Vector<T>& rhs);
    friend Vector<T> operator* <>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend bool operator== <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
    friend bool operator!= <>(const Matrix<T>& lhs, const Matrix<T>& rhs);
  
  protected:
    //Protected pure-virtual member functions to give off the illusion of virtual friends

    //operator<<
    virtual ostream& operatorOutput(ostream& out, const Matrix<T>& rhs) const = 0;

    //operator+
    virtual Matrix<T> operatorPlus(const Matrix<T>& lhs, const Matrix<T>& rhs) const = 0;

    //operator-
    virtual Matrix<T> operatorMinus(const Matrix<T>& lhs, const Matrix<T>& rhs) const = 0;

    //operator- unary
    virtual Matrix<T> operatorMinus(const Matrix<T>& rhs) const = 0;

    //operator* - Scalar-Matrix mult
    virtual Matrix<T> operatorAsterisk(const T& lhs, const Matrix<T>& rhs) const = 0;

    //operator* - Matrix-Scalar mult
    virtual Matrix<T> operatorAsterisk(const Matrix<T>& lhs, const T& rhs) const = 0;

    //Operator* - Matrix-Matrix mult
    virtual Matrix<T> operatorAsterisk(const Matrix<T>& lhs, const Matrix<T>& rhs) const = 0;

    //operator* - Matrix-Vector mult
    virtual Vector<T> operatorAsterisk(const Matrix<T>& lhs, const Vector<T>& rhs) const = 0;

    //operator* - Vector-Matrix mult
    virtual Vector<T> operatorAsterisk(const Vector<T>& lhs, const Vector<T>& rhs) const = 0;

    //operator== - Equality
    virtual bool operatorDoubleEqual(const Matrix<T>& lhs, const Matrix<T>& rhs) const = 0;

    //operator!= - Inequality
    virtual bool operatorBangEqual(const Matrix<T>& lhs, const Matrix<T>& rhs) const = 0;
};
#include "Matrix.hpp"
#endif
