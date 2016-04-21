/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 3
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/26/16
 * Filename: TwoNorm.hpp
 * Description: Template implementation file for the TwoNorm functor
 */

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
    throw std::invalid_argument("Vector is of size zero!");
  }
  return std::sqrt(temp);
}