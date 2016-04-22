/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: DiagonaltMatrix.h
 * Description: This is the header for the DiagonalMatrix class
 */
#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H
#include "AbstractMatrix.h"

template <class T>
class DiagonalMatrix;

template <class T>
DiagonalMatrix<T> operator+ (const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);

template <class T>
DiagonalMatrix<T> operator- (const DiagonalMatrix<T>& rhs);

template <class T>
DiagonalMatrix<T> operator- (const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);

template <class T>
DiagonalMatrix<T> operator* (const DiagonalMatrix<T>& lhs, DiagonalMatrix<T>& rhs);
template <class T>
class DiagonalMatrix : public AbstractMatrix<T>
{
  private:
    int dimensions;
    Vector<T> data;
    T zero = 0;
  public:

    /**
     * Purpose: Default Constructor
     * Pre: None
     * Param: None
     * Post: The object is initialized to a DiagonalMatrix of DEFAULT_ROWS x DEFAULT_COLUMNS
     * Return: None
     */
    DiagonalMatrix() : DiagonalMatrix(DEFAULT_DIMENSIONS) {};

    /**
     * Purpose: Parameterized Constructor
     * Pre: None
     * Param: d - The dimensions of the DiagonalMatrix
     * Post: If d is zero or below, an invalid_argument exception will be thrown
     *       The object is initialized to a DiagonalMatrix of r x c
     * Return: None
     */
    DiagonalMatrix(int d);


    /**
     * Purpose: Copy Constructor
     * Pre: Template type T must have operator= (T, T) defined
     * Param: src - The object to be copied from
     * Post: The calling object is a deep copy of the parameter src
     * Return: None
     */
    DiagonalMatrix(const DiagonalMatrix<T>& src);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: src - The temporary object to be "moved" from
     * Post: The calling object "steals" the pointer of src and sets it to NULL
     * Return: None
     */
    DiagonalMatrix(DiagonalMatrix<T>&& src) : dimensions(src.dimensions), data(std::move(src.data)) {}

    /*
     * Purpose: Operator+=
     * Pre: rhs must have same dimensions as the calling object
     * Param: rhs - The DiagonalMatrix to be added
     * Post: The calling object is equal to the sum of *this and rhs
     *       If the matrices differ in size, an invalid_argument exception is thrown
     * Return: *this
     */
    DiagonalMatrix<T>& operator+= (const DiagonalMatrix<T>& rhs);

  /*
   * Purpose: Operator-=
   * Pre: rhs must have same dimensions as the calling object
   * Param: rhs - The DiagonalMatrix to be subtracted
   * Post: The calling object is equal to the difference of *this and rhs
   *       If the matrices differ in size, an invalid_argument exception is thrown
   * Return: *this
   */
    DiagonalMatrix<T>& operator-= (const DiagonalMatrix<T>& rhs);

    /**
     * Purpose: Get the number of rows in the DiagonalMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows in the DiagonalMatrix
     */
    virtual int numRows() const {return dimensions;}
  
    /**
     * Purpose: Get the number of columns in the DiagonalMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns in the DiagonalMatrix
     */
    virtual int numColumns() const {return dimensions;}

    /**
     * Purpose: Get a specified column in the DiagonalMatrix
     * Pre: Parameter x must be in the range [0, columns)
     * Param: x - The index of the column to be grabbed
     * Post: If x is not in the range [0, columns), then an out_of_range exception is thrown
     * Return: The column at the specified index
     */
    virtual const Vector<T> getColumn(const int column) const;

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
     * Purpose: Clone function
     * Pre: None
     * Param: None
     * Post: None
     * Return: A pointer to a clone of the calling object
     */
    virtual AbstractMatrix<T>* clone() const;

    //Friends

    /**
     * Purpose: Operator+
     * Pre: lhs and rhs have the same size
     * Param: lhs - A matrix to be added
     *        rhs - A matrix to be added
     * Post: If lhs and rhs are different sizes, an invalid_argument is thrown
     * Return: The sum of lhs and rhs
     */
    friend DiagonalMatrix<T> operator+ <>(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);

    /*
     * Purpose: Negation Operator
     * Pre: Template type T must have operator-() defined
     * Param: rhs - The matrix to be negated
     * Post: None
     * Return: The negation of rhs
     */
    friend DiagonalMatrix<T> operator- <>(const DiagonalMatrix<T>& rhs);

    /**
     * Purpose: Operator+
     * Pre: lhs and rhs have the same size
     * Param: lhs - A matrix to be subtracted from
     *        rhs - A matrix to be subtracted
     * Post: If lhs and rhs are different sizes, an invalid_argument is thrown
     * Return: The difference of lhs and rhs
     */
    friend DiagonalMatrix<T> operator- <>(const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs);

    /*
     * Purpose: Matrix Multiplication operator
     * Pre: lhs and rhs have same dimension
     *      Template type T has operator* (T, T) defined
     * Param: lhs - A matrix to be multiplied
     *        rhs - A matrix to be multiplied
     * Post: If rhs and lhs are of differing size, an invalid_argument exception is thrown
     * Return: The product of lhs and rhs
     */
    friend DiagonalMatrix<T> operator* <>(const DiagonalMatrix<T>& lhs, DiagonalMatrix<T>& rhs);
};
#include "DiagonalMatrix.hpp"
#endif
