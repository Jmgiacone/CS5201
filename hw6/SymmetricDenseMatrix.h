/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: SymmetricDenseMatrix.h
 * Description: This is the header for the SymmetricDenseMatrix class
 */
#ifndef SYMMETRICDENSEMATRIX_H
#define SYMMETRICDENSEMATRIX_H
#include "AbstractMatrix.h"
template <class T>
class SymmetricDenseMatrix;

template <class T>
SymmetricDenseMatrix<T> operator+ (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);

template <class T>
SymmetricDenseMatrix<T> operator- (const SymmetricDenseMatrix<T>& rhs);

template <class T>
SymmetricDenseMatrix<T> operator- (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);

static const int DEFAULT_DIMENSIONS = 2;
template <class T>
class SymmetricDenseMatrix : public AbstractMatrix<T>
{
  private:
    int dimensions;
    Vector<T>* data;
  public:

    /**
     * Purpose: Default Constructor
     * Pre: None
     * Param: None
     * Post: The object is initialized to aSymmetricDenseMatrix of DEFAULT_ROWS x DEFAULT_COLUMNS
     * Return: None
     */
    SymmetricDenseMatrix() : SymmetricDenseMatrix(DEFAULT_DIMENSIONS){}

    /**
     * Purpose: Parameterized Constructor
     * Pre: None
     * Param: d - The dimension of theSymmetricDenseMatrix
     * Post: If r or c are zero or below, an invalid_argument exception will be thrown
     *       The object is initialized to aSymmetricDenseMatrix of d x d
     * Return: None
     */
    SymmetricDenseMatrix(const int d);

    /**
     * Purpose: Copy Constructor
     * Pre: Template type T must have operator= (T, T) defined
     * Param: src - The object to be copied from
     * Post: The calling object is a deep copy of the parameter src
     * Return: None
     */
    SymmetricDenseMatrix(const SymmetricDenseMatrix<T>& src);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: src - The temporary object to be "moved" from
     * Post: The calling object "steals" the pointer of src and sets it to NULL
     * Return: None
     */
    SymmetricDenseMatrix(SymmetricDenseMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}


    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: The object is destructed
     * Return: None
     */
    ~SymmetricDenseMatrix();

    /**
     * Purpose: Get the number of rows in theSymmetricDenseMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows in theSymmetricDenseMatrix
     */
    virtual int numRows() const {return dimensions;}

    /**
     * Purpose: Get the number of columns in theSymmetricDenseMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns in theSymmetricDenseMatrix
     */
    virtual int numColumns() const {return dimensions;}

    /**
     * Purpose: Assignment Operator
     * Pre: None
     * Param: rhs - TheSymmetricDenseMatrix to set the calling object equal to
     * Post: The calling object is set equal to the the parameter rhs
     * Return: The calling object
     */
    virtual SymmetricDenseMatrix<T>& operator= (SymmetricDenseMatrix<T> rhs);

    /**
     * Purpose: Addition-assignment Operator
     * Pre: Template type T must have operator+=(T, T) defined
     * Param: rhs - The object to be added and assigned
     * Post: The calling object is assigned to itself plus the parameter rhs
     * Return: The calling object
     */
    SymmetricDenseMatrix<T>& operator+= (const SymmetricDenseMatrix<T>& rhs);

    /**
     * Purpose: Subtraction-assignment operator
     * Pre: Template type T must have operator-(T) defined
     *      Template type T must have operator=(T, T) defined
     * Param: rhs - The object to be subtracted and assigned
     * Post: The calling object is assigned to itself minus the parameter rhs
     * Return: The calling object
     */
    SymmetricDenseMatrix<T>& operator-= (const SymmetricDenseMatrix<T>& rhs);

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
    virtual T& operator() (const int row, const int column);

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
    virtual const T& operator() (const int row, const int column) const;

    /*
     * Purpose: Clone function
     * Pre: None
     * Param: None
     * Post: None
     * Return: A pointer to a clone of the calling object
     */
    virtual AbstractMatrix<T>* clone() const;

    /**
     * Purpose:SymmetricDenseMatrix swap function
     * Pre: None
     * Param: x - An element to be swapped
     *        y - An element to be swapped
     * Post: x will be equal to y and y will be equal to x
     * Return: None
     */
    void swap(SymmetricDenseMatrix<T>& lhs, SymmetricDenseMatrix<T>& rhs);

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
    friend SymmetricDenseMatrix<T> operator+ <>(const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);

     /**
      * Purpose:SymmetricDenseMatrix negation operator
      * Pre: Template type T must have operator=(T) defined
      *      Template type T must have operator-() defined
      * Param: rhs - TheSymmetricDenseMatrix to be negated
      * Post: None
      * Return: The negative of rhs
      */
    friend SymmetricDenseMatrix<T> operator- <>(const SymmetricDenseMatrix<T>& rhs);

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
    friend SymmetricDenseMatrix<T> operator- <>(const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs);
};
#include "SymmetricDenseMatrix.hpp"
#endif
