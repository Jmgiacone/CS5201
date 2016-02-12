/**
 * Programmer: Jordan Giacone
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: Polynomial.h
 * Description: This is the header file for the templated Polynomial class.
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include "Term.h"
template <class T>
class Polynomial;

template <class T>
std::ostream& operator<< (std::ostream& out, const Polynomial<T>& rhs);

const int DEFAULT_MAX_TERMS = 5;
template <class T>
class Polynomial
{
  private:
    //A pointer to an Array of Terms
    Term<T>* data;

    //numTerms: The current number of terms in the Polynomial
    //maxTerms: The maximum capacity the Polynomial can have
    int numTerms, maxTerms;
  public:
    /**
     * Purpose: A default constructor. 
     * Pre: None
     * Post: numTerms is initialized to 0
             maxTerms is initialized to DEFAULT_MAX_TERMS
             data is initialized to a new array of size maxTerms
     */
    Polynomial();

    /**
     * Purpose: A constructor to initialize the object with a max number 
     * of terms other than DEFAULT_MAX_TERMS
     * Param: n - The size for the array to be allocated to
     * Pre: None
     * Post: numTerms is initialized to 0
             maxTerms is initialized to n
             data is initialized to a new array of size maxTerms
     */
    Polynomial(const int n);

    /**
     * Purpose: A constructor to initialize the object to a monomial (A polynomial with 1 term)
     * Pre: None
     * Param: c - The coefficient for the monomial
     * Param: e - The exponent for the monomial
     * Post: numTerms is initialized to 1
             maxTerms is initialized to DEFAULT_MAX_TERMS
             data is initialized to a new array of size maxTerms
             data[0] is initialized to a new Term<T> with parameters c and e 
     */
    Polynomial(const T& c, const int e);

    /**
     * Purpose: A copy constructor to make a deep copy of the passed-in object
     * Param: p - The Polynomial to be copied
     * Post: numTerms is initialized to numTerms in p
             maxTerms is initialized to maxTerms in p
             data from p is deeply copied in to data
     */
    Polynomial(const Polynomial<T>& p);

    /**
     * Purpose: A destructor for Polynomial
     * Pre: None
     * Post: numTerms is set to 0
             maxTerms is set to 0
             any data stored in data is deleted
             data is set to NULL
     */
    ~Polynomial();

    //Overloaded Operators
    
    /**
     * Purpose: Takes rhs and copies all of the data in to this object
     * Pre: Template type T must have the '=' operator defined
     * Param: rhs - The object to be copied
     * Post: All previous data will be deleted and replaced by data from rhs
     * Return: The calling object so that '=' operators can be chained
     */
    Polynomial<T>& operator= (const Polynomial<T>& rhs);

    /**
     * Purpose: To check equality between the calling object and the parameter
     * Pre: Template type T must have the == operator defined 
     * Param: rhs - The object to be compared to the calling object
     * Post: None
     * Return: true if the objects are equal, false if they are not
     */
    bool operator== (const Polynomial<T>& rhs) const;

    /**
     * Purpose: To check inequality between the calling object and the parameter
     * Pre: Template type T must have the == operator defined
     * Post: None
     * Return: true if the objects are not equal, false if they are
     */
    bool operator!= (const Polynomial<T>& rhs) const;

    /**
     * Purpose: To evaluate the function at a specified constant
     * Pre: Template type T must have the '*' operator defined
            Template type T must be compatible with function pow()
            Template type T must have the '+=' operator defined
     * Param: x - The value for the Polynomial to be evaluated at
     * Post: None
     * Return: The value of the Polynomial evaluated at x
     */
    const T operator() (const T& x) const;

    /**
     * Purpose: To peek at the monomial in the specified position
     * Pre: Parameter i must be a valid bound (between 0 and numTerms - 1)
     * Param: i - The index of the monomial to be retrieved 
     * Post: If parameter i is not a valid bound, a RangeError will be thrown
     * Return: The monomial indexed at i
     */
    const Term<T>& operator[] (const int i) const;

    /**
     * Purpose: To multiply the coefficients of the calling object by a constant
     * Pre: Template type T must have the '*=' operator defined
     * Param: x - The value to be multiplied across the coefficients
     * Post: None
     * Return: A copy of the calling object with all coefficients 
               multiplied by x 
     */
    const Polynomial<T> operator* (const T& x) const;

    /**
     * Purpose: To add two Polynomials together
       Pre: Template type T must have the '=' operator defined
            Template type T must have the '+' operator defined
            Template type T must have the '==' operator defined
     * Param: rhs - The Polynomial to be added to the calling object
     * Post: None
     * Return: A Polynomial representing the sum of the two Polynomials
     */
    const Polynomial<T> operator+ (const Polynomial<T>& rhs) const;

    /**
     * Purpose: To add two Polynomials together and set the calling object
                equal to the result
       Pre: Template type T must have the '=' operator defined 
            Template type T must have the '+' operator defined
            Template type T must have the '==' operator defined
     * Post: The calling object will be modified to be the sum of itself
             and the parameter rhs
     * Return: The calling object so that '+=' operators can be 
               chained together
     */
    const Polynomial<T>& operator+= (const Polynomial<T>& rhs);
    
    /**
     * Purpose: To subtract the parameter from the calling object
       Pre: Template type T must have the '=' operator defined
            Template type T must have the '+' operator defined
            Template type T must have the '*' operator defined
            Template type T must have the '==' operator defined
     * Param: rhs - The Polynomial to be subtracted from the calling object
     * Post: None
     * Return: A Polynomial representing the difference of the two Polynomials
     */
    const Polynomial<T> operator- (const Polynomial<T>& rhs) const;

    /**
     * Purpose: To subtract the parameter from the calling object
                and assign that difference to the calling object
       Pre: Template type T must have the '=' operator defined
            Template type T must have the '+' operator defined
            Template type T must have the '==' operator defined
     * Param: rhs - The Polynomial to be subtracted from the calling object
     * Post: The calling object will be modified to the difference between 
             the calling itself and the parameter rhs
     * Return: The calling object so that '-=' operators can be
               chained together
     */
    const Polynomial<T>& operator-= (const Polynomial<T>& rhs);
    
    /**
     * Purpose: To make the coefficient on each term of the 
                Polynomial negative
     * Pre: Template type T must have the '>' operator defined 
            Template type T must have the '*=' operator defined
     * Post: None
     * Return: A copy of the calling object where every coefficient
               is made to be negative
     */
    const Polynomial<T> operator~ () const;
    
    /**
     * Purpose: To negate the coefficient on each tearm of the Polynomial 
     * Pre: Template type T must have the '*=' operator defined
     * Post: None
     * Return: A copy of the calling object where every coefficient
               is negated
     */
    const Polynomial<T> operator- () const;

    /**
     * Purpose: To calculate and return the magnitude of the calling object.
                The magnitude is defined as the square root of the sum of
                the sum of the squares of the coefficients
     * Pre: Template type T must have the '*' operator defined
            Template type T must have the '+=' operator defined
            Template type T must be compatible with the sqrt() function
     * Post: None
     * Return: The magnitude of the calling object
     */
    const T magnitude() const;

    /**
     * Purpose: To multiply the coefficients of the calling rhs by a constant
     * Pre: Template type T must have the '*=' operator defined 
     * Param: x - The value to be multiplied across the coefficients
              rhs - The Polynomial object to supply the coefficients
     * Post: None
     * Return: A copy of rhs with all coefficients multiplied by x 
     */
    friend Polynomial<T> operator* (const T& x, const Polynomial<T>& rhs) {return rhs * x;};

    /**
     * Purpose: To output the given Polynomial using the provided ostream
     * Pre:
     * Param: out - The ostream to be used for output
              rhs - The Polynomial to be outputted to the given ostream
     * Post: out will have characters inserted in to it's stream
       Return: The ostream parameter rhs so that the '<<' operator can be chained
     */
    friend std::ostream& operator<< <>(std::ostream& out, const Polynomial<T>& rhs);
};
#include "Polynomial.hpp"
#endif

template <class T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& rhs)
{
  Term<T>* data = rhs.data;
  Term<T> currentData;
  int terms = rhs.numTerms;
  for(int i = 0; i < terms; i++)
  {
    currentData = data[i];

    //Know to put an extra space after the line
    if(i < (terms - 1))
    {
      out << currentData;

      if(data[i + 1].coefficient > 0 && data[i + 1].coefficient != 0)
      {
        out << "+";
      }
    }
    else
    {
      //Last term, don't check next one (because it doesn't exist)
      out << currentData;
    }
  }

  return out;
}
