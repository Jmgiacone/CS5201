//
// Created by Jordan on 4/20/2016.
//

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
