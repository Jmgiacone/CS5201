#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>

template <class T>
class Vector;

template <class T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& rhs);

template <class T>
std::istream& operator>> (std::istream& in, Vector<T>& rhs);

template <class T>
const Vector<T> operator+ (const Vector<T>& lhs, const Vector<T>& rhs);

template <class T>
const Vector<T> operator- (const Vector<T>& lhs, const Vector<T>& rhs);

template <class T>
const Vector<T> operator- (const Vector<T>& rhs);

template <class T>
const T operator* (const Vector<T>& lhs,const Vector<T>& rhs);

template <class T>
const Vector<T> operator* (const Vector<T>& lhs, const T& rhs);

template <class T>
const Vector<T> operator* (const T& lhs, const Vector<T>& rhs);

template <class T>
bool operator== (const Vector<T>& lhs, const Vector<T>& rhs);

template <class T>
bool operator!= (const Vector<T>& lhs, const Vector<T>& rhs);

template <class T>
void swap(Vector<T>& x, Vector<T>& y);

const int DEFAULT_TERMS = 5;
template <class T>
class Vector
{
  private:
    T* data;
    int terms;

  public:
    //Conventional Constructors
    /**
     * Purpose: Default constructor
     * Pre: None
     * Param: None
     * Post: The object is constructed
     * Return: None
     */
    Vector();

    /**
     * Purpose: Parameterized constructor
     * Pre: s must be non-zero
     * Param: s - The size of the Vector to be constructed
     * Post: The object is constructed
     *       If s is not non-zero, an invalid_argument exception will bet thrown
     * Return: None
     */
    Vector(int s);

    /**
     * Purpose: Copy constructor
     * Pre: None
     * Param: src - The object to be copied from
     * Post: The calling object will be a deep copy of the parameter src
     * Return: None
     */
    Vector(const Vector<T>& src);

    /**
     * Purpose: Destructor
     * Pre: None
     * Param: None
     * Post: The object is destructed
     * Return: None
     */
    ~Vector();

    /**
     * Purpose: Move constructor
     * Pre: None
     * Param: src - A temporary 'rvalue' that is about to be destructed
     * Post: The calling object 'steals' the data pointer from src and sets src's data to NULL
     *       The calling object will be a deep copy of the parameter src
     * Return: None
     */
    Vector(Vector<T>&& src) : data(src.data), terms(src.terms)
    {
      src.data = NULL;
    };

    /**
     * Purpose: To return the number of terms in the Vector
     * Pre: None
     * Param: None
     * Post: None
     * Return: The number of terms in the Vector
     */
    const int numTerms() const {return terms;};

    /**
     * Purpose: Assignment Operator - To assign the calling object to the state of the right-hand-side object
     * Pre: None
     * Param: rhs - The object to be copied from
     * Post: The calling object will be in the same state as parameter rhs
     * Return: The calling object for the purpose of chaining = operators
     */
    const Vector<T>& operator= (Vector<T> rhs);

    /**
     * Purpose: += Operator - To add the calling object and the parameter rhs together, then set the calling object
     *             equal to the result
     * Pre: The calling object and parameter rhs must have the same number of terms
     *      Template type T must have operator= (T) defined
     *      Template type T must have operator+ (T, T) defined
     * Param: rhs - The Vector to be added
     * Post: If the calling object and rhs have differing numbers of terms, a std::length_error will be thrown
     *       The calling object will be the sum of the calling object and the parameter rhs
     * Return: The calling object for the purpose of chaining += operators
     */
    const Vector<T>& operator+= (const Vector<T>& rhs);

    /**
     * Purpose: += Operator - To subtract the parameter rhs from the calling object, then set the calling object
     *             equal to the result
     * Pre: The calling object and parameter rhs must have the same number of terms
     *      Template type T must have operator= (T) defined
     *      Template type T must have operator+ (T, T) defined
     *      Template type T must have operator- (T) defined <--- This is unary - or the negation operator
     * Param: rhs - The Vector to be subtracted
     * Post: If the calling object and rhs have differing numbers of terms, a std::length_error will be thrown
     *       The calling object will be the difference of the calling object and the parameter rhs
     * Return: The calling object for the purpose of chaining -= operators
     */
    const Vector<T>& operator-= (const Vector<T>& rhs);

    /**
     * Purpose: [] operator - To be able to peek at and modify elements of the Vector
     * Pre: Parameter x must be within the range [0, terms)
     * Param: x - The index of the Vector element to be returned
     * Post: If parameter x is not withing the proper range, a out_of_range exception will be thrown
     * Return: The element indexed at parameter x
     */
    T& operator[] (const int x);

    /**
     * Purpose: [] operator - To be able to peek at and NOT modify elements of the Vector
     * Pre: Parameter x must be within the range [0, terms)
     * Param: x - The index of the Vector element to be returned
     * Post: If parameter x is not withing the proper range, a out_of_range exception will be thrown
     * Return: The element indexed at parameter x
     */
    const T& operator[] (const int x) const;

    /**
     * Purpose: Stream insertion operator - To facilitate output of Vector class to streams
     * Pre: Parameter out be connected to a valid stream
     *      Template type T must have operator<< (ostream, T) defined
     * Param: out - The stream to be output to
     *        rhs - The Vector object to be output
     * Post: The Vector object is output to the stream out
     * Return: The parameter out for chaining << operators
     */
    friend std::ostream& operator<< <>(std::ostream& out, const Vector<T>& rhs);

    /**
     * Purpose: Stream extraction operator - To facilitate extracting data from a stream and storing it in a Vector
     * Pre: Parameter in be connected to a valid stream
     *      Template type T must have operator>> (istream, T) defined
     * Param: in - The stream to be extracted from
     *        rhs - The Vector be extracted in to
     * Post: The Vector object is extracted into by the stream in
     * Return: The parameter in for chaining of >> operators
     */
    friend std::istream& operator>> <>(std::istream& in, Vector<T>& rhs);

    /**
     * Purpose: operator+ - Adding two Vectors together
     * Pre: lhs and rhs must be of the same size
     *      Template type T must have operator+ (T, T) defined
     *      Template type T must have operator= (T) defined
     * Param: lhs - A Vector to be added
     *        rhs - The other Vector to be added
     * Post: If lhs and rhs are of different size, a length_error exception is thrown
     * Return: The element-wise sum of the two Vectors
     */
    friend const Vector<T> operator+ <>(const Vector<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: operator- - Subtracting two Vectors from one another
     * Pre: lhs and rhs must be of the same size
     *      Template type T must have operator- (T) defined <--- unary- or negation operator
     *      Template type T must have operator+ (T, T) defined
     *      Template type T must have operator= (T) defined
     * Param: lhs - The Vector to be subtracted from
     *        rhs - The Vector to be subtracted
     * Post: If lhs and rhs are of different size, a length_error exception is thrown
     * Return: The element-wise difference of the two Vectors
     */
    friend const Vector<T> operator- <>(const Vector<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: operator- - Negation operator
     * Pre: Template type T must have operator- (T) defined <--- unary- or negation operator
     * Param: rhs - The Vector to be negated
     * Post: None
     * Return: The negation of parameter rhs
     */
    friend const Vector<T> operator- <>(const Vector<T>& rhs);

    /**
     * Purpose: Operator* - Dot product of two Vectors
     * Pre: lhs and rhs must be of the same size
     *      Template type T must have operator* (T, T) defined
     *      Template type T must have operator+= (T) defined
     * Param: lhs - One of the Vectors to be used in the dot product
     *        rhs - The other Vector to be used in the dot product
     * Post: If lhs and rhs are of different sizes, a length_error exception is thrown
     * Return: The dot product of the two Vectors
     */
    friend const T operator* <>(const Vector<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: operator* - Scalar multiplication on a Vector
     * Pre: Template type T must have operator*= (T) defined
     * Param: lhs - The Vector to be multiplied by the scalar
     *        rhs - The scalar to be multiplied
     * Post: None
     * Return: The scalar product of lhs and rhs
     */
    friend const Vector<T> operator* <>(const Vector<T>& lhs, const T& rhs);

    /**
     * Purpose: operator* - Scalar multiplication on a Vector
     * Pre: Template type T must have operator*= (T) defined
     * Param: rhs - The Vector to be multiplied by the scalar
     *        lhs - The scalar to be multiplied
     * Post: None
     * Return: The scalar product of lhs and rhs
     */
    friend const Vector<T> operator* <> (const T& lhs, const Vector<T>& rhs);

    /**
     * Purpose: operator== - Vector-Vector equality operator
     * Pre: Template type T must have operator!= (T) defined
     * Param: lhs - One of the Vectors to be compared
     *        rhs - The other Vector to be compared
     * Post: None
     * Return: True if the Vectors are equal, false otherwise
     */
    friend bool operator== <>(const Vector<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: operator!= - Vector-Vector inequality operator
     * Pre: Template type T must have operator!= (T) defined
     * Param: lhs - One of the Vectors to be compared
     *        rhs - The other Vector to be compared
     * Post: None
     * Return: True if the Vectors are not equal, false otherwise
     */
    friend bool operator!= <>(const Vector<T>& lhs, const Vector<T>& rhs);

    /**
     * Purpose: Swap function - To swap values of two Vector types
     * Pre: None
     * Param: x - One of the Vectors to be swapped
     *        y - The other Vector to be swapped
     * Post: The member variables of x have been swapped with those of y
     * Return: None
     */
    friend void swap <>(Vector<T>& x, Vector<T>& y);

};

#include "Vector.hpp"
#endif