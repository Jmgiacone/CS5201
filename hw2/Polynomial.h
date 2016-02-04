#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include "Term.h"
template <class T>
class Polynomial;

template <class T>
std::ostream& operator<< (std::ostream& out, const Polynomial<T>& rhs);

template <class T>
class Polynomial
{
  private:
    Term<T>* data;
    int numTerms;
  public:
    Polynomial();
    Polynomial(const int n);
    Polynomial(const Term<T>& t);
    Polynomial(const Polynomial<T>& p);
    ~Polynomial();

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
      out << currentData << " ";

      if(data[i + 1].coefficient > 0 && data[i + 1].coefficient != 0)
      {
        out << "+ ";
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