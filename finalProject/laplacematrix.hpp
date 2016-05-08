/**
 *  @file laplacematrix.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date May 4, 2016
 *  @brief Description: PDE laplace matrix class for use
 *  in PDE estimation
 *  @details Details:
 */

template<typename T>
const T LaplaceMatrix<T>::operator()(const size_t row, const size_t column)
{
  laplaceBoundCheck(row, column);

  size_t max_dim = row >= column ? row : column;
  size_t min_dim = row < column ? row : column;

  if (row == column)
  {
    return 1.0;
  }
  else if (max_dim == min_dim + 1)
  {
    if ((min_dim+1) % (m_divisions - 1))
    {
      return coefficient;
    }
    else
    {
      return 0.0;
    }
  }
  else if ((min_dim + (m_divisions - 1)) == max_dim)
  {
    return coefficient;
  }
  return 0.0;
}

template<typename T>
void LaplaceMatrix<T>::laplaceBoundCheck(const size_t row, const size_t column)
{
  std::stringstream ss;
  if (row >= m_dim_n)
  {
    ss << "ERROR: row out of bounds, input row value = " << row
        << " vs max dimension" << m_dim_n;
    throw(std::range_error(ss.str()));
  }
  if (column >= m_dim_n)
  {
    ss << "ERROR: column out of bounds, input column value = " << column
        << " vs max dimension " << m_dim_n;
    throw(std::range_error(ss.str()));
  }
}

template<typename T>
GenericMatrix<T> LaplaceMatrix<T>::toGenMat()
{
  DynamicArray<AlgebraVector<T>> temp_mat;
  for(size_t i = 0; i < m_dim_n; i++)
  {
    DynamicArray<T> temp_arr;
    for(size_t j = 0; j < m_dim_n; j++)
    {
      temp_arr.append((*this)(i, j));
    }
    temp_mat.append(AlgebraVector<T>(temp_arr));
  }
  GenericMatrix<T> mat(temp_mat);
  return mat;
}
