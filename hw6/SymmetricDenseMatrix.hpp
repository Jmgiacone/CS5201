template <class T>
SymmetricDenseMatrix<T>::SymmetricDenseMatrix()
{
  dimensions = DEFAULT_DIMENSIONS;

  data = new Vector<T>[dimensions];

  for(int i = 0; i < dimensions; i++)
  {
    data[i] = Vector<T>(dimensions - i);
  }
}