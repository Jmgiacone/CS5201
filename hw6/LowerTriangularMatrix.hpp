/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: LowerTriangularMatrix.hpp
 * Description: This is the implementation file for the LowerTriangularMatrix class
 */
template <class T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(const int d)
{
  dimensions = d;
  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = Vector<T>(dimensions - i);
  }
}

template <class T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(const LowerTriangularMatrix<T>& src)
{
  dimensions = src.dimensions;
  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = src.data[i];
  }
}

template <class T>
LowerTriangularMatrix<T>::~LowerTriangularMatrix()
{
  if (data != NULL)
  {
    delete[] data;
    data = NULL;
  }
}

template <class T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::operator=(LowerTriangularMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <class T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::operator+=(const LowerTriangularMatrix<T> &rhs)
{
  return *this = *this + rhs;
}

template <class T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::operator-=(const LowerTriangularMatrix<T> &rhs)
{
  return *this = *this - rhs;
}

template <class T>
void swap(LowerTriangularMatrix<T> &x, LowerTriangularMatrix<T> &y)
{
  std::swap(x.dimensions, y.dimensions);
  std::swap(x.data, y.data);
}

template <class T>
const T& LowerTriangularMatrix<T>::operator()(const int row, const int column) const
{
  if (zero != 0)
  {
    zero = 0;
  }

  if(row >= column)
  {
    return data[column - row][row];
  }

  return zero;
}

template <class T>
T& LowerTriangularMatrix<T>::operator()(const int row, const int column)
{
  if (zero != 0)
  {
    zero = 0;
  }

  if(row >= column)
  {
    return data[column - row][row];
  }

  return zero;
}

template <class T>
AbstractMatrix<T>* LowerTriangularMatrix<T>::clone() const
{
  return new LowerTriangularMatrix<T>(*this);
}