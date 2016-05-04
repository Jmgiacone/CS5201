/**
 *  @file unrestrictedrefmatrix.hpp
 *  @author shae, CS5201 Section A
 *  @date Apr 18, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
const UnrestrictedRefMatrix<T>& UnrestrictedRefMatrix<T>::operator +=(
    const AbstractMatrix<T>& rhs)
{
  addSubMatCheck(*this, rhs);
  for (size_t i = 0; i < this->rows(); i++)
  {
    this->getRow(i) += rhs.getRow(i);
  }
  return *this;
}

template<typename T>
const UnrestrictedRefMatrix<T>& UnrestrictedRefMatrix<T>::operator -=(
    const AbstractMatrix<T>& rhs)
{
  addSubMatCheck(*this, rhs);
  for (size_t i = 0; i < this->rows(); i++)
  {
    this->getRow(i) -= rhs.getRow(i);
  }
  return *this;
}

template<typename T>
const AbstractMatrix<T>& UnrestrictedRefMatrix<T>::transpose()
{
  std::swap(this->m_num_rows, this->m_num_cols);
  RefBasedMatrix<T>::transpose();
  return *this;
}
