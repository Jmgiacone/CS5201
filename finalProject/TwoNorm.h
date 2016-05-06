/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: TwoNorm.h
 * Description: Header file for the TwoNorm functor
 */

#ifndef TWONORM_H
#define TWONORM_H
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
#include "TwoNorm.hpp"
#endif
