template <class T>
SmartVector<T>::SmartVector(int size, T** d)
{
  terms = size;
  data = d;
}

template <class T>
SmartVector<T>::SmartVector(const SmartVector<T>& src)
{
  terms = src.terms;

  data = new T*[terms];

  for(int i = 0; i < terms; i++)
  {
    data[i] = new T(*src.data[i]);
  }
}

template <class T>
const T& SmartVector<T>::operator[](int x) const
{
  if(x >= terms || x < 0)
  {
    throw std::invalid_argument("SmartVector [] Error: Out of bounds");
  }

  if(data[x] == NULL)
  {
    return zero;
  }
  return *data[x];
}