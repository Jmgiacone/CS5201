/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 2
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: InfinityNorm.hpp
 * Description: This is the implementation file for the InfinityNorm class
 */

template <class T>
const T InfinityNorm<T>::operator() (const std::vector<Polynomial<T>> &vect) const
{
  T max, temp;
  int size = vect.size();

  for(int i = 0; i < size; i++)
  {
    temp = vect[i].magnitude();

    if(i == 0)
    {
      max = temp;
    }
    else if(temp > max)
    {
      max = temp;
    }
  }
  return max;
}
