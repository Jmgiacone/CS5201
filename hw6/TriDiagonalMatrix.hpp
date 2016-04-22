/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: TriDiagonalMatrix.hpp
 * Description: This is the implementation file for the TriDiagonalMatrix
 */
template <class T>
TriDiagonalMatrix<T>::TriDiagonalMatrix(int r, int c)
{
  rows = r;
  columns = c;

  data = new Vector<T>[NUM_DIAGONALS];

  data[0] = Vector<T>(rows - 1);
  data[1] = Vector<T>(rows);
  data[2] = Vector<T>(rows - 1);
}

template <class T>
TriDiagonalMatrix<T>::TriDiagonalMatrix(int r, int c, const Vector<T> &diag1, const Vector<T> &diag2,
                                        const Vector<T> &diag3)
{
  rows = r;
  columns = c;
  data = new Vector<T>[3];

  if(!(diag1.numTerms() == rows - 1 && diag2.numTerms() == rows && diag3.numTerms() == rows - 1))
  {
    throw std::invalid_argument("TriDiag Constructor Error: Diagonal parameters invalid size");
  }

  data[0] = diag1;
  data[1] = diag2;
  data[2] = diag3;
}


template <class T>
TriDiagonalMatrix<T>::TriDiagonalMatrix(const TriDiagonalMatrix<T>& rhs)
{
  rows = rhs.rows;
  columns = rhs.columns;

  for(int i = 0; i < NUM_DIAGONALS; i++)
  {
    data[i] = rhs.data[i];
  }
}

template <class T>
TriDiagonalMatrix<T>::~TriDiagonalMatrix()
{
  delete [] data;
}

template <class T>
TriDiagonalMatrix<T>& TriDiagonalMatrix<T>::operator= (TriDiagonalMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <class T>
void TriDiagonalMatrix<T>::swap(TriDiagonalMatrix<T>& x, TriDiagonalMatrix<T>& y)
{
  std::swap(x.rows, y.rows);
  std::swap(x.data, y.data);
}

template <class T>
TriDiagonalMatrix<T>& TriDiagonalMatrix<T>::operator+= (const TriDiagonalMatrix<T>& rhs)
{
  return (*this = *this + rhs);
}

template <class T>
TriDiagonalMatrix<T>& TriDiagonalMatrix<T>::operator-=(const TriDiagonalMatrix<T> &rhs)
{
  return (*this = *this - rhs);
}

/*template <class T>
const SmartVector<T> TriDiagonalMatrix<T>::operator[](int x) const
{
  T** vect = new T*[columns];

  for(int i = 0; i < columns; i++)
  {
    vect[i] = NULL;
  }

  if(x < 0 || x >= rows)
  {
    throw std::invalid_argument("TriDiagonal [] error: Out of bounds");
  }

  int numData = 3, startingDiag = 0, vectStartSpot = x - 1;
  if(x == 0)
  {
    numData = 2;
    startingDiag = 1;
    vectStartSpot = 0;
  }
  else if(x == 1)
  {
    vectStartSpot = 0;
  }
  else if(x == rows - 1)
  {
    numData = 2;
    startingDiag = 0;
    vectStartSpot = columns - 2;
  }

  vectStartSpot = vectStartSpot < 0 ? 0 : vectStartSpot;
  for(int i = 0; i < numData; i++)
  {
    vect[vectStartSpot] = &data[startingDiag][startingDiag == 0 ? x - 1 : x];
    startingDiag++;
    vectStartSpot++;
  }

  return SmartVector<T>(columns, vect);
}*/

template <class T>
const TriDiagonalMatrix<T> operator+ (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs)
{
  if(lhs.rows == rhs.rows && lhs.columns == rhs.columns)
  {
    TriDiagonalMatrix<T> result(lhs.rows, lhs.columns);

    for(int i = 0; i < NUM_DIAGONALS; i++)
    {
      result.data[i] = lhs.data[i] + rhs.data[i];
    }

    return result;
  }
  throw std::invalid_argument("Operator+ Error: TriDiagonalMatrix dimensions do not match!");
}

template <class T>
const TriDiagonalMatrix<T> operator- (const TriDiagonalMatrix<T>& rhs)
{
  TriDiagonalMatrix<T> result(rhs.rows, rhs.columns);

  for(int i = 0; i < NUM_DIAGONALS; i++)
  {
    result.data[i] = -rhs.data[i];
  }

  return result;
}

template <class T>
const TriDiagonalMatrix<T> operator- (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs)
{
  return lhs + -rhs;
}

//TODO Finish this function
template <class T>
const DenseMatrix<T> operator* (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs)
{
  if(lhs.columns != rhs.rows)
  {
    throw std::invalid_argument("TriDiag * error: Matrix-Matrix dimensions don't match");
  }

  DenseMatrix<T> result(lhs.rows, rhs.columns);

  //Zero-out the result
  for(int i = 0; i < result.numRows(); i++)
  {
    for(int j = 0; j < result.numColumns(); j++)
    {
      result(i, j) = 0;
    }
  }

  for(int i = 0; i < result.numRows(); i++)
  {
    for(int j = 0; j < result.numColumns(); j++)
    {
      result(i, j) = lhs.getRow(i) * rhs.getColumn(j);
    }
  }

  return result;
}

template <class T>
bool operator== (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs)
{
  for(int i = 0; i < NUM_DIAGONALS; i++)
  {
    if(lhs.data[i] != rhs.data[i])
    {
      return false;
    }
  }

  return true;
}

template <class T>
bool operator!= (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs)
{
  return !(lhs == rhs);
}

template <class T>
const Vector<T> TriDiagonalMatrix<T>::getColumn(const int column) const
{
  if(column < 0 || column >= numColumns())
  {
    throw std::invalid_argument("Column number is invalid");
  }

  Vector<T> columnVector(numColumns());

  for(int i = 0; i < columnVector.numTerms(); i++)
  {
    columnVector[i] = 0;
  }

  if(column == 0)
  {
    columnVector[0] = data[1][column];
    columnVector[1] = data[0][column];
  }
  else if(column == numColumns() - 1)
  {
    columnVector[column - 1] = data[2][column - 1];
    columnVector[column] = data[1][column];
  }
  else
  {
    columnVector[column - 1] = data[2][column - 1];
    columnVector[column] = data[1][column];
    columnVector[column + 1] = data[0][column];
  }
  return columnVector;
}

template <class T>
const T& TriDiagonalMatrix<T>::operator()(const int row, const int column) const
{
  if(row <= column + 1 && column <= row + 1)
  {
    //It's a real value in the matrix

    //We're on the diagonal
    if(row == column)
    {
      return data[1][column];
    }
    else if(column > row)
    {
      return data[2][column - 1];
    }
    return data[0][column];
  }

  return zero;
}

template <class T>
T& TriDiagonalMatrix<T>::operator()(const int row, const int column)
{
  if(zero != 0)
  {
    zero = 0;
  }

  if(row <= column + 1 && column <= row + 1)
  {
    //It's a real value in the matrix

    //We're on the diagonal
    if(row == column)
    {
      return data[1][column];
    }
    else if(column > row)
    {
      return data[2][column - 1];
    }
    return data[0][column];
  }

  return zero;
}

template <class T>
AbstractMatrix<T>* TriDiagonalMatrix<T>::clone() const
{
  return new TriDiagonalMatrix<T>(*this);
}

template <class T>
Vector<T> TriDiagonalMatrix<T>::getRow(int x) const
{
  Vector<T> vect(numColumns());

  if(x < 0 || x >= rows)
  {
    throw std::invalid_argument("TriDiagonal [] error: Out of bounds");
  }

  for(int i = 0; i < numColumns(); i++)
  {
    vect[i] = 0;
  }

  int numData = 3, startingDiag = 0, vectStartSpot = x - 1;
  if(x == 0)
  {
    numData = 2;
    startingDiag = 1;
    vectStartSpot = 0;
  }
  else if(x == 1)
  {
    vectStartSpot = 0;
  }
  else if(x == rows - 1)
  {
    numData = 2;
    startingDiag = 0;
    vectStartSpot = columns - 2;
  }

  vectStartSpot = vectStartSpot < 0 ? 0 : vectStartSpot;
  for(int i = 0; i < numData; i++)
  {
    vect[vectStartSpot] = data[startingDiag][startingDiag == 0 ? x - 1 : x];
    startingDiag++;
    vectStartSpot++;
  }

  return vect;
}