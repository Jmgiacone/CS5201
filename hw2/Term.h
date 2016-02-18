/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 2
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: Term.h
 * Description: This is the header file for the templated Term class
 */

#ifndef CS5201_HW2_TERM_H
#define CS5201_HW2_TERM_H
#include <iostream>
#include <cmath>
#include "ExponentError.h"

template <class T>
struct Term;

template <class T>
std::ostream& operator<< (std::ostream&, const Term<T>& rhs);

template <class T>
struct Term
{
  T coefficient;
  int exponent;
  
  /**
   * Purpose: To construct a Term with both coefficients as zero
   * Pre: Template type T must have the '=' operator defined
   * Post: The object is created with both coefficiens as zero
   */
  Term() {coefficient = 0; exponent = 0;};

  /**
   * Purpose: To construct a Term with given values for coefficient and exponent
   * Pre: Template type T must have the '=' operater defined
   * Post: The object is created with the given values
   */
  Term(const T& c, const int e) 
  {
    if(e < 0)
    {
      throw ExponentError("Negative Exponent detected!");
    }
    coefficient = c; 
    exponent = e;
  };

  /**
   * Purpose: To check if the calling object's exponent is less than the 
              exponent of the parameter
   * Pre: None
   * Param: rhs - The Term to be compared with the calling object
   * Post: None
   * Return: If the calling object's exponent is less than the exponent of
             the parameter, true. Otherwise, false
   */
  bool operator< (const Term<T>& rhs) const {return exponent < rhs.exponent;};
   
  /**
   * Purpose: To check if the calling object's exponent is greater than the 
              exponent of the parameter
   * Pre: None
   * Param: rhs - The Term to be compared with the calling object
   * Post: None
   * Return: If the calling object's exponent is greater than the exponent of
             the parameter, true. Otherwise, false
   */
  bool operator> (const Term<T>& rhs) const {return exponent > rhs.exponent;};

  /**
   * Purpose: To check if the calling object's exponent is less than or equal 
              to the exponent of the parameter
   * Pre: None
   * Param: rhs - The Term to be compared with the calling object
   * Post: None
   * Return: If the calling object's exponent is less than or equal to the 
             exponent of the parameter, true. Otherwise, false
   */
  bool operator<= (const Term<T>& rhs) const {return exponent <= rhs.exponent;};

  /**
   * Purpose: To check if the calling object's exponent is greater than or equal
               to the exponent of the parameter
   * Pre: None
   * Param: rhs - The Term to be compared with the calling object
   * Post: None
   * Return: If the calling object's exponent is greater than or equal to the
             exponent of the parameter, true. Otherwise, false
   */
  bool operator>= (const Term<T>& rhs) const {return exponent >= rhs.exponent;};

  /**
   * Purpose: To check if the calling object is equal to the parameter
   * Pre: Template type T must have the '==' operator defined
   * Param: rhs - The Term to be compared with the calling object
   * Post: None
   * Return: True if the calling object is equal to the parameter, 
             false otherwise
   */
  bool operator== (const Term<T>& rhs) const {return (coefficient == rhs.coefficient && exponent == rhs.exponent);};
  
  /**
   * Purpose: To check if the calling object is not equal to the parameter
   * Pre: Template type T must have the '!=' operator defined
   * Param: rhs - The Term to be compared with the calling object
   * Post: None
   * Return: True if the calling object is not equal to the parameter, 
             false otherwise
   */
  bool operator!= (const Term<T>& rhs) const {return !(*this == rhs);};
  
  /**
   * Purpose: To evaluate the Term at a specified constant
   * Pre: Template type T must have the '*' operator defined
          Template type T must be defined for function pow()
   * Param: x - The constant to use for Term evaluation
   * Post: None
   * Return: The value of the term evaluated at x
   */
  const T operator() (const T& x) const {return coefficient * pow(x, exponent);};
    
  /**
   * Purpose: To output the parameter rhs to the given ostream
   * Pre: Template type T must have the '==' operator defined
          Template type T must have the '!=' operator defined
   * Param: out - The ostream to output the given Term to
            rhs - The Term to be outputted
   * Post: The ostream out will have characters inserted in to it's stream
   * Return: The parameter out so that you can chain '<<' operators
   */
  friend std::ostream& operator<< <>(std::ostream& out, const Term<T> &rhs);
};
#endif

template <class T>
std::ostream& operator<<(std::ostream& out, const Term<T>& rhs)
{
  if(rhs.coefficient == 0 || rhs.exponent == 0)
  {
    out << rhs.coefficient;
    return out;
  }

  if(rhs.coefficient == -1)
  {
    out << "-";
  }
  else if(rhs.coefficient == 1)
  {
    //unused
  }
  else
  {
    out << rhs.coefficient;
  }

  out << "x";
  
  if(rhs.exponent != 1)
  {
    out << "^" << rhs.exponent;
  }
  
  return out;
}
