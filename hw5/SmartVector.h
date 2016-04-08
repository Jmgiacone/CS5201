/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: SmartVector.h
 * Description: This is the header file for the Smart Vector class
 */

#ifndef SMARTVECTOR_H
#define SMARTVECTOR_H
template <class T>
class SmartVector
{
  //Had to include this
  T zero = 0;
  private:
    int terms;
    T** data;

  public:
    /**
     * Purpose: Constructor
     * Pre: None
     * Param: size - The size of the Array
     *        d - The T** representation of the array
     * Post: The object is constructed
     * Return: None
     */
    SmartVector(int size, T** d);

    /**
     * Purpose: Copy constructor
     * Pre: None
     * Param: src - The SmartVector to be copied
     * Post: The calling object is now a copy of src
     * Return: None
     */
    SmartVector(const SmartVector<T>& src);

    /**
     * Purpose: Move constructor
     * Pre: None
     * Param: src - The SmartVector to be copied
     * Post: src has its data pointer "stolen" and set to NULL
     * Return: None
     */
    SmartVector(SmartVector<T>&& src) : terms(src.terms), data(src.data) {src.data = NULL;}

    /**
     * Purpose: Operator[] - Peeking
     * Pre: x must be in the interval [0, size)
     * Param: x - The element to be grabbed
     * Post: If x is not in the interval [0, size), an invalid_argument exception is thrown
     * Return: The element at x
     */
    const T& operator[] (int x) const;

    /**
     * Purpose: Returns how long the SmartVector is
     * Pre: None
     * Param: None
     * Post: None
     * Return: The length is returned
     */
    int numTerms() const {return terms;};
};
#include "SmartVector.hpp"
#endif
