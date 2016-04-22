/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: DiagonaltMatrix.hpp
 * Description: This is the implementation file for the DiagonalMatrix class
 */
template <class T>
DiagonalMatrix<T>::DiagonalMatrix(int d)
{
  dimensions = d;

  data = Vector<T>(dimensions);
}

template <class T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& src)
{
  dimensions = src.dimensions;

  data = src.data;
}

template <class T>
DiagonalMatrix<T>& DiagonalMatrix<T>::operator+=(const DiagonalMatrix<T> &rhs)
{
  return *this = *this + rhs;
}

template <class T>
DiagonalMatrix<T>& DiagonalMatrix<T>::operator-=(const DiagonalMatrix<T> &rhs)
{
  return *this = *this - rhs;
}

template <class T>
T& DiagonalMatrix<T>::operator()(const int row, const int column)
{
  zero = 0;
  if(row < 0 || row >= dimensions || column < 0 || column >= dimensions)
  {
    throw std::invalid_argument("DiagonalMatrix::(): Invalid row/column");
  }

  if(row == column)
  {
    return data[row];
  }

  return zero;
}

template <class T>
const T& DiagonalMatrix<T>::operator()(const int row, const int column) const
{
  if(row < 0 || row >= dimensions || column < 0 || column >= dimensions)
  {
    throw std::invalid_argument("DiagonalMatrix::(): Invalid row/column");
  }

  if(row == column)
  {
    return data[row];
  }

  return zero;
}

template <class T>
AbstractMatrix<T>* DiagonalMatrix<T>::clone() const
{
  return new DiagonalMatrix<T>(*this);
}

template <class T>
DiagonalMatrix<T> operator+ (const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs)
{
  if(lhs.dimensions != rhs.dimensions)
  {
    throw std::invalid_argument("DiagonalMatrix::+: Matrices are of different sizes");
  }

  DiagonalMatrix<T> sum(lhs.dimensions);

  sum.data = lhs.data + rhs.data;

  return sum;
}

template <class T>
DiagonalMatrix<T> operator- (const DiagonalMatrix<T>& lhs, const DiagonalMatrix<T>& rhs)
{
  return lhs + -rhs;
}

template <class T>
DiagonalMatrix<T> operator- (const DiagonalMatrix<T>& rhs)
{
  DiagonalMatrix<T> negation(rhs.dimensions);

  negation.data = -rhs.data;

  return negation;
}

template <class T>
const Vector<T> DiagonalMatrix<T>::getColumn(const int column) const
{
  if(column < 0 || column >= numColumns())
  {
    throw std::invalid_argument("Invalid column provided");
  }

  Vector<T> columnVector(numColumns());

  for(int i = 0; i < numColumns(); i++)
  {
    columnVector[i] = 0;
  }
  columnVector[column] = data[column];

  return columnVector;
}

template <class T>
DiagonalMatrix<T> operator* (const DiagonalMatrix<T>& lhs, DiagonalMatrix<T>& rhs)
{
  DiagonalMatrix<T> product(lhs.dimensions);

  for(int i = 0; i < lhs.dimensions; i++)
  {
    product.data[i] = lhs.data[i] * rhs.data[i];
  }

  return product;
}