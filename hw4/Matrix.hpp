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
const T& Matrix<T>::operator[] (int x) const
{
  if(x < 0 || x >= rows)
  {
    throw std::out_of_range("Illegal argument provided to Matrix []");
  }

  return data[x];
}

template <class T>
T& Matrix<T>::operator[](int x)
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