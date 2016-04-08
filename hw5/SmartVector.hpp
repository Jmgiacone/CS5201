/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: SmartVector.tpp
 * Description: This is the implementation file for the Smart Vector
 */

template <class T>
SmartVector<T>::SmartVector(int size, T** d)
{
  terms = size;
  data = d;
}

template <class T>
SmartVector<T>::SmartVector(const SmartVector<T>& src)
{
  terms = src.terms;

  data = new T*[terms];

  for(int i = 0; i < terms; i++)
  {
    data[i] = new T(*src.data[i]);
  }
}

template <class T>
const T& SmartVector<T>::operator[](int x) const
{
  if(x >= terms || x < 0)
  {
    throw std::invalid_argument("SmartVector [] Error: Out of bounds");
  }

  if(data[x] == NULL)
  {
    return zero;
  }
  return *data[x];
}