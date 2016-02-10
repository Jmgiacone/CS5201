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
  Term() {coefficient = 0; exponent = 0;};
  Term(T c, T e) {coefficient = c; exponent = e;};
  bool operator< (const Term<T>& rhs) const {return exponent < rhs.exponent;};
  bool operator> (const Term<T>& rhs) const {return exponent > rhs.exponent;};
  bool operator<= (const Term<T>& rhs) const {return exponent <= rhs.exponent;};
  bool operator>= (const Term<T>& rhs) const {return exponent >= rhs.exponent;};
  bool operator== (const Term<T>& rhs) const {return (coefficient == rhs.coefficient && exponent == rhs.exponent);};
  bool operator!= (const Term<T>& rhs) const {return !(*this == rhs);};
  const T& operator() (const T& x) const {return coefficient * pow(x, exponent);};
    
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
