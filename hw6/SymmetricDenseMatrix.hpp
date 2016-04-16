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