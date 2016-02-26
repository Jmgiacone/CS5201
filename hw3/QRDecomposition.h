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
    /**
     * Purpose: operator() - Function evaluation operator
     * Pre: Template type T must have operator== (T, int) defined
     *      Template type T must have operator/ (int, T) defined
     *      Template type T must have operator= (int) defined
     * Param: a - The matrix to be decomposed
     * Post: If there is a division by zero, a domain_error exception is thrown
     * Return: A standard vector of two matrices, ordered Q and R
     */
    std::vector<std::vector<Vector<T>>> operator() (const std::vector<Vector<T>>& a);
};

#include "QRDecomposition.hpp"
#endif
