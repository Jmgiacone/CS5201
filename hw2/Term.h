#ifndef CS5201_HW2_TERM_H
#define CS5201_HW2_TERM_H
#include <iostream>
#include <cmath>

template <class T>
struct Term;

template <class T>
std::ostream& operator<< (std::ostream&, const Term<T>& rhs);

template <class T>
struct Term
{
  T coefficient;
  T exponent;
  bool operator< (Term<T>& rhs) {return exponent < rhs.exponent;};
  bool operator> (Term<T>& rhs) {return exponent > rhs.exponent;};
  bool operator<= (Term<T>& rhs) {return exponent <= rhs.exponent;};
  bool operator>= (Term<T>& rhs) {return exponent >= rhs.exponent;};
  bool operator== (Term<T>& rhs) {return (coefficient == rhs.coefficient && exponent == rhs.exponent);};
  bool operator!= (Term<T>& rhs) {return !(*this == rhs);};
  const T& operator() (const T& x) {return coefficient * pow(x, exponent);};
    
  friend std::ostream& operator<< <>(std::ostream& out, const Term<T> &rhs);
};
#endif

template <class T>
std::ostream& operator<<(std::ostream& out, const Term<T>& rhs)
{
  if(rhs.coefficient == 0)
  {
    out << rhs.coefficient;
  }
  else if(rhs.exponent == 0)
  {
    out << rhs.coefficient;
  }
  else if(rhs.exponent == 1)
  {
    out << rhs.coefficient << "x";
  }
  else
  {
    out << rhs.coefficient << "x^" << rhs.exponent;
  }

  return out;
}
