/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: TwoNorm.hpp
 * Description: Template implementation file for the TwoNorm functor
 */
#include <iostream>
#include <cmath>
#include "algebravector.h"

template <class T>
const T TwoNorm<T>::operator() (const AlgebraVector<T>& src)
{
  T temp;
  int n = static_cast<int>(src.size());

  if(n != 0)
  {
    temp = src[0] * src[0];
    for (int i = 1; i < n; i++)
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