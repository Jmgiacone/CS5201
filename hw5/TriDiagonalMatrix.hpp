//
// Created by Jordan on 4/5/2016.
//

template <class T>
TriDiagonalMatrix<T>::TriDiagonalMatrix(int r, int c)
{
  rows = r;
  columns = c;

  data = new Vector<T>[3];

  data[0] = Vector<T>(rows - 1);
  data[1] = Vector<T>(rows);
  data[2] = Vector<T>(rows - 1);
}

template <class T>
TriDiagonalMatrix<T>::TriDiagonalMatrix(const TriDiagonalMatrix<T>& rhs)
{
  rows = rhs.rows;
  columns = rhs.columns;

  data = new Vector<T>[3];

  data[0] = rhs.data[0];
  data[1] = rhs.data[1];
  data[2] = rhs.data[2];
}