/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: LowerTriangularMatrix.h
 * Description: This is the header for the LowerTriangularMatrix class
 */

#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "AbstractMatrix.h"
template <class T>
class LowerTriangularMatrix;

template <class T>
LowerTriangularMatrix<T> operator+ (const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

template <class T>
LowerTriangularMatrix<T> operator- (const LowerTriangularMatrix<T>& rhs);

template <class T>
LowerTriangularMatrix<T> operator- (const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

template <class T>
void swap(LowerTriangularMatrix<T>& x, LowerTriangularMatrix<T>& y);

template <class T>
class LowerTriangularMatrix : public AbstractMatrix<T>
{
  private:
    static T zero = 0;
    int dimensions;
    Vector<T>* data;

  public:
    /**
     * Purpose: Default Constructor
     * Pre: None
     * Param: None
     * Post: The object is initialized to a UpperTriangularMatrix of DEFAULT_ROWS x DEFAULT_COLUMNS
     * Return: None
     */
    LowerTriangularMatrix() : LowerTriangularMatrix(DEFAULT_TERMS) {}

    /**
     * Purpose: Parameterized Constructor
     * Pre: None
     * Param: d - The dimension of the UpperTriangularMatrix
     * Post: If d is zero or below, an invalid_argument exception will be thrown
     *       The object is initialized to a UpperTriangularMatrix of d x d
     * Return: None
     */
    LowerTriangularMatrix(const int d);

    /**
     * Purpose: Copy Constructor
     * Pre: Template type T must have operator= (T, T) defined
     * Param: src - The object to be copied from
     * Post: The calling object is a deep copy of the parameter src
     * Return: None
     */
    LowerTriangularMatrix(const LowerTriangularMatrix<T>& src);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: src - The temporary object to be "moved" from
     * Post: The calling object "steals" the pointer of src and sets it to NULL
     * Return: None
     */
    LowerTriangularMatrix(LowerTriangularMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}

    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: The object is destructed
     * Return: None
     */
    ~LowerTriangularMatrix();

    /**
     * Purpose: Assignment Operator
     * Pre: None
     * Param: rhs - The UpperTriangularMatrix to set the calling object equal to
     * Post: The calling object is set equal to the the parameter rhs
     * Return: The calling object
     */
    LowerTriangularMatrix<T>& operator= (LowerTriangularMatrix<T> rhs);

   /**
    * Purpose: Addition-assignment Operator
    * Pre: Template type T must have operator+=(T, T) defined
    * Param: rhs - The object to be added and assigned
    * Post: The calling object is assigned to itself plus the parameter rhs
    * Return: The calling object
    */
    LowerTriangularMatrix<T>& operator+= (const LowerTriangularMatrix<T>& rhs);

    /**
     * Purpose: Subtraction-assignment operator
     * Pre: Template type T must have operator-(T) defined
     *      Template type T must have operator=(T, T) defined
     * Param: rhs - The object to be subtracted and assigned
     * Post: The calling object is assigned to itself minus the parameter rhs
     * Return: The calling object
     */
    LowerTriangularMatrix<T>& operator-= (const LowerTriangularMatrix<T>& rhs);

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
    virtual const T& operator()(const int row, const int column) const;

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
    virtual T& operator()(const int row, const int column);

    /*
     * Purpose: Clone function
     * Pre: None
     * Param: None
     * Post: None
     * Return: A pointer to a clone of the calling object
     */
    virtual AbstractMatrix<T>* clone() const;

    //Friends

    /**
     * Purpose: Operator+ - Add two Matrices
     * Pre: Parameter lhs and rhs must be of the same dimensions
     *      Template type T must have operator+=(T) defined
     * Param: lhs - One of the Matrices to be added
     *        rhs - One of the Matrices to be added
     * Post: If lhs and rhs do not have the same dimensions, a length_error exception will be thrown
     * Return: The element-wise sum of the two matrices
     */
    friend LowerTriangularMatrix<T> operator+ <>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix negation operator
     * Pre: Template type T must have operator=(T) defined
     *      Template type T must have operator-() defined
     * Param: rhs - The DenseMatrix to be negated
     * Post: None
     * Return: The negative of rhs
     */
    friend LowerTriangularMatrix<T> operator- <>(const LowerTriangularMatrix<T>& rhs);

     /**
      * Purpose: Operator- - Subtract rhs from lhs
      * Pre: Parameters lhs and rhs must be of the same dimensions
      *      Template type T must have operator=(T) defined
      *      Template type T must have operator-() defined
      * Param: lhs - The left-hand-side of the difference
      *        rhs - The right-hand-side of the difference
      * Post: If lhs and rhs do not have the same dimensions, a length_error exception will be thrown
      * Return: The element-wise difference of lhs and rhs
      */
    friend LowerTriangularMatrix<T> operator- <>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix swap function
     * Pre: None
     * Param: x - An element to be swapped
     *        y - An element to be swapped
     * Post: x will be equal to y and y will be equal to x
     * Return: None
     */
    friend void swap <>(LowerTriangularMatrix<T>& x, LowerTriangularMatrix<T>& y);
};
#include "LowerTriangularMatrix.hpp"
#endif
