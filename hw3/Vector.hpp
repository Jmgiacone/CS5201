//
// Created by Jordan on 2/17/2016.
//
template <class T>
Vector<T>::Vector()
{
  terms = DEFAULT_TERMS;
  data = new T[terms];
}

template <class T>
Vector<T>::Vector(int t)
{
  if(t < 1)
  {
    //Error
  }
  terms = t;
  data = new T[terms];
}

template <class T>
Vector<T>::Vector(const Vector<T>& src)
{
  terms = src.terms;
  data = new T[terms];

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
  data = NULL;
}

template <class T>
void swap(Vector<T>& x, Vector<T>& y)
{
  std::swap(x.data, y.data);
  std::swap(x.terms, y.terms);
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
const Vector<T> operator- (const Vector<T>& rhs)
{
  Vector<T> temp(rhs.terms);
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

template <class T>
T& Vector<T>::operator[] (const int x)
{
  if(x < 0 || x >= terms)
  {
    //Throw error
  }
  return data[x];
}

template <class T>
const T& Vector<T>::operator[] (const int x) const
{
  return (*this)[x];
}

template <class T>
const T operator* (const Vector<T>& lhs, const Vector<T>& rhs)
{
  if(rhs.terms != lhs.terms)
  {
    //Throw Error
  }

  T temp;
  for(int i = 0; i < rhs.terms; i++)
  {
    temp += lhs.data[i] * rhs.data[i];
  }

  return temp;
}

template <class T>
const Vector<T> operator* (const Vector<T>& lhs, const T& rhs)
{
  Vector<T> dotProduct(lhs);

  for(int i = 0; i < lhs.terms; i++)
  {
    dotProduct.data[i] *= rhs;
  }

  return dotProduct;
}

template <class T>
const Vector<T> operator* (const T& lhs, const Vector<T>& rhs)
{
  return (rhs * lhs);
}

template <class T>
bool operator== (const Vector<T>& lhs, const Vector<T>& rhs)
{
  if(lhs.terms != rhs.terms)
  {
    return false;
  }

  for(int i = 0; i < lhs.terms; i++)
  {
    if(lhs.data[i] != rhs.data[i])
    {
      return false;
    }
  }

  return true;
}

template <class T>
bool operator!= (const Vector<T>& lhs, const Vector<T>& rhs)
{
  return !(lhs == rhs);
}

template <class T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& rhs)
{
  for(int i = 0; i < rhs.terms; i++)
  {
    if(i == 0)
    {
      out << "[";
    }

    out << rhs.data[i];

    if(i == rhs.terms - 1)
    {
      out << "]";
    }
    else
    {
      out << ", ";
    }
  }

  return out;
}

template <class T>
std::istream& operator>> (std::istream& in, Vector<T>& rhs)
{
  for(int i = 0; i < rhs.terms; i++)
  {
    in >> rhs[i];
  }

  return in;
}