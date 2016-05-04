/**
 *  @file unrestricteddimmatrix.hpp
 *  @author shae, CS5201 Section A
 *  @date Apr 18, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
size_t UnrestrictedDimMatrix<T>::rows() const
{
  return m_num_rows;
}

template<typename T>
size_t UnrestrictedDimMatrix<T>::columns() const
{
  return m_num_cols;
}
