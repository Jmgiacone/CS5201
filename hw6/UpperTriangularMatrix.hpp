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
UpperTriangularMatrix::~UpperTriangularMatrix()
{
  if (data != NULL)
  {
    delete[] data;
    data = NULL;
  }
}

