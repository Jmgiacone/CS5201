/**
 *  @file triangularmatrix.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 21, 2016
 *  @brief Description:
 *  @details Details:
 */


template<typename T>
void TriangularMatrix<T>::createReferenceRows()
{
  DynamicArray<BoundedReferenceVector<T> > &logical_rows =
      !(this->m_transposed) ? this->m_rows : this->m_cols;
  (logical_rows).clear();
  //- - - - >
  //0 - - - >
  //0 0 - - >
  //0 0 0 - >
  if (m_type == UPPER)
  {
    for (size_t i = 0; i < (this->m_dim_n); i++)
    {
      DynamicArray<T*> pointer_references;
      size_t bound_lower = i;
      for (size_t j = bound_lower; j < this->m_dim_n; j++)
      {
        T* diagonal = (T*) &(m_tri_data[i][j - bound_lower]);
        pointer_references.append(diagonal);
      }
      size_t bound_upper = this->m_dim_n - 1;
      (logical_rows).append(
          BoundedReferenceVector<T>(pointer_references, (this->m_dim_n),
              bound_lower, bound_upper));
    }
  }

  //- 0 0 0 >
  //- - 0 0 >
  //- - - 0 >
  //- - - - >
  else if (m_type == LOWER)
  {
    for (size_t i = 0; i < (this->m_dim_n); i++)
    {
      DynamicArray<T*> pointer_references;
      size_t bound_upper = i;
      for (size_t j = 0; j <= bound_upper; j++)
      {
        T* diagonal = (T*) &(m_tri_data[i][j]);
        pointer_references.append(diagonal);
      }
      size_t bound_lower = 0;
      (logical_rows).append(
          BoundedReferenceVector<T>(pointer_references, (this->m_dim_n),
              bound_lower, bound_upper));
    }
  }
}

///@TODO need to take into account different upper or lower triangular matricies
template<typename T>
void TriangularMatrix<T>::createReferenceCols()
{
  DynamicArray<BoundedReferenceVector<T> > &logical_cols =
      !(this->m_transposed) ? this->m_cols : this->m_rows;
  (logical_cols).clear();
  DynamicArray<T*> pointer_references;
  //| | | |
  //0 | | |
  //0 0 | |
  //0 0 0 |
  //V V V V
  if (m_type == UPPER)
  {
    for (size_t i = 0; i < (this->m_dim_n); i++)
    {
      DynamicArray<T*> pointer_references;
      size_t bound_lower = 0;
      size_t bound_upper = i;
      for (size_t j = bound_lower; j <= bound_upper; j++)
      {
        T* diagonal = (T*) &(m_tri_data[j][i - j]);
        pointer_references.append(diagonal);
      }
      (logical_cols).append(
          BoundedReferenceVector<T>(pointer_references, (this->m_dim_n),
              bound_lower, bound_upper));
      pointer_references.clear();
    }
  }

  //| 0 0 0
  //| | 0 0
  //| | | 0
  //| | | |
  //V V V V
  else if (m_type == LOWER)
  {
    for (size_t i = 0; i < (this->m_dim_n); i++)
    {
      DynamicArray<T*> pointer_references;
      size_t bound_lower = i;
      size_t bound_upper = this->m_dim_n - 1;
      for (size_t j = bound_lower; j <= bound_upper; j++)
      {
        T* diagonal = (T*) &(m_tri_data[j][i]);
        pointer_references.append(diagonal);
      }
      (logical_cols).append(
          BoundedReferenceVector<T>(pointer_references, (this->m_dim_n),
              bound_lower, bound_upper));
      pointer_references.clear();
    }
  }
}

template<typename T>
std::istream& TriangularMatrix<T>::readin(std::istream& is)
{
  std::cerr << "No way to read in" << std::endl;
  return is;
}

template<typename T>
TriangularMatrix<T>::TriangularMatrix(const TriangularMatrix<T>& rhs) :
    SquareMatrix<T>(rhs), RefBasedMatrix<T>(rhs), m_tri_data(rhs.m_tri_data), m_type(
        rhs.m_type)
{
  this->initReferenceDims();
}

template<typename T>
TriangularMatrix<T>::TriangularMatrix(TriangularMatrix<T> && rhs) :
    m_tri_data(std::move(rhs.m_tri_data)), m_type(std::move(rhs.m_type))
{
  this->m_transposed = std::move(rhs.m_transposed);
  this->m_dim_n = std::move(rhs.m_dim_n);
  this->initReferenceDims();
}

template<typename T>
TriangularMatrix<T>::TriangularMatrix(const TRIANGLE_TYPE type,
    const DynamicArray<AlgebraVector<T> >& tri_data)
{
  triangularConsistencyCheck(tri_data);
  triangularTypeConsistencyCheck(type, tri_data);
  m_type = type;
  m_tri_data = tri_data;
  this->m_dim_n = m_tri_data.size();
  this->m_transposed = type;
  this->initReferenceDims();
}

template<typename T>
TriangularMatrix<T>::TriangularMatrix(const size_t dim_n,
    const TRIANGLE_TYPE type, const T& item)
{
  m_type = type;
  this->m_dim_n = dim_n;
  if (type == UPPER)
  {
    for (size_t i = 0; i < dim_n; i++)
    {
      m_tri_data.append(AlgebraVector<T>((dim_n - i), item));
    }
  }
  else if (type == LOWER)
  {
    for (size_t i = 0; i < dim_n; i++)
    {
      m_tri_data.append(AlgebraVector<T>((i + 1), item));
    }
  }
  this->m_transposed = false;
  this->initReferenceDims();
}

template<typename T>
const TriangularMatrix<T>& TriangularMatrix<T>::operator =(
    const TriangularMatrix<T>& rhs)
{
  m_tri_data = rhs.m_tri_data;
  m_type = rhs.m_type;
  this->m_transposed = rhs.m_transposed;
  this->m_dim_n = rhs.m_dim_n;
  this->initReferenceDims();
  return *this;
}

template<typename T>
const TriangularMatrix<T>& TriangularMatrix<T>::operator =(
    TriangularMatrix<T> && rhs)
{
  m_tri_data = std::move(rhs.m_tri_data);
  m_type = std::move(rhs.m_type);
  this->m_transposed = std::move(rhs.m_transposed);
  this->m_dim_n = std::move(rhs.m_dim_n);
  this->initReferenceDims();
  return *this;
}

template<typename T>
const TriangularMatrix<T>& TriangularMatrix<T>::operator +=(
    const TriangularMatrix<T>& rhs)
{
  addSubMatCheck(*this, rhs);
  triangularAddSubCheck(*this, rhs);
  for (size_t i = 0; i < this->rows(); i++)
  {
    m_tri_data[i] += rhs.m_tri_data[i];
  }
  return *this;
}

template<typename T>
const TriangularMatrix<T>& TriangularMatrix<T>::operator -=(
    const TriangularMatrix<T>& rhs)
{
  addSubMatCheck(*this, rhs);
  triangularAddSubCheck(*this, rhs);
  for (size_t i = 0; i < this->rows(); i++)
  {
    m_tri_data[i] -= rhs.m_tri_data[i];
  }
  return *this;
}

template<typename T>
const AbstractMatrix<T>& TriangularMatrix<T>::transpose()
{
  RefBasedMatrix<T>::transpose();
  m_type = (m_type == UPPER) ? LOWER : UPPER;
  return *this;
}

template<typename T>
TriangularMatrix<T> TriangularMatrix<T>::getTranspose() const
{
  TriangularMatrix<T> ret(*this);
  ret.transpose();
  return ret;
}

template<typename T>
TRIANGLE_TYPE TriangularMatrix<T>::getType() const
{
  return m_type;
}

template<typename T>
TriangularMatrix<T> operator +(const TriangularMatrix<T>& lhs,
    const TriangularMatrix<T>& rhs)
{
  return TriangularMatrix<T>(lhs) += rhs;
}

template<typename T>
TriangularMatrix<T> operator -(const TriangularMatrix<T>& lhs,
    const TriangularMatrix<T>& rhs)
{
  return TriangularMatrix<T>(lhs) -= rhs;
}

template<typename T>
TriangularMatrix<T> operator *(const TriangularMatrix<T>& lhs, const T& rhs)
{
  TriangularMatrix<T> ret(lhs);
  ret *= rhs;
  return ret;
}

template<typename T>
TriangularMatrix<T> operator /(const TriangularMatrix<T>& lhs, const T& rhs)
{
  TriangularMatrix<T> ret(lhs);
  ret /= rhs;
  return ret;
}
template<typename T>
TriangularMatrix<T> operator *(const T& rhs, const TriangularMatrix<T>& lhs)
{
  return lhs * rhs;
}

template<typename T>
void triangularAddSubCheck(const TriangularMatrix<T>& lhs,
    const TriangularMatrix<T>& rhs)
{
  std::stringstream ss;
  if (rhs.getType() != lhs.getType())
  {
    ss << "ERROR: triangular types don't match, lhs type "
        << (lhs.getType() ? " LOWER " : " UPPER ") << " vs rhs type "
        << (rhs.getType() ? " LOWER " : " UPPER ");
    throw(std::domain_error(ss.str()));
  }
}

template<typename T>
void triangularTypeConsistencyCheck(const TRIANGLE_TYPE type,
    const DynamicArray<AlgebraVector<T> >& tri_data)
{
  std::stringstream ss;
  if (type == UPPER)
  {
    if (tri_data.size() && tri_data[0].size() <= 1)
    {
      ss << "ERROR: triangular type doesn't match data, type " << " UPPER "
          << " and top data is not largest side" << tri_data[0].size();
      throw(std::domain_error(ss.str()));
    }
  }
  else if (type == LOWER)
  {
    if (tri_data.size() && tri_data[0].size() != 1)
    {
      ss << "ERROR: triangular type doesn't match data, type " << " LOWER "
          << " and top data is not smallest side" << tri_data[0].size();
      throw(std::domain_error(ss.str()));
    }
  }

}

