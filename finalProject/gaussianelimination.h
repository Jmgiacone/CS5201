/**
 *  @file gaussianelimination.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 8, 2016
 *  @brief Description: Header File for Gaussian Elimination functor
 *  @details Details:
 */



#ifndef GAUSSIANELIMINATION_H
#define GAUSSIANELIMINATION_H
#include "genericmatrix.h"
#include "algebravector.h"

///@brief Header File for Gaussian Elimination functor
template <class T>
class GaussianElimination
{
  public:
    /**
     * Purpose: Function Evaluation operator - separate Matrix and Vector
     * Pre: Parameter a must have same number of rows as b has terms
     *      Template type T must have operator/(T, T) defined
     *      Template type T must have operator=(T, T) defined
     *      Template type T must be compatible with std::abs(T)
     *      Template type T must have operator==(int, T) defined
     *      Template type T must have operator=(T, int) defined
     *      Template type T must have operator-(T, T) defined
     *      Template type T must have operator* (T, T) defined
     * Param: a - A non-augmented Matrix as the 'A' input to the equation Ax = b
     *        b - A Vector 
     *        pivoting - Whether or not to employ pivoting techniques
     * Post: If a.rows != b.numTerms, an invalid_argument exception is thrown
     *       If a or b have a zero dimension, an invalid_argument exception is thrown
     *       If a is not a square Matrix, an invalid_argument exception is thrown
     *       If there is an attempted division by zero, a domain_error exception is thrown
     * Return: The answer Vector
     */
    AlgebraVector<T> operator() (GenericMatrix<T> a, AlgebraVector<T> b);

    /**
     * Purpose: Function Evaluation operator - Augmented Matrix
     * Pre: Parameter a must have same number of rows as b has terms
     *      Template type T must have operator/(T, T) defined
     *      Template type T must have operator=(T, T) defined
     *      Template type T must be compatible with std::abs(T)
     *      Template type T must have operator==(int, T) defined
     *      Template type T must have operator=(T, int) defined
     *      Template type T must have operator-(T, T) defined
     *      Template type T must have operator* (T, T) defined
     * Param: a - An augmented Matrix
     *        pivoting - Whether or not to employ pivoting techniques
     * Post: If a.rows is not augmented (rows == columns - 1), an invalid_argument exception is thrown
     *       If a has a zero dimension, an invalid_argument exception is thrown
     *       If there is an attempted division by zero, a domain_error exception is thrown
     * Return: The augmented Matrix with all it's diagonal elements set to 1
     */
    GenericMatrix<T> operator() (GenericMatrix<T> a);
};
#include "gaussianelimination.hpp"
#endif
