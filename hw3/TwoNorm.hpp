#include <iostream>
#include <cmath>
#include "Vector.h"

template <class T>
const T TwoNorm<T>::operator() (const Vector<T>& src)
{
  T temp;

  for(int i = 0; i < src.numTerms(); i++)
  {
    temp += src[i] * src[i];
  }

  return std::sqrt(temp);
}