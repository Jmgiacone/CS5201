//
// Created by Jordan on 4/7/2016.
//

#ifndef SMARTVECTOR_H
#define SMARTVECTOR_H
template <class T>
class SmartVector
{
  T zero = 0;
  private:
    T** data;
    int terms;

  public:
    SmartVector(int size, T** d);
    SmartVector(const SmartVector<T>& src);
    SmartVector(SmartVector<T>&& src) : terms(src.terms), data(src.data) {src.data = NULL;}
    const T& operator[] (int x) const;
    int numTerms() const {return terms;};
};
#include "SmartVector.hpp"
#endif
