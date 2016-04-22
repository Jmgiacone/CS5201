/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: TriDiagonalMatrix.h
 * Description: This is the derived class from AbstractMatrix
 */

#ifndef TRIDIAGONALMATRIX_H
#define TRIDIAGONALMATRIX_H
#include "DenseMatrix.h"
#include "AbstractMatrix.h"

template <class T>
class TriDiagonalMatrix;

template <class T>
const TriDiagonalMatrix<T> operator+ (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const TriDiagonalMatrix<T> operator- (const TriDiagonalMatrix<T>& rhs);

template <class T>
const TriDiagonalMatrix<T> operator- (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const DenseMatrix<T> operator* (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
const Vector<T> operator* (const TriDiagonalMatrix<T>& lhs, const Vector<T>& rhs);

template <class T>
bool operator== (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

template <class T>
bool operator!= (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

const int NUM_DIAGONALS = 3;
template <class T>
class TriDiagonalMatrix : public AbstractMatrix<T>
{
  private:
    Vector<T>* data;
    int rows, columns;
    T zero = 0;
  public:
    /**
     * Purpose: Default constructor
     * Pre: None
     * Param: None
     * Post: The object is constructed
     * Return: none
     */
    TriDiagonalMatrix() : TriDiagonalMatrix(DEFAULT_ROWS, DEFAULT_COLUMNS) {}

    /**
     * Purpose: Parameterized Constructor - initializes with rows and columns
     * Pre: None
     * Param: r - The number of desired rows in the TDM
     *        c - The number of desired columns in the TDM
     * Post: The object is constructed
     * Return: None
     */
    TriDiagonalMatrix(int r, int c);

    /**
     * Purpose: Parameterized Constructor - Initializes with rows, columns, and the 3 diagonals
     * Pre: None
     * Param: r - The number of desired rows in the TDM
     *        c - The number of desired columns in the TDM
     *        diag1 - The first diagonal in the TDM
     *        diag2 - The second diagonal in the TDM
     *        diag3 - The third diagonal in the tdm
     * Post: If the term layout for the diagonals isn't (rows-1, rows, rows-1), then an invalid_argument exception
     *       will be thrown
     * Return: None
     */
    TriDiagonalMatrix(int r, int c, const Vector<T>& diag1, const Vector<T>& diag2, const Vector<T>& diag3);

    /**
     * Purpose: Copy Constructor
     * Pre: None
     * Param: rhs - The object to be copied
     * Post: The calling object reflects the state of rhs
     * Return: None
     */
    TriDiagonalMatrix(const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: rhs - The object to be copied
     * Post: rhs has its pointer "stolen" by the calling object
     * Return: None
     */
    TriDiagonalMatrix(TriDiagonalMatrix<T>&& rhs) : rows(rhs.rows), columns(rhs.columns),
                                                    data(rhs.data) {rhs.data = NULL;}

    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: Object is destructed
     * Return: None
     */
    ~TriDiagonalMatrix();

    /**
     * Purpose: Assignment operator
     * Pre: None
     * Param: rhs - The Matrix to be assigned to the calling object
     * Post: The calling object has identical state to parameter rhs
     * Return: The calling object
     */
    TriDiagonalMatrix<T>& operator= (TriDiagonalMatrix<T> rhs);

    /**
     * Purpose: Swap Function - To swap the state of two TDMs
     * Pre: None
     * Param: x - A TDM to be swapped
     *        y - A TDM to be swapped
     * Post: The two TDM will have effectively swapped states
     * Return: None
     */
    void swap(TriDiagonalMatrix<T>& x, TriDiagonalMatrix<T>& y);

    /**
     * Purpose: Operator += - Adds the parameter rhs and then sets the calling object
     * Pre: parameter rhs must have the same rows and columns as the calling object
     * Param: rhs - The TDM to be added in
     * Post: If the parameter rhs has a different dimension from the calling objec, an
     *       invalid_argument exception is thrown
     *       The calling object is set to the sum of the two
     * Return: The calling object
     */
    TriDiagonalMatrix<T>& operator+= (const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose: Operator -= - Subtracts the parameter rhs and sets calling object      * Pre:
     * Pre: rhs must have the same dimensions as the calling object
     * Param: rhs - The TDM to be subtracted
     * Post: If the calling object and rhs have different dimensions, an invalid_argument is thrown
     *       The calling object is set to the difference of the two TDMs
     * Return: The calling object
     */
    TriDiagonalMatrix<T>& operator-= (const TriDiagonalMatrix<T>& rhs);



    //AbstractMatrix interface functions
    /**
     * Purpose: Returns the number of rows in the TDM
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows
     */
    virtual int numRows() const {return rows;}

    /**
     * Purpose: Returns the number of columns in the TDM
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns
     */
    virtual int numColumns() const {return columns;}

    Vector<T> getRow(int row) const;
    virtual const Vector<T> getColumn(const int column) const;

    virtual T& operator()(const int row, const int column);

    virtual const T& operator()(const int row, const int column) const;

    virtual AbstractMatrix<T>* clone() const;
    //Friend functions

    /**
     * Purpose: Operator + - Adds two TDMs together
     * Pre: lhs and rhs must have the same dimensions
     * Param: lhs - A TDM to be added
     *        rhs - A TDM to be added
     * Post: If lhs and rhs are of differing dimensions, an invalid_argument exception is thrown
     * Return: The sum of the two TDMs
     */
    friend const TriDiagonalMatrix<T> operator+ <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose: Operator- - Negates a TDM
     * Pre: None
     * Param: rhs - The TDM to be negated
     * Post: None
     * Return: The negated version of rhs
     */
    friend const TriDiagonalMatrix<T> operator- <>(const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose: Operator- Subtract two TDMs from each other
     * Pre: lhs and rhs must be of the same dimension
     * Param: lhs - A TDM to be subtracted
     *        rhs - A TDM to be subtracted
     * Post: If lhs and rhs are of different size, an invalid_argument exception is thrown
     * Return:
     */
    friend const TriDiagonalMatrix<T> operator- <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose:
     * Pre:
     * Param:
     * Post:
     * Return:
     */
    friend const DenseMatrix<T> operator* <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose: Operator* - Matrix-Vector Multiplication
     * Pre: lhs must have the same number of columns as rhs has terms
     * Param: lhs - The Matrix to be multiplied
     *        rhs - The Vector to be multiplied
     * Post: If lhs and rhs are of differing size, an invalid_argument excpetion is thrown
     * Return: The product of lhs and rhs
     */
    friend const Vector<T> operator* <>(const TriDiagonalMatrix<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: Equality operator
     * Pre: None
     * Param: lhs - A matrix to be checked
     *        rhs - A matrix to be checked
     * Post: None
     * Return: If they're equal
     */
    friend bool operator== <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);

    /**
     * Purpose: Inequality operator
     * Pre: None
     * Param: lhs - A matrix to be checked
     *        rhs - A matrix to be checked
     * Post: None
     * Return: If they're not equal
     */
    friend bool operator!= <>(const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs);
};
#include "TriDiagonalMatrix.hpp"
#endif
