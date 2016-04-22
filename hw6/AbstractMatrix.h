/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: AbstractMatrix.h
 * Description: This is the interface base for an Abstract Matrix
 */
#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H
#include <iomanip>
#include <iostream>
#include "Vector.h"
using std::ostream;
using std::endl;
template <class T>
class AbstractMatrix;

template <class T>
ostream& operator<< (ostream& out, const AbstractMatrix<T>& rhs);

template <class T>
class AbstractMatrix
{
  public:
    /*
     * Purpose: Retrieve the number of rows
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows
     */
    virtual int numRows() const = 0;

    /*
     * Purpose: Retrieve the number of columns
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns
     */
    virtual int numColumns() const = 0;

    /*
     * Purpose: Gets the specified column
     * Pre: column must be in the range [0, numColumns())
     * Param: column - The column to be grabbed
     * Post: If column is not in the proper range, then an invalid_argument is thrown
     * Return: The specified column in Vector form
     */
    virtual const Vector<T> getColumn(const int column) const = 0;

    /*
     * Purpose: Inspection/Change Operator
     * Pre: row must be in the range [0, numRows())
     *      column must be in the range [0, numColumns())
     * Param: row - The row of the element
     *        column - The column of the element
     * Post: The element is returned by reference, so it may be changed externally
     *       If the row or column is invalid, an invalid_argument will be thrown
     * Return: The element at index [row][column]
     */
    virtual T& operator()(const int row, const int column) = 0;

    /*
     * Purpose: Inspection/Change Operator
     * Pre: row must be in the range [0, numRows())
     *      column must be in the range [0, numColumns())
     * Param: row - The row of the element
     *        column - The column of the element
     * Post: The element is returned by reference, so it may be changed externally
     *       If the row or column is invalid, an invalid_argument will be thrown
     * Return: The element at index [row][column]
     */
    virtual const T& operator()(const int row, const int column) const = 0;

    /*
     * Purpose: Clone function
     * Pre: None
     * Param: None
     * Post: None
     * Return: A pointer to a clone of the calling object
     */
    virtual AbstractMatrix<T>* clone() const = 0;

    /*
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: Object is deleted
     * Return: None
     */
    virtual ~AbstractMatrix() {}

    //Friends
    /*
     * Purpose: Output operator
     * Pre: Parameter out must be connected to a stream
     *      Template type T must have operator<<(ostream, T) defined
     * Param: out - The stream to output to
     *        rhs - The Matrix to be output
     * Post: out will have the contents of rhs output to it
     * Return: Parameter out
     */
    friend ostream& operator<< <>(ostream& out, const AbstractMatrix<T>& rhs);
};
#include "AbstractMatrix.hpp"
#endif
