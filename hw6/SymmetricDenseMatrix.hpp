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