/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 2
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: InfinityNorm.h
 * Description: This is the header file for the templated InfinityNorm class
 */

#ifndef INFINITYNORM_H
#define INFINITYNORM_H
template<class T>
class InfinityNorm
{
  public:
    /**
     * Purpose: To find the Infinity Norm given a vector of Polynomials
                The Infinity Norm is defined as the maximum of the 
                magnitudes of the given Polynomials
     * Pre: Template type T must have the '=' operator defined
            Template type T must have the '*' operator defined
            Template type T must have the '+=' operator defined
            Template type T must be compatible with function sqrt()
     * Post: None
     * Return: The Infinity Norm of the given vector
     */
    const T operator() (const std::vector<Polynomial<T>>& vect) const;
};
#include "InfinityNorm.hpp"
#endif
