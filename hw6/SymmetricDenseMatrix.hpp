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
AbstractMatrix<T>& SymmetricDenseMatrix<T>::operator+=(const AbstractMatrix<T>& rhs)
{
  return *this = *this + dynamic_cast<const SymmetricDenseMatrix<T>&>(rhs);
}

template <class T>
AbstractMatrix<T>& SymmetricDenseMatrix<T>::operator-=(const AbstractMatrix<T>& rhs)
{
  return *this = *this + -dynamic_cast<const SymmetricDenseMatrix<T>&>(rhs);
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

template <class T>
SymmetricDenseMatrix<T> operator+ (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs)
{
  if(lhs.numRows() != rhs.numRows())
  {
    throw std::invalid_argument("SymmetricDenseMatrix: Matrices are of differing sizes");
  }
   SymmetricDenseMatrix<T> sum(lhs.dimensions);

  for(int i = 0; i < lhs.dimensions; i++)
  {
    lhs.data[i] = rhs.data[i];
  }

  return sum;
}

template <class T>
SymmetricDenseMatrix<T> operator- (const SymmetricDenseMatrix<T>& lhs, const SymmetricDenseMatrix<T>& rhs)
{
  return lhs + -rhs;
}

template <class T>
SymmetricDenseMatrix<T> operator- (const SymmetricDenseMatrix<T>& rhs)
{
  SymmetricDenseMatrix<T> negation(rhs.dimensions);

  for(int i = 0; i < rhs.dimensions; i++)
  {
    negation.data[i] = -rhs.data[i];
  }

  return negation;
}

template <class T>
ostream& SymmetricDenseMatrix<T>::output(ostream &out) const
{
  for(int i = 0; i < dimensions; i++)
  {
    for(int j = 0; j < dimensions; j++)
    {
      if(j != 0)
      {
        out << std::setw(10);
      }
      else if ((*this)(i, j) >= 0)
      {
        out << " ";
      }
      out << std::fixed << std::setprecision(5) << (*this)(i, j) << "\t";
    }

    if (i == dimensions - 1)
    {

    }
    else
    {
      out << std::endl;
    }
  }

  return out;
}

template <class T>
Vector<T> SymmetricDenseMatrix<T>::gaussianElimination(Vector<T> bVector) const
{
  //TODO: This

  return bVector;
}

template <class T>
Vector<T> SymmetricDenseMatrix<T>::vectorMultiplication(const Vector<T>& bVector) const
{
  //Todo: This

  return bVector;
}