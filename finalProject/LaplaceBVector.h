//
// Created by Jordan on 5/6/2016.
//

#ifndef LAPLACEBVECTOR_H
#define LAPLACEBVECTOR_H
#include "algebravector.h"
template <double topFunction(double x, double y),
          double bottomFunction(double x, double y),
          double leftFunction(double x, double y),
          double rightFunction(double x, double y),
          double gFunction(double x, double y),
          class T>
AlgebraVector<T> laplaceBVector(const size_t n);

template <double topFunction(double x, double y),
    double bottomFunction(double x, double y),
    double leftFunction(double x, double y),
    double rightFunction(double x, double y),
    double gFunction(double x, double y),
    class T>
AlgebraVector<T> laplaceMatrixSolver(const size_t n, bool pivoting);

template <double topFunction(double x, double y),
    double bottomFunction(double x, double y),
    double leftFunction(double x, double y),
    double rightFunction(double x, double y),
    class T>
T evaluateBorderFunction(const double x, const double y);
#include "LaplaceBVector.hpp"
#endif
