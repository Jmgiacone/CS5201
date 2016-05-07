/**
 *  @file squarerefmatrix.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 21, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
const SquareRefMatrix<T>& SquareRefMatrix<T>::operator +=(
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
const SquareRefMatrix<T>& SquareRefMatrix<T>::operator -=(
    const AbstractMatrix<T>& rhs)
{
  addSubMatCheck(*this, rhs);
  for (size_t i = 0; i < this->rows(); i++)
  {
    this->getRow(i) -= rhs.getRow(i);
  }
  return *this;
}
