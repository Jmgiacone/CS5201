/**
 *  @file LaplaceBVector.h
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
#include "GaussianElimination.h"
#include "QRDecomposition.h"
#include <iostream>
#include "LaplaceMatrix.h"

#define line_width 20
#define number_max 14
#define default_precision 10

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
void print_formatter(std::ostream & os, const int precision = default_precision,
                     const int width = number_max);
#include "LaplaceBVector.hpp"
#endif
