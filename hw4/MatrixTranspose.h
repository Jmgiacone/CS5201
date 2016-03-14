/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 4
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 3/14/16
 * Filename: MatrixTranspose.h
 * Description: Header File for Matrix transpose functor
 */

#ifndef MATRIXTRANSPOSE_H
#define MATRIXTRANSPOSE_H
#include "Matrix.h"

template <class T>
class MatrixTranspose
{
  public:
    /**
     * Purpose: Function implementation operator
     * Pre: Template type T must have operator=(T) defined
     * Param: m - The Matrix to be transposed
     * Post: None
     * Return: The transpose of m
     */
    Matrix<T> operator() (const Matrix<T>& m);
};
#include "MatrixTranspose.hpp"
#endif
