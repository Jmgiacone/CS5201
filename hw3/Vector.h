#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

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
    Vector();
    Vector(int s);
    Vector(const Vector<T>& src);
    ~Vector();

    //Move Constructor
    Vector(Vector<T>&& src) : data(src.data), terms(src.terms)
    {
      src.data = NULL;
    };

    //Conventional Operators
    const Vector<T>& operator= (Vector<T> rhs);
    const Vector<T>& operator+= (const Vector<T>& rhs);
    const Vector<T>& operator-= (const Vector<T>& rhs);
    const T& operator[] (const int x);

    //Move operators
    const Vector<T>& operator= (Vector<T>&& rhs);
    const Vector<T>& operator+= (Vector<T>&& rhs);
    const Vector<T>& operator-= (Vector<T>&& rhs);

    friend std::ostream& operator<< <>(std::ostream& out, const Vector<T>& rhs);
    friend std::istream& operator>> <>(std::istream& in, Vector<T>& rhs);
    friend const Vector<T> operator+ <>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend const Vector<T> operator- <>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend const Vector<T> operator- <>(const Vector<T>& rhs);
    friend const T operator* <>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend const Vector<T> operator* <>(const Vector<T>& lhs, const T& rhs);
    friend const Vector<T> operator* <> (const T& lhs, const Vector<T>& rhs);
    friend bool operator== <>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend bool operator!= <>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend void swap <>(Vector<T>& x, Vector<T>& y);

};

#include "Vector.hpp"
#endif