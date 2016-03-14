#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"

using std::ostream;
using std::istream;
template<class T>
class Matrix;

template <class T>
ostream& operator<< (ostream& out, const Matrix<T>& rhs);

template <class T>
istream& operator>> (istream& in, Matrix<T>& rhs);

template <class T>
Matrix<T> operator+ (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator- (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Matrix<T> operator- (const Matrix<T>& rhs);

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
Vector<T> operator* (const Matrix<T>& lhs, const Vector<T>& rhs);

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const Matrix<T>& rhs);

template <class T>
T operator* (const T& lhs, const Matrix<T>& rhs);

template <class T>
T operator* (const Matrix<T>& lhs, const T& rhs);

template <class T>
bool operator== (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
bool operator!= (const Matrix<T>& lhs, const Matrix<T>& rhs);

template <class T>
void swap (Matrix<T>& x, Matrix<T>& y);

const int DEFAULT_ROWS = 5, DEFAULT_COLUMNS = 5;
template <class T>
class Matrix
{
  private:
    int rows;
    int columns;
    Vector<T>* data;

  public:
    /**
     * Purpose: Default Constructor
     * Pre: None
     * Param: None
     * Post: The object is initialized to a Matrix of DEFAULT_ROWS x DEFAULT_COLUMNS
     * Return: None
     */
    Matrix ();

    /**
     * Purpose: Parameterized Constructor
     * Pre: None
     * Param: r - The number of rows in the Matrix
     *        c - The number of columns in the Matrix
     * Post: If r or c are zero or below, an invalid_argument exception will be thrown
     *       The object is initialized to a Matrix of r x c
     * Return: None
     */
    Matrix (int r, int c);

    /**
     * Purpose: Copy Constructor
     * Pre: Template type T must have operator= (T, T) defined
     * Param: src - The object to be copied from
     * Post: The calling object is a deep copy of the parameter src
     * Return: None
     */
    Matrix (const Matrix<T>& src);

    /**
     * Purpose: Move Constructor
     * Pre: None
     * Param: src - The temporary object to be "moved" from
     * Post: The calling object "steals" the pointer of src and sets it to NULL
     * Return: None
     */
    Matrix (Matrix<T>&& src);

    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: The object is destructed
     * Return: None
     */
    ~Matrix ();

    /**
     * Purpose: Get a specified column in the Matrix
     * Pre: Parameter x must be in the range [0, columns)
     * Param: x - The index of the column to be grabbed
     * Post: If x is not in the range [0, columns), then an out_of_range exception is thrown
     * Return: The column at the specified index
     */
    const Vector<T> getColumn(int x) const;

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
     * Param: rhs - The Matrix to set the calling object equal to
     * Post: The calling object is set equal to the the parameter rhs
     * Return: The calling object
     */
    Matrix<T>& operator= (Matrix<T> rhs);

    /**
     * Purpose: Addition-assignment Operator
     * Pre: Template type T must have operator+=(T, T) defined
     * Param: rhs - The object to be added and assigned
     * Post: The calling object is assigned to itself plus the parameter rhs
     * Return: The calling object
     */
    Matrix<T>& operator+= (const Matrix<T>& rhs);

    /**
     * Purpose: Subtraction-assignment operator
     * Pre: Template type T must have operator-(T) defined
     *      Template type T must have operator=(T, T) defined
     * Param: rhs - The object to be subtracted and assigned
     * Post: The calling object is assigned to itself minus the parameter rhs
     * Return: The calling object
     */
    Matrix<T>& operator-= (const Matrix<T>& rhs);

    /**
     * Purpose: Get the number of rows in the Matrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of rows in the Matrix
     */
    int getRows () const;

    /**
     * Purpose: Get the number of columns in the Matrix
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of columns in the matrix
     */
    int getColumns () const;
    
    //Friends

    /**
     * Purpose: Matrix output operator
     * Pre: ostream out must be connected to a stream
     *      Template type T must have operator<<(ostream, T) defined
     * Param: out - The ostream to output the Matrix to
     *        rhs - The Matrix to be output
     * Post: The parameter out will have rhs inserted in to it
     * Return: Parameter out
     */
    friend ostream& operator<< <>(ostream& out, const Matrix<T>& rhs);

    /**
     * Purpose: Matrix extraction operator
     * Pre: istream in must be connected to a stream
     *      Template type T must have operator>>(istream, T) defined
     * Param: in - The istream to read in to the Matrix
     *        rhs - The Matrix to be read in to
     * Post: The parameter in will have rhs read out of it
     *       The parameter rhs will be populated
     * Return: Parameter in
     */
    friend istream& operator>> <>(istream& in, Matrix<T>& rhs);

    /**
     * Purpose: Operator+ - Add two Matrices
     * Pre: Parameter lhs and rhs must be of the same dimensions
     *      Template type T must have operator+=(T) defined
     * Param: lhs - One of the Matrices to be added
     *        rhs - One of the Matrices to be added
     * Post: If lhs and rhs do not have the same dimensions, a length_error exception will be thrown
     * Return: The element-wise sum of the two matrices
     */
    friend Matrix<T> operator+ <>(const Matrix<T>& lhs, const Matrix<T>& rhs);

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
    friend Matrix<T> operator- <>(const Matrix<T>& lhs, const Matrix<T>& rhs);

    /**
     * Purpose: Matrix negation operator
     * Pre: Template type T must have operator=(T) defined
     *      Template type T must have operator-() defined
     * Param: rhs - The Matrix to be negated
     * Post: None
     * Return: The negative of rhs
     */
    friend Matrix<T> operator- <>(const Matrix<T>& rhs);

    /**
     * Purpose: Matrix - Matrix multiplication
     * Pre: Middle dimensions must match (lhs.columns == rhs.rows)
     *      Template type T must have operator=(T) defined
     *      Template type T must have operator*(T, T) defined
     * Param: lhs - The left-hand-side Matrix
     *        rhs - The right-hand-side Matrix
     * Post: If the middle dimensions don't match, a length_error exception will be thrown
     * Return: A product Matrix of size lhs.rows x rhs.columns
     */
    friend Matrix<T> operator* <>(const Matrix<T>& lhs, const Matrix<T>& rhs);

    /**
     * Purpose: Matrix - Vector multiplication
     * Pre: Matrix must have same number of columns as Vector has elements
     * Param: lhs - The matrix to be multiplied
     *        rhs - The Vector to be multiplied
     * Post: If the Matrix and Vector are of differing dimensions, a length_error exception will be thrown
     * Return: The Matrix - Vector product
     */
    friend Vector<T> operator* <>(const Matrix<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: Matrix - Vector multiplication
     * Pre: Matrix must have same number of rows as Vector has elements
     * Param: rhs - The matrix to be multiplied
     *        lhs - The Vector to be multiplied
     * Post: If the Matrix and Vector are of differing dimensions, a length_error exception will be thrown
     * Return: The Vecotr - Matrix product
     */
    friend Vector<T> operator* <>(const Vector<T>& lhs, const Matrix<T>& rhs);

    /**
     * Purpose: Scalar - Matrix multiplication
     * Pre: Template type T must have operator* (T, T) defined
     * Param: lhs - The scalar to be multiplied to the Matrix
     *        rhs - The Matrix to be multiplied in to
     * Post: None
     * Return: The parameter lhs
     */
    friend T operator* <>(const T& lhs, const Matrix<T>& rhs);

    /**
     * Purpose: Scalar - Matrix multiplication
     * Pre: Template type T must have operator* (T, T) defined
     * Param: rhs - The scalar to be multiplied to the Matrix
     *        lhs - The Matrix to be multiplied in to
     * Post: None
     * Return: The parameter rhs
     */
    friend T operator* <>(const Matrix<T>& lhs, const T& rhs);

    /**
     * Purpose: Matrix - Matrix equality operator
     * Pre: None
     * Param: lhs - A matrix to be compared
     *        rhs - A matrix to be compared
     * Post: None
     * Return: True if they're equal, false otherwise
     */
    friend bool operator== <>(const Matrix<T>& lhs, const Matrix<T>& rhs);

    /**
     * Purpose: Matrix - Matrix equality operator
     * Pre: None
     * Param: lhs - A matrix to be compared
     *        rhs - A matrix to be compared
     * Post: None
     * Return: True if they're not equal, false otherwise
     */
    friend bool operator!= <>(const Matrix<T>& lhs, const Matrix<T>& rhs);

    /**
     * Purpose: Matrix swap function
     * Pre: None
     * Param: x - An element to be swapped
     *        y - An element to be swapped
     * Post: x will be equal to y and y will be equal to x
     * Return: None
     */
    friend void swap <>(Matrix<T>& x, Matrix<T>& y);
};
#include "Matrix.hpp"
#endif
