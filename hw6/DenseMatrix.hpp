/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: DenseMatrix.hpp
 * Description: Implementation file for DenseMatrix class
 */

#include <iomanip>
#include <cmath>
#include <stdexcept>
template <class T>
DenseMatrix<T>::DenseMatrix()
{
  rows = DEFAULT_ROWS;
  columns = DEFAULT_COLUMNS;
  data = new Vector<T>[rows];

  for(int i = 0; i < rows; i++)
  {
    Vector<T> temp(columns);

    data[i] = temp;
  }
}

template <class T>
DenseMatrix<T>::DenseMatrix(int r, int c)
{
  if(r < 1 || c < 1)
  {
    throw std::invalid_argument("DenseMatrix Error. Attempt to initialize with values less than 1");
  }

  rows = r;
  columns = c;

  data = new Vector<T>[rows];

  for(int i = 0; i < rows; i++)
  {
    Vector<T> temp(columns);

    data[i] = temp;
  }
}

template <class T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& src)
{
  rows = src.rows;
  columns = src.columns;
  data = new Vector<T>[rows];

  for(int i = 0; i < rows; i++)
  {
    data[i] = src[i];
  }
}

template <class T>
DenseMatrix<T>::DenseMatrix(DenseMatrix<T>&& src)
{
  rows = src.rows;
  columns = src.columns;
  data = src.data;
  src.data = NULL;
}

template <class T>
DenseMatrix<T>::~DenseMatrix()
{
  if(data != NULL)
  {
    delete [] data;
  }

  rows = 0;
  columns = 0;
  data = NULL;
}

template <class T>
const Vector<T> DenseMatrix<T>::getColumn(int x) const
{
  if(x < 0 || x >= columns)
  {
    throw std::out_of_range("Error: getColumn parameter is illegal");
  }

  Vector<T> tmp(rows);

  for(int i = 0; i < rows; i++)
  {
    tmp[i] = (*this)[i][x];
  }

  return tmp;
}

template <class T>
const Vector<T>& DenseMatrix<T>::operator[] (int x) const
{
  if(x < 0 || x >= rows)
  {
    throw std::out_of_range("Illegal argument provided to DenseMatrix []");
  }

  return data[x];
}

template <class T>
Vector<T>& DenseMatrix<T>::operator[](int x)
{
  if(x < 0 || x >= rows)
  {
    throw std::out_of_range("Illegal argument provided to DenseMatrix []");
  }

  return data[x];
}

template <class T>
DenseMatrix<T>& DenseMatrix<T>::operator= (DenseMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}
template <class T>
DenseMatrix<T>& DenseMatrix<T>::operator+= (const DenseMatrix<T>& rhs)
{
  return (*this = (*this + rhs));
}

template <class T>
DenseMatrix<T>& DenseMatrix<T>::operator-= (const DenseMatrix<T>& rhs)
{
  return (*this = (*this - rhs));
}

template <class T>
int DenseMatrix<T>::numRows() const
{
  return rows;
}

template <class T>
int DenseMatrix<T>::numColumns() const
{
  return columns;
}

template <class T>
istream& operator>> (istream&in, DenseMatrix<T>& rhs)
{
  for(int i = 0; i < rhs.rows; i++)
  {
    in >> rhs.data[i];
  }

  return in;
}

template <class T>
DenseMatrix<T> operator+ (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  if(!(lhs.rows == rhs.rows && lhs.columns == rhs.columns))
  {
    throw std::length_error("Operator+ - lhs and rhs have differing dimensions");
  }

  DenseMatrix<T> tmp(lhs);

  for(int i = 0; i < rhs.rows; i++)
  {
    for(int j = 0; j < rhs.columns; j++)
    {
      tmp.data[i][j] += rhs.data[i][j];
    }
  }

  return tmp;
}

template <class T>
DenseMatrix<T> operator- (const DenseMatrix<T>& rhs)
{
  DenseMatrix<T> temp(rhs.rows, rhs.columns);

  for(int i = 0; i < rhs.rows; i++)
  {
    rhs.data[i] = -rhs[i];
  }

  return temp;
}

template <class T>
DenseMatrix<T> operator- (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  return (lhs + (-rhs));
}

template <class T>
DenseMatrix<T> operator* (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  if(lhs.columns != rhs.rows)
  {
    throw std::length_error("Middle dimensions do not match!");
  }

  DenseMatrix<T> temp(lhs.rows, rhs.columns);

  for(int i = 0; i < temp.rows; i++)
  {
    for(int j = 0; j < temp.columns; j++)
    {
      temp[i][j] = lhs[i] * rhs.getColumn(j);
    }
  }

  return temp;
}

template <class T>
Vector<T> operator* (const DenseMatrix<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.columns != rhs.numTerms())
  {
    throw std::length_error("DenseMatrix and Vector have differing dimensions!");
  }

  Vector<T> temp(lhs.rows);
  for(int i = 0; i < lhs.rows; i++)
  {
    temp[i] = lhs[i] * rhs;
  }

  return temp;
}

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const DenseMatrix<T>& rhs)
{
  return (rhs * lhs);
}

template <class T>
T operator* (const T& lhs, const DenseMatrix<T>& rhs)
{
  DenseMatrix<T> temp(rhs.rows, rhs.columns);

  for(int i = 0; i < rhs.rows; i++)
  {
    for(int j = 0; j < rhs.columns; j++)
    {
      temp[i][j] = lhs * rhs[i][j];
    }
  }
}

template <class T>
T operator* (const DenseMatrix<T>& lhs, const T& rhs)
{
  return (rhs * lhs);
}

template <class T>
bool operator== (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  if(lhs.rows == rhs.rows && lhs.columns == rhs.columns)
  {
    for(int i = 0; i < rhs.rows; i++)
    {
      for(int j = 0; j < rhs.columns; j++)
      {
        if(lhs.data[i][j] != rhs[i][j])
        {
          return false;
        }
      }
    }
    return true;
  }

  return false;
}

template <class T>
bool operator!= (const DenseMatrix<T>& lhs, const DenseMatrix<T>& rhs)
{
  return !(lhs == rhs);
}

template <class T>
void swap(DenseMatrix<T>& x, DenseMatrix<T>& y)
{
  std::swap(x.rows, y.rows);
  std::swap(x.columns, y.columns);
  std::swap(x.data, y.data);
}

template <class T>
T& DenseMatrix<T>::operator()(int row, int column)
{
  if(row < 0 || row >= rows || column < 0 || column >= columns)
  {
    throw std::out_of_range("Illegal argument provided to DenseMatrix []");
  }

  return (*this)[row][column];
}

template <class T>
const T& DenseMatrix<T>::operator()(const int row, const int column) const
{
  if(row < 0 || row >= rows || column < 0 || column >= columns)
  {
    throw std::out_of_range("Illegal argument provided to DenseMatrix []");
  }

  return data[row][column];
}

template <class T>
AbstractMatrix<T>* DenseMatrix<T>::clone() const
{
  return new DenseMatrix<T>(*this);
}