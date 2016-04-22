/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: DenseMatrix.h
 * Description: Header for DenseMatrix class
 *
 */

#ifndef DenseMatrix_H
#define DenseMatrix_H
#include <iostream>
#include "Vector.h"

using std::ostream;
using std::istream;
template<class T>
class DenseMatrix;

template <class T>
istream& operator>> (istream& in, DenseMatrix<T>& rhs);

template <class T>
DenseMatrix<T> operator+ (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
DenseMatrix<T> operator- (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
DenseMatrix<T> operator- (const DenseMatrix<T>& rhs);

template <class T>
DenseMatrix<T> operator* (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
Vector<T> operator* (const DenseMatrix<T>& lhs, const Vector<T>& rhs);

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
T operator* (const T& lhs, const DenseMatrix<T>& rhs);

template <class T>
T operator* (const DenseMatrix<T>& lhs, const T& rhs);

template <class T>
bool operator== (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
bool operator!= (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

template <class T>
void swap (DenseMatrix<T>& x, DenseMatrix<T>& y);

const int DEFAULT_ROWS = 5, DEFAULT_COLUMNS = 5;

template <class T>
class DenseMatrix : public AbstractMatrix<T>
{
  public:
    /**
     * Purpose: Default Constructor
     * Pre: None
     * Param: None
     * Post: The object is initialized to a DenseMatrix of DEFAULT_ROWS x DEFAULT_COLUMNS
     * Return: None
     */
    DenseMatrix ();

    /**
     * Purpose: Parameterized Constructor
     * Pre: None
     * Param: r - The number of rows in the DenseMatrix
     *        c - The number of columns in the DenseMatrix
     * Post: If r or c are zero or below, an invalid_argument exception will be thrown
     *       The object is initialized to a DenseMatrix of r x c
     * Return: None
     */
    DenseMatrix (int r, int c);

    /**
     * Purpose: Copy Constructor
     * Pre: Template type T must have operator= (T, T) defined
     * Param: src - The object to be copied from
     * Post: The calling object is a deep copy of the parameter src
     * Return: None
     */
    DenseMatrix (const DenseMatrix<T>& src);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: src - The temporary object to be "moved" from
     * Post: The calling object "steals" the pointer of src and sets it to NULL
     * Return: None
     */
    DenseMatrix (DenseMatrix<T>&& src);

    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: The object is destructed
     * Return: None
     */
    ~DenseMatrix ();

    /**
     * Purpose: Get a specified column in the DenseMatrix
     * Pre: Parameter x must be in the range [0, columns)
     * Param: x - The index of the column to be grabbed
     * Post: If x is not in the range [0, columns), then an out_of_range exception is thrown
     * Return: The column at the specified index
     */
    virtual const Vector<T> getColumn(const int column) const;

    /**
     * Purpose: Peek index operator
     * Pre: Parameter x must be in the range [0, rows)
     * Param: x - The index of the row to be grabbed
     * Post: If x is not in the range [0, rows), then an out_of_range exception is thrown
     * Return: A const reference to the row indexed at x
     */
    const Vector<T>& operator[] (int x) const;

    /**
     * Purpose: Modify index operator
     * Pre: Parameter x must be in the range [0, rows)
     * Param: x - The index of the row to be grabbed
     * Post: If x is not in the range [0, rows), then an out_of_range exception is thrown
     *       The row indexed at x is returned by reference, so it's able to be modified
     * Return: A reference to the row indexed at x
     */
    Vector<T>& operator[] (int x);

    /**
     * Purpose: Assignment Operator
     * Pre: None
     * Param: rhs - The DenseMatrix to set the calling object equal to
     * Post: The calling object is set equal to the the parameter rhs
     * Return: The calling object
     */
    DenseMatrix<T>& operator= (DenseMatrix<T> rhs);

    /**
     * Purpose: Addition-assignment Operator
     * Pre: Template type T must have operator+=(T, T) defined
     * Param: rhs - The object to be added and assigned
     * Post: The calling object is assigned to itself plus the parameter rhs
     * Return: The calling object
     */
    DenseMatrix<T>& operator+= (const DenseMatrix<T>& rhs);

    /**
     * Purpose: Subtraction-assignment operator
     * Pre: Template type T must have operator-(T) defined
     *      Template type T must have operator=(T, T) defined
     * Param: rhs - The object to be subtracted and assigned
     * Post: The calling object is assigned to itself minus the parameter rhs
     * Return: The calling object
     */
    DenseMatrix<T>& operator-= (const DenseMatrix<T>& rhs);

    /**
     * Purpose: Get the number of rows in the DenseMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows in the DenseMatrix
     */
    virtual int numRows() const;

    /**
     * Purpose: Get the number of columns in the DenseMatrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns in the DenseMatrix
     */
    virtual int numColumns() const;
    
    //Friends

    /**
     * Purpose: DenseMatrix output function
     * Pre: ostream out must be connected to a stream
     *      Template type T must have operator<<(ostream, T) defined
     * Param: out - The ostream to output the DenseMatrix to
     * Post: The parameter out will have rhs inserted in to it
     * Return: Parameter out
     */
    //virtual ostream& output(ostream& out) const;

    virtual T& operator()(const int row, const int column);
    virtual const T& operator()(const int row, const int column) const;
    virtual AbstractMatrix<T>* clone() const;
    /**
     * Purpose: DenseMatrix extraction operator
     * Pre: istream in must be connected to a stream
     *      Template type T must have operator>>(istream, T) defined
     * Param: in - The istream to read in to the DenseMatrix
     *        rhs - The DenseMatrix to be read in to
     * Post: The parameter in will have rhs read out of it
     *       The parameter rhs will be populated
     * Return: Parameter in
     */
    friend istream& operator>> <>(istream& in, DenseMatrix<T>& rhs);

    /**
     * Purpose: Operator+ - Add two Matrices
     * Pre: Parameter lhs and rhs must be of the same dimensions
     *      Template type T must have operator+=(T) defined
     * Param: lhs - One of the Matrices to be added
     *        rhs - One of the Matrices to be added
     * Post: If lhs and rhs do not have the same dimensions, a length_error exception will be thrown
     * Return: The element-wise sum of the two matrices
     */
    friend DenseMatrix<T> operator+ <>(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

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
    friend DenseMatrix<T> operator- <>(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix negation operator
     * Pre: Template type T must have operator=(T) defined
     *      Template type T must have operator-() defined
     * Param: rhs - The DenseMatrix to be negated
     * Post: None
     * Return: The negative of rhs
     */
    friend DenseMatrix<T> operator- <>(const DenseMatrix<T>& rhs);

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
    friend DenseMatrix<T> operator* <>(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix - Vector multiplication
     * Pre: DenseMatrix must have same number of columns as Vector has elements
     * Param: lhs - The DenseMatrix to be multiplied
     *        rhs - The Vector to be multiplied
     * Post: If the DenseMatrix and Vector are of differing dimensions, a length_error exception will be thrown
     * Return: The DenseMatrix - Vector product
     */
    friend Vector<T> operator* <>(const DenseMatrix<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: DenseMatrix - Vector multiplication
     * Pre: DenseMatrix must have same number of rows as Vector has elements
     * Param: rhs - The DenseMatrix to be multiplied
     *        lhs - The Vector to be multiplied
     * Post: If the DenseMatrix and Vector are of differing dimensions, a length_error exception will be thrown
     * Return: The Vecotr - DenseMatrix product
     */
    friend Vector<T> operator* <>(const Vector<T>& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: Scalar - DenseMatrix multiplication
     * Pre: Template type T must have operator* (T, T) defined
     * Param: lhs - The scalar to be multiplied to the DenseMatrix
     *        rhs - The DenseMatrix to be multiplied in to
     * Post: None
     * Return: The parameter lhs
     */
    friend T operator* <>(const T& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: Scalar - DenseMatrix multiplication
     * Pre: Template type T must have operator* (T, T) defined
     * Param: rhs - The scalar to be multiplied to the DenseMatrix
     *        lhs - The DenseMatrix to be multiplied in to
     * Post: None
     * Return: The parameter rhs
     */
    friend T operator* <>(const DenseMatrix<T>& lhs, const T& rhs);

    /**
     * Purpose: DenseMatrix - DenseMatrix equality operator
     * Pre: None
     * Param: lhs - A DenseMatrix to be compared
     *        rhs - A DenseMatrix to be compared
     * Post: None
     * Return: True if they're equal, false otherwise
     */
    friend bool operator== <>(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix - DenseMatrix equality operator
     * Pre: None
     * Param: lhs - A DenseMatrix to be compared
     *        rhs - A DenseMatrix to be compared
     * Post: None
     * Return: True if they're not equal, false otherwise
     */
    friend bool operator!= <>(const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs);

    /**
     * Purpose: DenseMatrix swap function
     * Pre: None
     * Param: x - An element to be swapped
     *        y - An element to be swapped
     * Post: x will be equal to y and y will be equal to x
     * Return: None
     */
    friend void swap <>(DenseMatrix<T>& x, DenseMatrix<T>& y);

  private:
    int rows;
    int columns;
    Vector<T>* data;
    DenseMatrix<T> elim(DenseMatrix<T> augmented, bool pivoting) const;
};
#include "DenseMatrix.hpp"
#endif
