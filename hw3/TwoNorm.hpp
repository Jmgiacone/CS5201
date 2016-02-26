#include <iostream>
#include <cmath>
#include "Vector.h"

template <class T>
const T TwoNorm<T>::operator() (const Vector<T>& src)
{
  T temp;
  int n = src.numTerms();

  if(n != 0)
  {
    temp = src[0] * src[0];
    for (int i = 1; i < src.numTerms(); i++)
    {
      temp += src[i] * src[i];
    }
  }
  else
  {
    //throw error
  }
  return std::sqrt(temp);
}