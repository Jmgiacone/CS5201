template <class T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(const int d)
{
  dimensions = d;
  data = new Vector<T>[dimensions];

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
T& UpperTriangularMatrix<T>::operator()(const int row, const int column) const
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
Vector<T> UpperTriangularMatrix<T>::gaussElimination(Vector<T> bVector) const
{
  return bVector;
}

template <class T>
Vector<T> UpperTriangularMatrix<T>::vectorMultiplication(const Vector<T> &bVector) const
{
  return bVector;
}