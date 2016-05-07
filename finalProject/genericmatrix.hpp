#include <cstdio>

/**
 *  @file genericmatrix.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Mar 13, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
GenericMatrix<T>::GenericMatrix(const GenericMatrix<T>& rhs) :
    UnrestrictedDimMatrix<T>(rhs), RefBasedMatrix<T>(rhs), m_data(rhs.m_data)
{
  this->initReferenceDims();
}

template<typename T>
GenericMatrix<T>::GenericMatrix(GenericMatrix<T> && rhs) :
    m_data(std::move(rhs.m_data))
{
  this->m_transposed = std::move(rhs.m_transposed);
  this->m_num_rows = std::move(rhs.m_num_rows);
  this->m_num_cols = std::move(rhs.m_num_cols);
  this->initReferenceDims();
}

template<typename T>
GenericMatrix<T>::GenericMatrix(const AbstractMatrix<T>& rhs)
{
  this->m_num_rows = rhs.rows();
  this->m_num_cols = rhs.columns();
  this->m_transposed = false;
  m_data.reserve(rhs.rows());
  for (size_t i = 0; i < rhs.rows(); i++)
  {
    m_data[i] = rhs[i];
  }
  this->initReferenceDims();
}

template<typename T>
GenericMatrix<T>::GenericMatrix(const DynamicArray<AlgebraVector<T> >& data)
{
  this->m_transposed = false;
  this->m_num_rows = data.size();
  this->m_num_cols = data.size() ? data[0].size() : 0;
  m_data.reserve(data.size());
  for (size_t i = 0; i < data.size(); i++)
  {
    m_data[i] = data[i];
  }
  this->initReferenceDims();
}

template<typename T>
GenericMatrix<T>::GenericMatrix(const size_t rows, const AlgebraVector<T>& row)
{
  this->m_transposed = false;
  this->m_num_rows = rows;
  this->m_num_cols = row.size();
  m_data.reserve(rows);
  for (size_t i = 0; i < rows; i++)
  {
    m_data[i] = row;
  }
  this->initReferenceDims();
}

template<typename T>
GenericMatrix<T>::GenericMatrix(const size_t rows, const size_t cols, const T& item)
{
  this->m_transposed = false;
  this->m_num_rows = rows;
  this->m_num_cols = cols;
  m_data.reserve(rows);
  for(size_t i = 0; i < rows; i++)
  {
    m_data[i] = (AlgebraVector<T>(cols, item));
  }
  this->initReferenceDims();
}


template<typename T>
const GenericMatrix<T>& GenericMatrix<T>::operator =(
    const GenericMatrix<T>& rhs)
{
  this->m_transposed = rhs.m_transposed;
  this->m_num_rows = rhs.m_num_rows;
  this->m_num_cols = rhs.m_num_cols;
  m_data = rhs.m_data;
  this->initReferenceDims();
  return *this;
}

template<typename T>
const GenericMatrix<T>& GenericMatrix<T>::operator =(GenericMatrix<T> && rhs)
{
  this->m_transposed = std::move(rhs.m_transposed);
  this->m_num_rows = std::move(rhs.m_num_rows);
  this->m_num_cols = std::move(rhs.m_num_cols);
  m_data = std::move(rhs.m_data);
  this->initReferenceDims();
  return *this;
}

template<typename T>
const GenericMatrix<T>& GenericMatrix<T>::operator =(
    const AbstractMatrix<T> & rhs)
{
  this->m_transposed = false;
  this->m_num_rows = rhs.rows();
  this->m_num_cols = rhs.cols();
  m_data.clear();
  m_data.reserve(rhs.rows());
  for (size_t i = 0; i < rhs.rows(); i++)
  {
    m_data[i] = rhs[i];
  }
  this->initReferenceDims();
  return *this;
}

template<typename T>
GenericMatrix<T> GenericMatrix<T>::getTranspose()
{
  GenericMatrix<T> ret(*this);
  ret.transpose();
  return ret;
}

template<typename T>
std::istream& GenericMatrix<T>::readin(std::istream& is)
{
  AlgebraVector<T> temp;
  //add different data for num

  size_t num_rows;
  is >> num_rows;
  (this->m_data).clear();
  while (((is.peek() != EOF) && !(is.eof())) && num_rows)
  {
    is >> temp;
    //std::cout << temp << std::endl;
    if (is.eof())
    {
      break;
    }
    num_rows -= 1;
    (this->m_data).append(temp);
  }
  this->m_num_rows = m_data.size();
  this->m_num_cols = m_data.size() ? m_data[0].size() : 0;
  this->initReferenceDims();
  return is;
}

template<typename T>
void GenericMatrix<T>::createReferenceRows()
{
  DynamicArray<BoundedReferenceVector<T> > &logical_rows =
      !(this->m_transposed) ? this->m_rows : this->m_cols;
  (logical_rows).clear();

  size_t row_size = m_data.size();
  size_t col_size = row_size ? m_data[0].size() : 0;
  //std::cout << "start initing rows for generic" << std::endl;
  for (size_t i = 0; i < row_size; i++)
  {
    DynamicArray<T*> row;
    for (size_t j = 0; j < col_size; j++)
    {
      T* diagonal = (T*) &(m_data[i][j]);
      row.append(diagonal);
    }
    (logical_rows).append(
        BoundedReferenceVector<T>(row, col_size, 0, col_size - 1));
    //what happens to variables? do I need to set null?
  }
  //std::cout << "finit" << std::endl;
  /*for(size_t i = 0; i < (logical_rows).size(); i ++)
  {
    std::cout << logical_rows[i] << std::endl;
  }*/
  //std::cout << "finit" << std::endl;
  //std::cout << "done initing rows for generic" << std::endl;
}

template<typename T>
void GenericMatrix<T>::createReferenceCols()
{
  DynamicArray<BoundedReferenceVector<T> > &logical_cols =
      !(this->m_transposed) ? this->m_cols : this->m_rows;
  (logical_cols).clear();
  DynamicArray<T*> col;
  size_t row_size = m_data.size();
  size_t col_size = row_size ? m_data[0].size() : 0;
  for (size_t i = 0; i < col_size; i++)
  {
    for (size_t j = 0; j < row_size; j++)
    {
      col.append(&(m_data[j][i]));
    }
    (logical_cols).append(
        BoundedReferenceVector<T>(col, row_size, 0, row_size - 1));
    col.clear();
    //what happens to variables? do I need to set null?
  }
}

template<typename T>
GenericMatrix<T> operator +(const GenericMatrix<T>& lhs,
    const AbstractMatrix<T>& rhs)
{
  return GenericMatrix<T>(lhs) += rhs;
}
template<typename T>
GenericMatrix<T> operator -(const GenericMatrix<T>& lhs,
    const AbstractMatrix<T>& rhs)
{
  return GenericMatrix<T>(lhs) -= rhs;
}
template<typename T>
GenericMatrix<T> operator *(const GenericMatrix<T>& lhs,
    const AbstractMatrix<T>& rhs)
{

  multMatCheck(lhs, rhs);
  DynamicArray<AlgebraVector<T> > temp;
  DynamicArray<T> temp_array;
  for (size_t i = 0; i < lhs.rows(); i++)
  {
    for (size_t j = 0; j < rhs.columns(); j++)
    {
      temp_array.append(
          AlgebraVector<T>(lhs[i]) * AlgebraVector<T>(rhs.getColumn(j)));
    }
    temp.append(AlgebraVector<T>(temp_array));

    temp_array.clear();
  }
  return GenericMatrix<T>(temp);
}

template<typename T>
GenericMatrix<T> operator *(const GenericMatrix<T>& lhs, const T& rhs)
{
  return GenericMatrix<T>(lhs) *= rhs;
}
template<typename T>
GenericMatrix<T> operator /(const GenericMatrix<T>& lhs, const T& rhs)
{
  return GenericMatrix<T>(lhs) /= rhs;
}

template<typename T>
GenericMatrix<T> operator *(const T& rhs, const GenericMatrix<T>& lhs)
{
  return lhs * rhs;
}
template<typename T>
GenericMatrix<T> vandermonde(const AlgebraVector<T>& x)
{
//AlgebraVector<T>
  GenericMatrix<T> temp_matrix;
  for (size_t i = 0; i < x.size(); i++)
  {
    DynamicArray<T> temp_array;
    T temp = 1;
    for (size_t j = 0; j < x.size(); j++)
    {
      temp_array.append(temp); //std::pow(a[i], j));
      temp *= x[i];
    }
    temp_matrix.m_rows.append(AlgebraVector<T>(temp_array));
  }
  return temp_matrix;
}
