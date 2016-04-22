/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: UpperTriangularMatrix.h
 * Description: This is the header for the UpperTriangularMatrix class
 */
#ifndef UPPERTRIAGONALMATRIX_H
#define UPPERTRIAGONALMATRIX_H
#include "AbstractMatrix.h"
template <class T>
class UpperTriangularMatrix;

template <class T>
UpperTriangularMatrix<T> operator+ (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

template <class T>
UpperTriangularMatrix<T> operator- (const UpperTriangularMatrix<T>& rhs);

template <class T>
UpperTriangularMatrix<T> operator- (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

template <class T>
void swap(UpperTriangularMatrix<T>& x, UpperTriangularMatrix<T>& y);

template <class T>
DenseMatrix<T> operator* (const UpperTriangularMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
UpperTriangularMatrix<T> operator* (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

template <class T>
class UpperTriangularMatrix : public AbstractMatrix<T>
{
   private:
    int dimensions;
    Vector<T>* data;
    T zero = 0;

  public:
   /**
    * Purpose: Default Constructor
    * Pre: None
    * Param: None
    * Post: The object is initialized to a DenseMatrix of DEFAULT_ROWS x DEFAULT_COLUMNS
    * Return: None
    */
    UpperTriangularMatrix() : UpperTriangularMatrix(DEFAULT_TERMS) {}

    /**
     * Purpose: Parameterized Constructor
     * Pre: None
     * Param: r - The number of rows in the DenseMatrix
     *        c - The number of columns in the DenseMatrix
     * Post: If r or c are zero or below, an invalid_argument exception will be thrown
     *       The object is initialized to a DenseMatrix of r x c
     * Return: None
     */
    UpperTriangularMatrix(const int d);

   /**
    * Purpose: Copy Constructor
    * Pre: Template type T must have operator= (T, T) defined
    * Param: src - The object to be copied from
    * Post: The calling object is a deep copy of the parameter src
    * Return: None
    */
    UpperTriangularMatrix(const UpperTriangularMatrix<T>& src);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: src - The temporary object to be "moved" from
     * Post: The calling object "steals" the pointer of src and sets it to NULL
     * Return: None
     */
    UpperTriangularMatrix(UpperTriangularMatrix<T>&& src) : dimensions(src.dimensions), data(src.data) {src.data = NULL;}

    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: The object is destructed
     * Return: None
     */
    ~UpperTriangularMatrix();

    /**
     * Purpose: Assignment Operator
     * Pre: None
     * Param: rhs - The DenseMatrix to set the calling object equal to
     * Post: The calling object is set equal to the the parameter rhs
     * Return: The calling object
     */
    UpperTriangularMatrix<T>& operator= (UpperTriangularMatrix<T> rhs);

    /**
     * Purpose: Addition-assignment Operator
     * Pre: Template type T must have operator+=(T, T) defined
     * Param: rhs - The object to be added and assigned
     * Post: The calling object is assigned to itself plus the parameter rhs
     * Return: The calling object
     */
    UpperTriangularMatrix<T>& operator+= (const UpperTriangularMatrix<T>& rhs);

    /**
     * Purpose: Subtraction-assignment operator
     * Pre: Template type T must have operator-(T) defined
     *      Template type T must have operator=(T, T) defined
     * Param: rhs - The object to be subtracted and assigned
     * Post: The calling object is assigned to itself minus the parameter rhs
     * Return: The calling object
     */
    UpperTriangularMatrix<T>& operator-= (const UpperTriangularMatrix<T>& rhs);

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

    /**
     * Purpose: Get a specified column in the DenseMatrix
     * Pre: Parameter x must be in the range [0, columns)
     * Param: x - The index of the column to be grabbed
     * Post: If x is not in the range [0, columns), then an out_of_range exception is thrown
     * Return: The column at the specified index
     */
    virtual const Vector<T> getColumn(int column) const;

    /**
     * Purpose: Get the number of rows in the DenseMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows in the DenseMatrix
     */
    virtual int numColumns() const {return dimensions;}

    /**
     * Purpose: Get the number of columns in the DenseMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns in the DenseMatrix
     */
    virtual int numRows() const {return dimensions;}

    //Friends

    /*
     * Purpose: UTM - DM multiplication
     * Pre: lhs and rhs must be of same size
     * Param: lhs - The left-side of the multiplication
     *        rhs - The right-side of the multiplication
     * Post: If lhs and rhs differ in size, an invalid_argument exception will be thrown
     * Return: The product of lhs and rhs
     */
    friend DenseMatrix<T> operator* <>(const UpperTriangularMatrix<T>& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix - DenseMatrix multiplication
     * Pre: Middle dimensions must match (lhs.columns == rhs.rows)
     *      Template type T must have operator=(T) defined
     *      Template type T must have operator*(T, T) defined
     * Param: lhs - The left-hand-side DenseMatrix
     *        rhs - The right-hand-side DenseMatrix
     * Post: If the middle dimensions don't match, a length_error exception will be thrown
     * Return: A product DenseMatrix of size lhs.rows x rhs.columns
     */
    friend UpperTriangularMatrix<T> operator* <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

    /**
     * Purpose: Operator+ - Add two Matrices
     * Pre: Parameter lhs and rhs must be of the same dimensions
     *      Template type T must have operator+=(T) defined
     * Param: lhs - One of the Matrices to be added
     *        rhs - One of the Matrices to be added
     * Post: If lhs and rhs do not have the same dimensions, a length_error exception will be thrown
     * Return: The element-wise sum of the two matrices
     */
    friend UpperTriangularMatrix<T> operator+ <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix negation operator
     * Pre: Template type T must have operator=(T) defined
     *      Template type T must have operator-() defined
     * Param: rhs - The DenseMatrix to be negated
     * Post: None
     * Return: The negative of rhs
     */
    friend UpperTriangularMatrix<T> operator- <>(const UpperTriangularMatrix<T>& rhs);

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
    friend UpperTriangularMatrix<T> operator- <>(const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix swap function
     * Pre: None
     * Param: x - An element to be swapped
     *        y - An element to be swapped
     * Post: x will be equal to y and y will be equal to x
     * Return: None
     */
    friend void swap <>(UpperTriangularMatrix<T>& x, UpperTriangularMatrix<T>& y);
  

};
#include "UpperTriangularMatrix.hpp"
#endif