/**
 *  @file LaplaceMatrix.hpp
 *  @author shae, CS5201 Section A
 *  @date May 6, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
const T& LaplaceMatrix<T>::operator()(const size_t row, const size_t column)
{
  laplaceBoundCheck(row, column);

  size_t max_dim = row >= column ? row : column;
  size_t min_dim = row < column ? row : column;

  if (row == column)
  {
    return -1.0;
  }
  else if (max_dim == min_dim + 1)
  {
    if (min_dim % (m_dim_n - 1))
    {
      return coefficient;
    }
    else
    {
      return 0.0;
    }
  }
  else if (min_dim + (m_dim_n - 1) == max_dim)
  {
    return coefficient;
  }
  return 0.0;
  /*
   else if(row == column + 1)
   {
   if(column % (m_dim_n - 1))
   {
   return coefficient;
   }
   else
   {
   return 0.0;
   }
   }
   else if(row + 1 == column)
   {
   if(row % (m_dim_n - 1))
   {
   return coefficient;
   }
   else
   {
   return 0.0;
   }
   }

   else if(column+(m_dim_n - 1) == row)
   {
   return coefficient;
   }
   else if(row+(m_dim_n - 1) == column)
   {
   return coefficient;
   }*/

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
    ss << "ERROR: column out of bounds, input column value = " << row
        << " vs max dimension" << m_dim_n;
    throw(std::range_error(ss.str()));
  }
}
