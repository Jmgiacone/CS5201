/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: UpperTriangularMatrix.h
 * Description: This is the implementation file for the UpperTriangularMatrix class
 */
template <class T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(const int d)
{
  dimensions = d;
  data = new Vector<T>[dimensions];
  //zero = 0.0;

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = Vector<T>(dimensions - i);
  }
}

template <class T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(const UpperTriangularMatrix<T>& src)
{
  dimensions = src.dimensions;
  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = src.data[i];
  }
}

template <class T>
UpperTriangularMatrix<T>::~UpperTriangularMatrix()
{
  if (data != NULL)
  {
    delete[] data;
    data = NULL;
  }
}

template <class T>
UpperTriangularMatrix<T>& UpperTriangularMatrix<T>::operator=(UpperTriangularMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <class T>
UpperTriangularMatrix<T>& UpperTriangularMatrix<T>::operator+=(const UpperTriangularMatrix<T> &rhs)
{
  return *this = *this + rhs;
}

template <class T>
UpperTriangularMatrix<T>& UpperTriangularMatrix<T>::operator-=(const UpperTriangularMatrix<T> &rhs)
{
  return *this = *this - rhs;
}

template <class T>
void swap(UpperTriangularMatrix<T> &x, UpperTriangularMatrix<T> &y)
{
  std::swap(x.dimensions, y.dimensions);
  std::swap(x.data, y.data);
}

template <class T>
const T& UpperTriangularMatrix<T>::operator()(const int row, const int column) const
{
  if(row <= column)
  {
    return data[column - row][row];
  }

  return zero;
}

template <class T>
T& UpperTriangularMatrix<T>::operator()(const int row, const int column)
{
  if (zero != 0)
  {
    zero = 0;
  }

  if(row <= column)
  {
    return data[column - row][row];
  }

  return zero;
}

template <class T>
AbstractMatrix<T>* UpperTriangularMatrix<T>::clone() const
{
  return new UpperTriangularMatrix<T>(*this);
}

template <class T>
const Vector<T> UpperTriangularMatrix<T>::getColumn(int column) const
{
  if(column < 0 || column >= dimensions)
  {
    throw std::invalid_argument("Column is outside of acceptable bounds");
  }

  Vector<T> x(dimensions);

  for(int i = 0; i < dimensions; i++)
  {
    if(column - i >= 0)
    {
      x[i] = data[column - i][i];
    }
  }
  return x;
}

template <class T>
DenseMatrix<T> operator* (const UpperTriangularMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  DenseMatrix<T> product(rhs.numRows(), rhs.numRows());

  for(int i = 0; i < rhs.numRows(); i++)
  {
    for(int j = 0; j < rhs.numRows(); j++)
    {
      product(i, j) = 0;
    }
  }

  T element = 0;

  for(int i = 0; i < rhs.numRows(); i++)
  {
    for(int k = 0; k < rhs.numRows(); k++)
    {
      for (int j = i; j < rhs.numRows(); j++)
      {
        element += lhs(i, j) * rhs(j, k);
      }
      product(i, k) = element;
      element = 0;
    }
  }
  return product;
}

template <class T>
UpperTriangularMatrix<T> operator* (const UpperTriangularMatrix<T>& lhs, const UpperTriangularMatrix<T>& rhs)
{
  UpperTriangularMatrix<T> product(lhs.numColumns());

  for(int i = 0; i < rhs.numRows(); i++)
  {
    for(int j = 0; j < rhs.numRows(); j++)
    {
      if(j >= i)
      {
        product(i, j) = 0;
      }
    }
  }

  T element = 0;

  for(int i = 0; i < rhs.numRows(); i++)
  {
    for(int k = 0; k < rhs.numRows(); k++)
    {
      for (int j = i; j < rhs.numRows(); j++)
      {
        element += lhs(i, j) * rhs(j, k);
      }
      product(i, k) = element;
      element = 0;
    }
  }
  return product;
}