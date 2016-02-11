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
    Polynomial(const T& c, const T& e);

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
    Polynomial<T>&operator= (const Polynomial<T>& rhs);
    bool operator== (const Polynomial<T>& rhs) const;
    bool operator!= (const Polynomial<T>& rhs) const;
    const T operator() (const T& x) const;
    const Term<T>& operator[] (const int i) const;
    const Polynomial<T> operator* (const T& x) const;
    const Polynomial<T> operator+ (const Polynomial<T>& rhs) const;
    const Polynomial<T>& operator+= (const Polynomial<T>& rhs);
    const Polynomial<T> operator- (const Polynomial<T>& rhs) const;
    const Polynomial<T>& operator-= (const Polynomial<T>& rhs);
    const Polynomial<T> operator~ () const;
    const Polynomial<T> operator- () const;

    //Magnitude function
    const T magnitude() const;

    friend Polynomial<T> operator* (const T& x, const Polynomial<T>& rhs) {return rhs * x;};
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
