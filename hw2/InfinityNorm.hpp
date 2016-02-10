template <class T>
const T InfinityNorm<T>::operator() (const std::vector<Polynomial<T>> &vect) const
{
  T max, temp;
  int size = vect.size();

  for(int i = 0; i < size; i++)
  {
    temp = vect[i].magnitude();

    if(i == 0)
    {
      max = temp;
    }
    else if(temp > max)
    {
      max = temp;
    }
  }
  return max;
}
