/**
 *  @file twonorm.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 22, 2016
 *  @brief Description: Template implementation file for the TwoNorm functor
 *  @details Details:
 */



template <class T>
const T TwoNorm<T>::operator() (const AlgebraVector<T>& src)
{
  T temp;
  int n = static_cast<int>(src.size());

  if(n != 0)
  {
    temp = src[0] * src[0];
    for (int i = 1; i < n; i++)
    {
      temp += src[i] * src[i];
    }
  }
  else
  {
    throw std::invalid_argument("Vector is of size zero!");
  }
  return std::sqrt(temp);
}
