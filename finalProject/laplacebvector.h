/**
 *  @file laplacebvector.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date May 6, 2016
 *  @brief Description: PDE laplace matrix estimation functions
 *  given a set of four border functions and a forcing function
 *  @details Details:
 */


//
// Created by Jordan on 5/6/2016.
//

#ifndef LAPLACEBVECTOR_H
#define LAPLACEBVECTOR_H
#include "algebravector.h"
#include "triangularmatrix.h"
#include <iostream>

#include "gaussianelimination.h"
#include "laplacematrix.h"
#include "qrdecomposition.h"

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
AlgebraVector<T> laplaceMatrixSolver(const size_t n, bool qrMethod);

template <double topFunction(double x, double y),
    double bottomFunction(double x, double y),
    double leftFunction(double x, double y),
    double rightFunction(double x, double y),
    class T>
T evaluateBorderFunction(const double x, const double y);
#include "laplacebvector.hpp"
#endif
