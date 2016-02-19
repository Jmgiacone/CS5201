//
// Created by Jordan on 2/17/2016.
//
template <class T>
Vector<T>::Vector()
{
  terms = 0;
  size = DEFAULT_MAX_TERMS;
  data = new T[size];
}

template <class T>
Vector<T>::Vector(int s)
{
  terms = 0;

  if(s < 1)
  {
    //Error
  }
  size = s;
  data = new T[size];
}

template <class T>
Vector<T>::Vector(const Vector<T>& src)
{
  terms = src.terms;
  size = src.size;
  data = new T[size];

  for(int i = 0; i < terms; i++)
  {
    data[i] = src.data[i];
  }
}

template<class T>
Vector<T>::~Vector()
{
  if(data != NULL)
  {
    delete [] data;
  }
  terms = 0;
  size = 0;
  data = NULL;
}

template <class T>
void swap(Vector<T>& x, Vector<T>& y)
{
  std::swap(x.data, y.data);
  std::swap(x.terms, y.terms);
  std::swap(x.size, y.size);
}

template <class T>
const Vector<T>& Vector<T>::operator= (Vector<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <class T>
const Vector<T> operator+ (const Vector<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.terms != rhs.terms)
  {
    //Throw error
  }

  Vector<T> sum(lhs.terms);
  for(int i = 0; i < lhs.terms; i++)
  {
    sum.data[i] = lhs.data[i] + rhs.data[i];
  }

  return sum;
}

template <class T>
const Vector<T> operator- (const Vector<T>& lhs, const Vector<T>& rhs)
{
  return (lhs + (-rhs));
}

template <class T>
const Vector<T>& operator- (const Vector<T>& rhs)
{
  Vector<T> temp(rhs.size);
  for (int i = 0; i < rhs.terms; i++)
  {
    temp.data[i] = -rhs.data[i];
  }

  return temp;
}

template <class T>
const Vector<T>& Vector<T>::operator+= (const Vector<T>& rhs)
{
  return (*this = (*this + rhs));
}

template <class T>
const Vector<T>& Vector<T>::operator-= (const Vector<T>& rhs)
{
  return (*this = (*this - rhs));
}