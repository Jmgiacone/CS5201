#include <iomanip>
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
Matrix<T>& Matrix<T>::operator= (Matrix<T>&& rhs)
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
Matrix<T>& Matrix<T>::operator+= (Matrix<T>&& rhs)
{
  return (*this = (*this + rhs));
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& rhs)
{
  return (*this = (*this - rhs));
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (Matrix<T>&& rhs)
{
  return (*this = (*this - rhs));
}

template <class T>
int Matrix<T>::getRows() const
{
  return rows;
}

template <class T>
int Matrix<T>::getColumns() const
{
  return columns;
}

template <class T>
ostream& operator<< (ostream& out, const Matrix<T>& rhs)
{
  for(int i = 0; i < rhs.rows; i++)
  {
    for(int j = 0; j < rhs.columns; j++)
    {
      out << std::setw(8) << std::fixed << std::setprecision(5) << rhs[j][i] << "\t";
    }
    out << std::endl;
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
  if(!(lhs.rows == rhs.rows && lhs.columns == rhs.columns))
  {
    throw std::length_error("lhs and rhs are of differing dimensions");
  }

  Matrix<T> temp(lhs.rows, lhs.columns);

  for(int i = 0; i < temp.rows; i++)
  {
    temp.data[i] = lhs.data[i] - rhs.data[i];
  }

  return temp;
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
      temp[i][j] = lhs[i] * rhs[j];
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
  if(lhs.rows == rhs.columns && lhs.columns == rhs.rows)
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