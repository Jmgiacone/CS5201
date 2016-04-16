template <class T>
SymmetricDenseMatrix<T>::SymmetricDenseMatrix(const int d)
{
  dimensions = d;

  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = Vector<T>(dimensions - i);
  }
}

template <class T>
SymmetricDenseMatrix<T>::SymmetricDenseMatrix(const SymmetricDenseMatrix<T>& src)
{
  dimensions = src.dimensions;
  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = src.data[i];
  }
}

template <class T>
SymmetricDenseMatrix<T>::~SymmetricDenseMatrix()
{
  if(data != NULL)
  {
    delete [] data;
  }
}

template <class T>
SymmetricDenseMatrix<T>& SymmetricDenseMatrix<T>::operator=(SymmetricDenseMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <class T>
AbstractMatrix<T>& SymmetricDenseMatrix<T>::operator+=(const AbstractMatrix<T> &rhs)
{
  return *this = *this + static_cast<SymmetricDenseMatrix>(rhs);
}

template <class T>
AbstractMatrix<T>& SymmetricDenseMatrix<T>::operator-=(const AbstractMatrix<T>& rhs)
{
  return *this = *this + -static_cast<SymmetricDenseMatrix>(rhs);
}

template <class T>
T& SymmetricDenseMatrix<T>::operator()(const int row, const int column) const
{
  if(column < 0 || column >= dimensions || row < 0 || row >= dimensions)
  {
    throw std::invalid_argument("SymmetricDenseMatrix: Indices provided to operator() are invalid");
  }

  if(column < row)
  {
    return (*this)(column, row);
  }

  return data[row][column];
}

template <class T>
T& SymmetricDenseMatrix<T>::operator()(const int row, const int column)
{
  if(column < 0 || column >= dimensions || row < 0 || row >= dimensions)
  {
    throw std::invalid_argument("SymmetricDenseMatrix: Indices provided to operator() are invalid");
  }

  if(column < row)
  {
    return (*this)(column, row);
  }

  return data[row][column];
}

template <class T>
AbstractMatrix<T>* SymmetricDenseMatrix<T>::clone() const
{
  return new SymmetricDenseMatrix(*this);
}

template <class T>
void SymmetricDenseMatrix<T>::swap(SymmetricDenseMatrix<T> &lhs, SymmetricDenseMatrix<T> &rhs)
{
  std::swap(lhs.dimensions, rhs.dimensions);
  std::swap(lhs.data, rhs.data);
}