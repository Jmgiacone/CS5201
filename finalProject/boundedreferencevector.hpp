/**
 *  @file boundedreferencevector.hpp
 *  @author shae, CS5201 Section A
 *  @date Apr 3, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
BoundedReferenceVector<T>::BoundedReferenceVector(
    const DynamicArray<T*>& pointer_references)
{
  t_pointer_references = pointer_references;
  m_ref_size = t_pointer_references.size();
  m_bound_lower = 0;
  m_bound_upper = m_ref_size - 1;
  m_zero = T();
}

template<typename T>
std::ostream& BoundedReferenceVector<T>::print(std::ostream& os) const
{
  std::ios prev_format(nullptr);
  prev_format.copyfmt(os);
  if ((m_bound_lower + t_pointer_references.size() - 1) != m_bound_upper)
  {
    std::cerr << " lower bound plus size "
        << (m_bound_lower + t_pointer_references.size() - 1) << " upper "
        << m_bound_upper << std::endl;
  }
  for (size_t i = 0; i < m_bound_lower; i++)
  {
    os.copyfmt(prev_format);
    os << 0.0;//m_zero;
  }
  for (size_t i = 0; i < t_pointer_references.size(); i++)
  {
    os.copyfmt(prev_format);
    os << *(t_pointer_references[i]);
  }
  for (size_t i = m_bound_upper + 1; i < m_ref_size; i++)
  {
    os.copyfmt(prev_format);
    os << 0.0;//m_zero;
  }
  return os;
}

template<typename T>
std::istream& BoundedReferenceVector<T>::readin(std::istream& is)
{
  std::cerr << "Error can't read in a reference vector from a istream"
      << std::endl;
  return is;
}

template<typename T>
T BoundedReferenceVector<T>::vectorMultiply(const AbstractVector<T>& rhs) const
{
  T temp = m_zero;

  vecArithmeticSizeCheck(*this, rhs);

  for (size_t i = m_bound_lower; i <= m_bound_upper; i++)
  {
    temp += (*this)[i] * rhs[i];
  }
  return temp;
}

template<typename T>
BoundedReferenceVector<T>::BoundedReferenceVector(
    const DynamicArray<T*>& pointer_references, const size_t size,
    const size_t bound_lower, const size_t bound_upper)
{
  t_pointer_references = pointer_references;
  m_ref_size = size;
  m_bound_lower = bound_lower;
  m_bound_upper = bound_upper;
//forcing the value to be the equivalent of zero
  m_zero = T();
}

template<typename T>
const BoundedReferenceVector<T>& BoundedReferenceVector<T>::operator =(
    const BoundedReferenceVector<T>& rhs)
{
  t_pointer_references = rhs.t_pointer_references;
  m_ref_size = rhs.m_ref_size;
  m_bound_lower = rhs.m_bound_lower;
  m_bound_upper = rhs.m_bound_upper;
//forcing the value to be the equivalent of zero
  m_zero = T();
  return *this;
}

template<typename T>
const BoundedReferenceVector<T>& BoundedReferenceVector<T>::operator =(
    const BoundedReferenceVector<T> && rhs)
{
  t_pointer_references = std::move(rhs.t_pointer_references);
  m_ref_size = std::move(rhs.m_ref_size);
  m_bound_lower = std::move(rhs.m_bound_lower);
  m_bound_upper = std::move(rhs.m_bound_upper);
//forcing the value to be the equivalent of zero
  m_zero = T();
  return *this;
}

template<typename T>
const T& BoundedReferenceVector<T>::operator [](const size_t index) const
{
  T* ref;

  if ((index < m_bound_lower || index > m_bound_upper) && index < size())
  {
    return m_zero;
  }
  else
  {
    ref = t_pointer_references[index - m_bound_lower];
  }
  return *ref;
}

template<typename T>
T& BoundedReferenceVector<T>::operator [](const size_t index)
{

  T* ref;

  if ((index < m_bound_lower || index > m_bound_upper) && index < size())
  {
    return m_zero;
  }
  else
  {
    ref = t_pointer_references[index - m_bound_lower];
  }
  return *ref;
}

template<typename T>
size_t BoundedReferenceVector<T>::getUpper() const
{
  return m_bound_upper;
}
template<typename T>
size_t BoundedReferenceVector<T>::getLower() const
{
  return m_bound_lower;
}
template<typename T>
size_t BoundedReferenceVector<T>::size() const
{
  return m_ref_size;
}

template<typename T>
const BoundedReferenceVector<T>& BoundedReferenceVector<T>::operator +=(
    const BoundedReferenceVector<T>& rhs)
{

  vecArithmeticSizeCheck(*this, rhs);
  boundVecBoundCheck(*this, rhs);
  size_t lower_bound = rhs.m_bound_lower;
  size_t upper_bound = rhs.m_bound_upper;
  for (size_t i = lower_bound; i <= upper_bound; i++)
  {
    *(t_pointer_references[i]) += rhs[i];
  }
  return *this;
}

template<typename T>
const BoundedReferenceVector<T>& BoundedReferenceVector<T>::operator -=(
    const BoundedReferenceVector<T>& rhs)
{
  vecArithmeticSizeCheck(*this, rhs);
  boundVecBoundCheck(*this, rhs);
  size_t lower_bound = rhs.m_bound_lower;
  size_t upper_bound = rhs.m_bound_upper;
  for (size_t i = lower_bound; i <= upper_bound; i++)
  {
    *(t_pointer_references[i]) -= rhs[i];
  }
  return *this;
}

template<typename T>
const AbstractVector<T>& BoundedReferenceVector<T>::operator *=(const T& rhs)
{
  for (size_t i = getLower(); i <= getUpper(); i++)
  {
    (*this)[i] *= rhs;
  }
  return *this;
}

template<typename T>
const AbstractVector<T>& BoundedReferenceVector<T>::operator /=(const T& rhs)
{

  for (size_t i = getLower(); i <= getUpper(); i++)
  {
    (*this)[i] /= rhs;
  }
  return *this;
}

template<typename T>
BoundedReferenceVector<T>::~BoundedReferenceVector()
{
  for (size_t i = 0; i < t_pointer_references.size(); i++)
  {
    t_pointer_references[i] = nullptr;
  }
}

template<typename T>
AlgebraVector<T> operator *(const T& lhs, const BoundedReferenceVector<T>& rhs)
{
  AlgebraVector<T> temp_vector(rhs);
  for (size_t i = rhs.getLower(); i <= rhs.getUpper(); i++)
  {
    temp_vector[i] *= lhs;
  }
  return temp_vector;
}

template<typename T>
AlgebraVector<T> operator /(const BoundedReferenceVector<T>& lhs, const T& rhs)
{
  AlgebraVector<T> temp_vector(lhs);
  for (size_t i = lhs.getLower(); i <= lhs.getUpper(); i++)
  {
    temp_vector[i] /= rhs;
  }
  return temp_vector;
}

template<typename T>
AlgebraVector<T> operator +(const BoundedReferenceVector<T>& lhs,
    const AbstractVector<T>& rhs)
{
  AlgebraVector<T> temp_vector(rhs);
  vecArithmeticSizeCheck(lhs, rhs);
  for (size_t i = lhs.getLower(); i <= lhs.getUpper(); i++)
  {
    temp_vector[i] += lhs[i];
  }

  return temp_vector;
}

template<typename T>
AlgebraVector<T> operator -(const BoundedReferenceVector<T>& lhs,
    const AbstractVector<T>& rhs)
{
  AlgebraVector<T> temp_vector(rhs);
  vecArithmeticSizeCheck(lhs, rhs);

  for (size_t i = 0; i < rhs.size(); i++)
  {
    temp_vector[i] = -(temp_vector[i]);
  }
  for (size_t i = lhs.getLower(); i <= lhs.getUpper(); i++)
  {
    temp_vector[i] += lhs[i];
  }

  return temp_vector;
}

template<typename T>
void boundVecBoundCheck(const BoundedReferenceVector<T>& lhs,
    const BoundedReferenceVector<T>& rhs)
{
  std::stringstream ss;
  if (rhs.getLower() < lhs.getLower())
  {
    ss << "vector bounds do not match, rhs lower bound " << rhs.getLower()
        << " < lhs lower bound " << lhs.getLower();

    throw(std::out_of_range(ss.str()));
  }
  else if (rhs.getUpper() > lhs.getUpper())
  {
    ss << "vector bounds do not match, rhs upper bound " << rhs.getUpper()
        << " < lhs upper bound " << lhs.getUpper();
    throw(std::out_of_range(ss.str()));
  }
}
