/**
 *  @file refbasedmatrix.hpp
 *  @author shae, CS5201 Section A
 *  @date Apr 18, 2016
 *  @brief Description:
 *  @details Details:
 */

/*template<typename T>
 RefBasedMatrix<T>::RefBasedMatrix()
 {
 initReferenceDims();
 }
 */
template<typename T>
const AbstractMatrix<T>& RefBasedMatrix<T>::operator *=(const T& rhs)
{
  for (size_t i = 0; i < m_rows.size(); i++)
  {
    m_rows[i] *= rhs;
  }
  return *this;
}

template<typename T>
const AbstractMatrix<T>& RefBasedMatrix<T>::operator /=(const T& rhs)
{
  for (size_t i = 0; i < m_rows.size(); i++)
  {
    m_rows[i] /= rhs;
  }
  return *this;
}
template<typename T>
BoundedReferenceVector<T>& RefBasedMatrix<T>::operator [](const size_t index)
{
  return m_rows[index];
}
template<typename T>
const BoundedReferenceVector<T>& RefBasedMatrix<T>::operator [](
    const size_t index) const
{
  return m_rows[index];
}

template<typename T>
const AbstractMatrix<T>& RefBasedMatrix<T>::transpose()
{
  m_transposed = ~m_transposed;
  swap(m_rows, m_cols);
  return *this;
}

template<typename T>
const BoundedReferenceVector<T>& RefBasedMatrix<T>::getRow(
    const size_t index) const
{
  return m_rows[index];
}

template<typename T>
BoundedReferenceVector<T>& RefBasedMatrix<T>::getRow(const size_t index)
{
  return m_rows[index];
}

template<typename T>
const BoundedReferenceVector<T>& RefBasedMatrix<T>::getColumn(
    const size_t index) const
{
  return m_cols[index];
}

template<typename T>
BoundedReferenceVector<T>& RefBasedMatrix<T>::getColumn(const size_t index)
{
  return m_cols[index];
}

template<typename T>
void RefBasedMatrix<T>::initReferenceDims()
{
  createReferenceRows();
  createReferenceCols();
}

template<typename T>
std::ostream& RefBasedMatrix<T>::print(std::ostream& os) const
{
  std::ios prev_format(nullptr);
  prev_format.copyfmt(os);
  for (size_t i = 0; i < this->rows(); i++)
  {
    os.copyfmt(prev_format);
    os << m_rows[i] << std::endl;
  }
  return os;
}

template<typename T>
AlgebraVector<T> RefBasedMatrix<T>::vectorMultiply(
    const AbstractVector<T>& vector) const
{
  DynamicArray<T> temp;
  matVecDimCheck(*this, vector);

  for (size_t i = 0; i < this->rows(); i++)
  {
    temp.append((*this)[i] * vector);
  }
  return AlgebraVector<T>(temp);
}
