//
// Created by Jordan on 2/24/2016.
//

#ifndef QRDECOMPOSITION_H
#define QRDECOMPOSITION_H
#include "Vector.h"
template <class T>
class QRDecomposition
{
  public:
    std::vector<std::vector<Vector<T>>>& operator() (const std::vector<Vector<T>>& a);
};

#include "QRDecomposition.hpp"
#endif
