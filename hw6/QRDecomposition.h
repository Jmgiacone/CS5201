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
    std::vector<AbstractMatrix<T>*> operator()(const AbstractMatrix<T>& aMatrix);
};
#include "QRDecomposition.hpp"
#endif
