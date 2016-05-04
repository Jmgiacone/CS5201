/**
 *  @file squarematrix.hpp
 *  @author shae, CS5201 Section A
 *  @date Apr 21, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
size_t SquareMatrix<T>::rows() const
{
  return m_dim_n;
}

template<typename T>
size_t SquareMatrix<T>::columns() const
{
  return m_dim_n;
}

