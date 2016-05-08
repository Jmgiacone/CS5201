/**
 *  @file twonorm.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 22, 2016
 *  @brief Description: Header file for the TwoNorm functor
 *  @details Details:
 */



#ifndef TWONORM_H
#define TWONORM_H

#include <iostream>
#include <cmath>
#include "algebravector.h"

template <class T>
class TwoNorm
{
  public:
    /**
     * Purpose: operator() - Function evaluation operator
     * Pre: Parameter src must have a non-zero size
     *      Template type T must have operator* (T, T) defined
     *      Template type T must have operator= (T) defined
     *      Template type T must have operator+ (T, T) defined
     *      std::sqrt(T) must be defined for template type T
     * Param: src - The Vector for the Two Norm to be applied to
     * Post: If parameter src has a size of zero, an invalid_argument exception is thrown
     * Return: The Two Norm of parameter src
     */
    const T operator() (const AlgebraVector<T>& src);
};
#include "twonorm.hpp"
#endif
