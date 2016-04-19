//
// Created by jordan on 4/9/16.
//
template <class T>
DiagonalMatrix<T>::DiagonalMatrix(int d)
{
  dimensions = d;

  data = new Vector<T>[dimensions];
}

template <class T>
DiagonalMatrix<T>::DiagonalMatrix(const DiagonalMatrix<T>& src)
{
  dimensions = src.dimensions;
  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = src.data[i];
  }
}

template <class T>
DiagonalMatrix<T>::~DiagonalMatrix()
{
  if(data != NULL)
  {
    delete [] data;
    data = NULL;
  }
}

template <class T>
AbstractMatrix<T>& DiagonalMatrix<T>::operator+=(const AbstractMatrix<T> &rhs)
{
  return *this = *this + dynamic_cast<const DiagonalMatrix<T>&>(rhs);
}

template <class T>
AbstractMatrix<T>& DiagonalMatrix<T>::operator-=(const AbstractMatrix<T> &rhs)
{
  return *this = *this - dynamic_cast<const DiagonalMatrix<T>&>(rhs);
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
T& DiagonalMatrix<T>::operator()(const int row, const int column) const
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

  for(int i = 0; i < rhs.dimensions; i++)
  {
    sum.data[i] = lhs.data[i] + rhs.data[i];
  }

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

  for(int i = 0; i < rhs.dimensions; i++)
  {
    negation.data[i] = -rhs.data[i];
  }

  return negation;
}

template <class T>
Vector<T> DiagonalMatrix<T>::gaussianElimination(Vector<T> bVector) const
{
  return bVector;
}

template <class T>
Vector<T> DiagonalMatrix<T>::vectorMultiplication(const Vector<T> &bVector) const
{
  return bVector;
}