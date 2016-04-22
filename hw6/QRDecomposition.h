/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: QRDecomposition
 * Description: This is the header for the QRDecomposition class
 */
#ifndef QRDECOMPOSITION_H
#define QRDECOMPOSITION_H

#include "AbstractMatrix.h"
#include <vector>
template <class T>
class QRDecomposition
{
  public:
    QRDecomposition();
    void operator()(const AbstractMatrix<T>& aMatrix);
    DenseMatrix<T> getQ() {return q;}
    UpperTriangularMatrix<T> getR() {return r;}
  private:
    DenseMatrix<T> q;
    UpperTriangularMatrix<T> r;
};
#include "QRDecomposition.hpp"
#endif
