/**
 *  @file abstractmatrix.hpp
 *  @author shae, CS5201 Section A
 *  @date Mar 30, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
void multMatCheck(const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs)
{
  std::stringstream ss;
  if (lhs.columns() != rhs.rows())
  {
    ss
        << "Mulitply lhs matrix size does not match rhs matrix columns, lhs matrix columns "
        << lhs.columns() << " vs rhs rows" << rhs.rows();
    throw(std::out_of_range(ss.str()));
  }
}

template<typename T>
void addSubMatCheck(const AbstractMatrix<T>& lhs, const AbstractMatrix<T>& rhs)
{
  std::stringstream ss;
  if (lhs.rows() != rhs.rows())
  {
    ss << "Matrix rows don't match up, lhs rows " << lhs.rows()
        << " vs rhs rows" << rhs.rows();
    throw(std::out_of_range(ss.str()));
  }
  else if (lhs.columns() != rhs.columns())
  {
    ss << "Matrix columns don't match up, lhs columns " << lhs.columns()
        << " vs rhs columns" << rhs.columns();

    throw(std::out_of_range(ss.str()));
  }
}

template<typename T>
void matVecDimCheck(const AbstractMatrix<T>& lhs, const AbstractVector<T>& rhs)
{
  std::stringstream ss;
  if (lhs.columns() != rhs.size())
  {
    ss << "Multiply vector size does not match matrix columns, matrix columns "
        << lhs.columns() << " vs vector size" << rhs.size();
    throw(std::out_of_range(ss.str()));
  }
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const AbstractMatrix<T>& rhs)
{
  return rhs.print(os);
}

template<typename T>
std::istream& operator >>(std::istream& is, AbstractMatrix<T>& rhs)
{
  return rhs.readin(is);
}

template<typename T>
AlgebraVector<T> operator *(const AbstractMatrix<T>& lhs,
    const AlgebraVector<T>& vector)
{
  return lhs.vectorMultiply(vector);
}

