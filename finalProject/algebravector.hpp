/**
 *  @file algebravector.hpp
 *  @author shae, CS5201 Section A
 *  @date Feb 23, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
AlgebraVector<T>::AlgebraVector(const AbstractVector<T>& rhs)
{
  *this = rhs;
}

template<typename T>
const AlgebraVector<T>& AlgebraVector<T>::operator =(
    const AbstractVector<T>& rhs)
{
  m_dynamic_array.reserve(rhs.size());
  for (size_t i = 0; i < rhs.size(); i++)
  {
    m_dynamic_array[i] = rhs[i];
  }
  return *this;
}

template<typename T>
const AlgebraVector<T>& AlgebraVector<T>::operator =(AlgebraVector<T> && rhs)
{
  m_dynamic_array = std::move(rhs.m_dynamic_array);
  return *this;
}

template<typename T>
const AbstractVector<T>& AlgebraVector<T>::operator +=(
    const AbstractVector<T>& rhs)
{
  vecArithmeticSizeCheck(*this, rhs);
  for (size_t i = 0; i < size(); i++)
  {
    m_dynamic_array[i] += rhs[i];
  }
  return *this;
}

template<typename T>
const AbstractVector<T>& AlgebraVector<T>::operator -=(
    const AbstractVector<T>& rhs)
{
  vecArithmeticSizeCheck(*this, rhs);
  for (size_t i = 0; i < size(); i++)
  {
    m_dynamic_array[i] -= rhs[i];
  }

  return *this;
}

template<typename T>
const AbstractVector<T>& AlgebraVector<T>::operator *=(const T& rhs)
{
  for (size_t i = 0; i < size(); i++)
  {
    m_dynamic_array[i] *= rhs;
  }
  return *this;
}

template<typename T>
const AbstractVector<T>& AlgebraVector<T>::operator /=(const T& rhs)
{
  for (size_t i = 0; i < size(); i++)
  {
    m_dynamic_array[i] /= rhs;
  }
  return *this;
}

template<typename T>
T& AlgebraVector<T>::operator [](const size_t index)
{
  return m_dynamic_array[index];
}

template<typename T>
const T& AlgebraVector<T>::operator [](const size_t index) const
{
  return m_dynamic_array[index];
}

template<typename T>
size_t AlgebraVector<T>::size() const
{
  return m_dynamic_array.size();
}

template<typename T>
const AlgebraVector<T>& AlgebraVector<T>::operator =(
    const AlgebraVector<T>& rhs)
{
  m_dynamic_array = rhs.m_dynamic_array;
  return *this;
}

template<typename T>
std::ostream& AlgebraVector<T>::print(std::ostream& os) const
{
  //saves the state of the previous format
  std::ios prev_format(nullptr);
  prev_format.copyfmt(os);
  for (size_t i = 0; i < size(); i++)
  {
    os.copyfmt(prev_format);
    os << (*this)[i];

  }
  return os;
}

template<typename T>
std::istream& AlgebraVector<T>::readin(std::istream& is)
{
  T temp;
  m_dynamic_array.clear();
  do
  {
    is >> temp;
    m_dynamic_array.append(temp);
  } while (is.peek() == ' ' && !(is.eof()));
  return is;
}

template<typename T>
T AlgebraVector<T>::vectorMultiply(const AbstractVector<T>& rhs) const
{
  T temp;
  temp -= temp;
  vecArithmeticSizeCheck(*this, rhs);

  for (size_t i = 0; i < size(); i++)
  {
    temp += (rhs[i] * (*this)[i]);
  }

  return temp;
}

template<typename T>
void swap(AlgebraVector<T>& lhs, AlgebraVector<T>& rhs)
{
  using std::swap;

  swap(lhs.m_dynamic_array, rhs.m_dynamic_array);
}

template<typename T>
T twoNorm(const AlgebraVector<T>& vector)
{
  T temp;
  if (vector.size() > 0)
  {
    temp = (vector[0] * vector[0]);
    for (size_t i = 1; i < vector.size(); i++)
    {
      temp += (vector[i] * vector[i]);
    }
    temp = sqrt(temp);
  }
  return temp;
}

template<typename T>
AlgebraVector<T> operator /(const AlgebraVector<T>& lhs, const T& rhs)
{
  return AlgebraVector<T>(lhs) /= rhs;
}

template<typename T>
AlgebraVector<T> operator *(const T& lhs, const AlgebraVector<T>& rhs)
{
  return AlgebraVector<T>(rhs) *= lhs;
}

template<typename T>
AlgebraVector<T> operator *(const AlgebraVector<T>& lhs, const T& rhs)
{
  return AlgebraVector<T>(lhs) *= rhs;
}

template<typename T>
AlgebraVector<T> operator +(const AlgebraVector<T>& lhs,
    const AbstractVector<T>& rhs)
{
  return AlgebraVector<T>(lhs) += rhs;
}

template<typename T>
AlgebraVector<T> operator -(const AlgebraVector<T>& lhs,
    const AbstractVector<T>& rhs)
{
  return AlgebraVector<T>(lhs) -= rhs;
}

