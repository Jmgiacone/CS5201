/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 4
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: Matrix.hpp
 * Description: Implementation file for Matrix class
 */

#include <iomanip>
#include <cmath>
#include <stdexcept>
template <class T>
Matrix<T>::Matrix()
{
  rows = DEFAULT_ROWS;
  columns = DEFAULT_COLUMNS;
  data = new Vector<T>[rows];

  for(int i = 0; i < rows; i++)
  {
    Vector<T> temp(columns);

    data[i] = temp;
  }
}

template <class T>
Matrix<T>::Matrix(int r, int c)
{
  if(r < 1 || c < 1)
  {
    throw std::invalid_argument("Matrix Error. Attempt to initialize with values less than 1");
  }

  rows = r;
  columns = c;

  data = new Vector<T>[rows];

  for(int i = 0; i < rows; i++)
  {
    Vector<T> temp(columns);

    data[i] = temp;
  }
}

template <class T>
Vector<T> Matrix<T>::gaussElimation(Vector<T> b) const
{
  Matrix<T> a(*this);
  if(a.numRows() != b.numTerms())
  {
    //B vector isn't same size as input matrix
    throw std::invalid_argument("Dimension mismatch! input matrix and answer vector are of differening dimensions");
  }
  else if(a.numRows() != a.numColumns())
  {
    //Non-square Matrix
    throw std::invalid_argument("Input Matrix is not square! Please only use Gaussian Elimination on a square or Augmented Matrix");
  }
  Matrix<T> augmented(a.numRows(), a.numColumns()+1);
  Vector<T> result(a.numRows());

  //Create an augmented matrix from A and B
  for(int i = 0; i < augmented.numRows(); i++)
  {
    for(int j = 0; j < augmented.numColumns()-1; j++)
    {
      augmented[i][j] = a[i][j];
    }
    augmented[i][augmented.numColumns()-1] = b[i];
  }

  augmented = elim(augmented, true);

  for(int i = 0; i < result.numTerms(); i++)
  {
    result[i] = augmented[i][augmented.numColumns()-1];
  }

  return result;
}

template <class T>
Matrix<T> Matrix<T>::elim(Matrix <T> a, bool pivoting) const
{
  if (a.numRows() != a.numColumns() - 1)
  {
    //Matrix is not augmented
    throw std::invalid_argument("Input Matrix is not augmented (Rows != Columns - 1)");
  }
  else if (a.numRows() == 0 || a.numColumns() == 0)
  {
    //Zero Dimensions
    throw std::invalid_argument("Matrix dimensions are zero!");
  }

  int numMultipliers = a.numRows() - 1;
  if (numMultipliers > 0)
  {
    T *multipliers = new T[numMultipliers];

    //Forward Elimination
    for (int i = 0; i < a.numRows(); i++)
    {
      for (int j = i + 1; j < a.numColumns() - 1; j++)
      {
        if (pivoting)
        {
          //Search for largest magnitude
          T largestMagnitude = std::abs(a[i][i]), tmp;
          int largestMagnitudeIndex = i;

          for (int l = i + 1; l < a.numRows(); l++)
          {
            tmp = std::abs(a[l][i]);

            if (tmp > largestMagnitude)
            {
              largestMagnitude = tmp;
              largestMagnitudeIndex = l;
            }
          }
          if (largestMagnitudeIndex != i)
          {
            swap(a[i], a[largestMagnitudeIndex]);
          }
        }

        if (a[i][i] == 0)
        {
          throw std::domain_error("Attempted Division by zero in forward elimination");
        }

        multipliers[j - i - 1] = a[j][i] / a[i][i];
        a[j][i] = 0;
        for (int k = i + 1; k < a.numColumns(); k++)
        {
          a[j][k] = a[j][k] - multipliers[j - i - 1] * a[i][k];
        }
      }
    }

    //Back substitution
    for (int i = a.numRows() - 1; i >= 0; i--)
    {
      for (int j = a.numColumns() - 2; j > i; j--)
      {
        a[i][a.numColumns() - 1] = a[i][a.numColumns() - 1] - a[j][a.numColumns() - 1] * a[i][j];
        a[i][j] = 0;
      }

      if (a[i][i] == 0)
      {
        throw std::domain_error("Attempted Division by zero in backward substitution");
      }
      a[i][a.numColumns() - 1] = a[i][a.numColumns() - 1] / a[i][i];
      a[i][i] = 1;
    }
    delete[] multipliers;
  }

  return a;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& src)
{
  rows = src.rows;
  columns = src.columns;
  data = new Vector<T>[rows];

  for(int i = 0; i < rows; i++)
  {
    data[i] = src[i];
  }
}

template <class T>
Matrix<T>::Matrix(Matrix<T>&& src)
{
  rows = src.rows;
  columns = src.columns;
  data = src.data;
  src.data = NULL;
}

template <class T>
Matrix<T>::~Matrix()
{
  if(data != NULL)
  {
    delete [] data;
  }

  rows = 0;
  columns = 0;
  data = NULL;
}

template <class T>
const Vector<T> Matrix<T>::getColumn(int x) const
{
  if(x < 0 || x >= columns)
  {
    throw std::out_of_range("Error: getColumn parameter is illegal");
  }

  Vector<T> tmp(rows);

  for(int i = 0; i < rows; i++)
  {
    tmp[i] = (*this)[i][x];
  }

  return tmp;
}

template <class T>
const Vector<T>& Matrix<T>::operator[] (int x) const
{
  if(x < 0 || x >= rows)
  {
    throw std::out_of_range("Illegal argument provided to Matrix []");
  }

  return data[x];
}

template <class T>
Vector<T>& Matrix<T>::operator[](int x)
{
  if(x < 0 || x >= rows)
  {
    throw std::out_of_range("Illegal argument provided to Matrix []");
  }

  return data[x];
}

template <class T>
Matrix<T>& Matrix<T>::operator= (Matrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}
template <class T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T>& rhs)
{
  return (*this = (*this + rhs));
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& rhs)
{
  return (*this = (*this - rhs));
}

template <class T>
int Matrix<T>::numRows() const
{
  return rows;
}

template <class T>
int Matrix<T>::numColumns() const
{
  return columns;
}

template <class T>
ostream& Matrix<T>::output(ostream& out) const
{
  for(int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (j != 0)
      {
        out << std::setw(10);
      }
      else if (data[i][j] >= 0)
      {
        out << " ";
      }
      out << std::fixed << std::setprecision(5) << data[i][j] << "\t";
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
istream& operator>> (istream&in, Matrix<T>& rhs)
{
  for(int i = 0; i < rhs.rows; i++)
  {
    in >> rhs.data[i];
  }

  return in;
}

template <class T>
Matrix<T> operator+ (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  if(!(lhs.rows == rhs.rows && lhs.columns == rhs.columns))
  {
    throw std::length_error("Operator+ - lhs and rhs have differing dimensions");
  }

  Matrix<T> tmp(lhs);

  for(int i = 0; i < rhs.rows; i++)
  {
    for(int j = 0; j < rhs.columns; j++)
    {
      tmp.data[i][j] += rhs.data[i][j];
    }
  }

  return tmp;
}

template <class T>
Matrix<T> operator- (const Matrix<T>& rhs)
{
  Matrix<T> temp(rhs.rows, rhs.columns);

  for(int i = 0; i < rhs.rows; i++)
  {
    rhs.data[i] = -rhs[i];
  }

  return temp;
}

template <class T>
Matrix<T> operator- (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return (lhs + (-rhs));
}

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  if(lhs.columns != rhs.rows)
  {
    throw std::length_error("Middle dimensions do not match!");
  }

  Matrix<T> temp(lhs.rows, rhs.columns);

  for(int i = 0; i < temp.rows; i++)
  {
    for(int j = 0; j < temp.columns; j++)
    {
      temp[i][j] = lhs[i] * rhs.getColumn(j);
    }
  }

  return temp;
}

template <class T>
Vector<T> operator* (const Matrix<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.columns != rhs.numTerms())
  {
    throw std::length_error("Matrix and Vector have differing dimensions!");
  }

  Vector<T> temp(lhs.rows);
  for(int i = 0; i < lhs.rows; i++)
  {
    temp[i] = lhs[i] * rhs;
  }

  return temp;
}

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const Matrix<T>& rhs)
{
  return (rhs * lhs);
}

template <class T>
T operator* (const T& lhs, const Matrix<T>& rhs)
{
  Matrix<T> temp(rhs.rows, rhs.columns);

  for(int i = 0; i < rhs.rows; i++)
  {
    for(int j = 0; j < rhs.columns; j++)
    {
      temp[i][j] = lhs * rhs[i][j];
    }
  }
}

template <class T>
T operator* (const Matrix<T>& lhs, const T& rhs)
{
  return (rhs * lhs);
}

template <class T>
bool operator== (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  if(lhs.rows == rhs.rows && lhs.columns == rhs.columns)
  {
    for(int i = 0; i < rhs.rows; i++)
    {
      for(int j = 0; j < rhs.columns; j++)
      {
        if(lhs.data[i][j] != rhs[i][j])
        {
          return false;
        }
      }
    }
    return true;
  }

  return false;
}

template <class T>
bool operator!= (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return !(lhs == rhs);
}

template <class T>
void swap(Matrix<T>& x, Matrix<T>& y)
{
  std::swap(x.rows, y.rows);
  std::swap(x.columns, y.columns);
  std::swap(x.data, y.data);
}
