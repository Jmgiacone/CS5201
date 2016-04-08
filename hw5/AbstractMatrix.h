/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: AbstractMatrix.h
 * Description: This is the interface base for an Abstract Matrix
 */

#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H
#include <iostream>
#include "Vector.h"
template <class T>
class AbstractMatrix
{
  public:
    virtual std::ostream& output(std::ostream& out) const = 0;
    friend std::ostream& operator<< (std::ostream& out, const AbstractMatrix<T>& rhs) {return rhs.output(out);}
    virtual int numRows() const = 0;
    virtual int numColumns() const = 0;
    virtual Vector<T> gaussElimation(Vector<T> bVector) const = 0;
    virtual ~AbstractMatrix() {}
};
#endif
