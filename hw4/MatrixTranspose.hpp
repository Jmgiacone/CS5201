template <class T>
Matrix<T> MatrixTranspose<T>::operator()(const Matrix<T>& m)
{
  Matrix<T> transpose(m.getColumns(), m.getRows());

  for(int i = 0; i < m.getRows(); i++)
  {
    for(int j = 0; j < m.getColumns(); j++)
    {
      transpose[j][i] = m[i][j];
    }
  }

  return transpose;
}