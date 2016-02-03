#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <fstream>

using namespace std;
template<class T>
struct Term
{
  public:
    T coefficient;
    T exponent;
};

template <class T>
class Polynomial
{
  private:
    int numTerms;
    Term<T>* data;
  
  public:
    Polynomial(); 
    Polynomial(const int n);
    Polynomial(const Polynomial<T> &src); 
    ~Polynomial();

    //Overloaded Operators
    Polynomial<T>& operator+=(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator+(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator-(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator-() const;
    Polynomial<T>& operator-=(const Polynomial<T>& rhs) const;
    bool operator==(const Polynomial<T>& rhs) const;
    bool operator!=(const Polynomial<T>& rhs) const;
    Polynomial<T>& operator*(const float f) const;
    Polynomial<T>& operator=(const Polynomial<T>& rhs);
    T& operator[](const int i) const;
    float operator()(const int x) const;
    Polynomial<T>& operator~() const;

    template <class U> 
    friend ostream& operator<<(ostream& out, const Polynomial<U> rhs);

};


#include "Polynomial.hpp"
#endif
