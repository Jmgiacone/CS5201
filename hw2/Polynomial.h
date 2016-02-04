#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <fstream>
#include "Term.h"
using namespace std;
template<class T>
class Polynomial
{
  private:
    int numTerms;
    Term<T>* data;
    void copyArray(Term<T>* src, Term<T>* dest, int numTerms);
    void sort();
  
  public:
    Polynomial(); 
    Polynomial(const int n);
    Polynomial(const Polynomial<T> &src);
    Polynomial(Term<T>* terms, int numTerms);
    ~Polynomial();

    //Overloaded Operators
    Polynomial<T>& operator+=(const Polynomial<T>& rhs);
    Polynomial<T>& operator+(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator-(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator-() const;
    Polynomial<T>& operator-=(const Polynomial<T>& rhs);
    bool operator==(const Polynomial<T>& rhs) const;
    bool operator!=(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator*(const float f) const;
    Polynomial<T>& operator=(const Polynomial<T>& rhs);
    T& operator[](const int i) const;
    T operator()(const int x) const;
    Polynomial<T>& operator~() const;

    template <class U> 
    friend ostream& operator<<(ostream& out, const Polynomial<U> rhs);

};


#include "Polynomial.hpp"
#endif

template <typename U>
ostream& operator<<(ostream &out, const Polynomial<U> rhs)
{
  Term<U>* data = rhs.data;
  Term<U> currentData;
  int terms = rhs.numTerms;
  for(int i = 0; i < terms; i++)
  {
    currentData = data[i];

    //Know to put an extra space after the line
    if(i < (terms - 1))
    {
      out << currentData << " ";

      if(data[i + 1].coefficient > 0)
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
