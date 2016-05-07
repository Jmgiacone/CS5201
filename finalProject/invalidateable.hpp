/**
 *  @file invalidateable.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 20, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
GenericMatrix<T> operator +(const Invalidateable<T>& lhs,
    const AbstractMatrix<T>& rhs)
{
  addSubMatCheck(lhs, rhs);
  DynamicArray<AlgebraVector<T> > matrix;
  matrix.reserve(lhs.rows());
  for (size_t i = 0; i < lhs.rows(); i++)
  {
    matrix[i] = lhs[i] + rhs[i];
  }
  return GenericMatrix<T>(matrix);
}
template<typename T>
GenericMatrix<T> operator -(const Invalidateable<T>& lhs,
    const AbstractMatrix<T>& rhs)
{
  addSubMatCheck(lhs, rhs);
  DynamicArray<AlgebraVector<T> > matrix;
  matrix.reserve(lhs.rows());
  for (size_t i = 0; i < lhs.rows(); i++)
  {
    matrix[i] = lhs[i] - rhs[i];
  }
  return GenericMatrix<T>(matrix);
}
template<typename T>
GenericMatrix<T> operator *(const Invalidateable<T>& lhs,
    const AbstractMatrix<T>& rhs)
{
  multMatCheck(lhs, rhs);
  DynamicArray<AlgebraVector<T> > temp;
  DynamicArray<T> temp_array;
  for (size_t i = 0; i < rhs.columns(); i++)
  {
    for (size_t j = 0; j < lhs.rows(); j++)
    {
      temp_array.append(lhs[j] * rhs.getColumn(i));
    }
    temp.append(AlgebraVector<T>(temp_array));
    temp_array.clear();
  }
  return GenericMatrix<T>(temp);

}

template<typename T>
void triangularConsistencyCheck(const DynamicArray<AlgebraVector<T> >& tri_data)
{
  std::stringstream ss;
  /*
   size_t i_upper;
   size_t i_lower;
   size_t size_upper;
   size_t size_lower;
   */
  bool upper_fail = false;
  bool lower_fail = false;
  for (size_t i = tri_data.size(); i > 0; i--)
  {
    if (i != tri_data[tri_data.size() - i].size())
    {
      upper_fail = true;
      //i_upper = i;
      //size_upper = tri_data[tri_data.size() - i].size();
      ss << "ERROR: size of vector doesn't match upper triangular index, index "
          << i << " vs size " << tri_data[tri_data.size() - i].size();
      break;
    }
  }
  for (size_t i = 1; i <= tri_data.size(); i++)
  {
    if (i != tri_data[i - 1].size())
    {
      lower_fail = true;
      if (upper_fail)
      {
        ss << "\n";
      }
      //i_lower = i;
      //size_upper = tri_data[tri_data.size() - i].size();
      ss << "ERROR: size of vector doesn't match lower triangular index, index "
          << i << " vs size " << tri_data[i - 1].size();
      break;
    }
  }

  if (upper_fail && lower_fail)
  {
    throw(std::invalid_argument(ss.str()));
  }
}

