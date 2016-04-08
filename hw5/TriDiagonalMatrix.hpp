/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
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

template <class T>
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
}

/*template <class T>
const SmartVector<T> TriDiagonalMatrix<T>::operator[] (int x)
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
std::ostream& TriDiagonalMatrix<T>::output(std::ostream& out) const
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (j != 0)
      {
        out << std::setw(10);
      }
      else if ((*this)[i][j] >= 0)
      {
        out << " ";
      }
      out << std::fixed << std::setprecision(5) << (*this)[i][j] << " ";//"\t";
    }

    if (i == rows - 1)
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
Vector<T> TriDiagonalMatrix<T>::gaussElimation(Vector<T> bVector) const
{
  Vector<T> xVector(bVector);
  //TriDiagonalMatrix<T> aMatrix(*this);
  Vector<T>* diagonals = new Vector<T>[3];
  diagonals[0] = data[0];
  diagonals[1] = data[1];
  diagonals[2] = data[2];
  //Implement Adam's Algorithm

  //i = 0 -> ci' = ci/bi
  diagonals[2][0] /= diagonals[1][0];

  //i = 0 -> di' = di/bi
  bVector[0] /= diagonals[1][0];

  //ci' = ci / (bi - ai * ci-1')
  //di' = (di - ai * di-1') / (bi - ai * ci-1')
  for(int i = 1; i < diagonals[2].numTerms(); i++)
  {
    diagonals[2][i] /= diagonals[1][i] - diagonals[0][i-1] * diagonals[2][i-1];
    bVector[i] = (bVector[i] - diagonals[0][i-1] * bVector[i-1]) / (diagonals[1][i] - diagonals[0][i-1] * diagonals[2][i-1]);
  }

  xVector[xVector.numTerms() - 1] = bVector[xVector.numTerms() - 1];
  for(int i = xVector.numTerms() - 2; i >= 0; i--)
  {
    xVector[i] = bVector[i] - diagonals[2][i] * xVector[i + 1];
  }

  return xVector;
}

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
const Matrix<T> operator* (const TriDiagonalMatrix<T>& lhs, const TriDiagonalMatrix<T>& rhs)
{
  if(lhs.columns != rhs.rows)
  {
    throw std::invalid_argument("TriDiag * error: Matrix-Matrix dimensions don't match");
  }

  Matrix<T> result(lhs.rows, rhs.columns);

  return result;
}

template <class T>
const Vector<T> operator* (const TriDiagonalMatrix<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.columns != rhs.numTerms())
  {
    throw std::invalid_argument("TriDiag * error: Matrix-vector dimensions don't match");
  }

  Vector<T> result(lhs.rows);
  int numMults, startIndex;
  for(int i = 0; i < lhs.rows; i++)
  {
    SmartVector<T> row = lhs[i];

    if(i == 0)
    {
      numMults = 2;
      startIndex = 0;
    }
    else if(i == 1)
    {
      numMults = 3;
      startIndex = 0;
    }
    else if(i == lhs.rows - 1)
    {
      numMults = 2;
      startIndex = i - 1;
    }
    else
    {
      numMults = 3;
      startIndex = i - 1;
    }

    for(int j = 0; j < numMults; j++)
    {
      result[i] += row[startIndex] * rhs[startIndex];
      startIndex++;
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