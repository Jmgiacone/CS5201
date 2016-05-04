/**
 *  @file abstractvector.hpp
 *  @author shae, CS5201 Section A
 *  @date Apr 11, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
void vecArithmeticSizeCheck(const AbstractVector<T>& lhs,
    const AbstractVector<T>& rhs)
{
  std::stringstream ss;
  if (lhs.size() != rhs.size())
  {
    ss << "Vector sizes do not match, lhs " << lhs.size() << " vs rhs "
        << rhs.size();
    throw(std::out_of_range(ss.str()));
  }
}

template<typename T>
std::ostream& operator <<(std::ostream& os, const AbstractVector<T>& rhs)
{
  return rhs.print(os);
}

template<typename T>
std::istream& operator >>(std::istream& is, AbstractVector<T>& rhs)
{
  return rhs.readin(is);
}

template<typename T>
T operator *(const AbstractVector<T>& lhs, const AbstractVector<T>& rhs)
{
  return lhs.vectorMultiply(rhs);
}

