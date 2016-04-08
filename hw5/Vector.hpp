/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 4
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: Vector.hpp
 * Description: Template implementation file for the Vector class
 */

template <class T>
Vector<T>::Vector()
{
  terms = DEFAULT_TERMS;
  data = new T[terms];

  for(int i = 0; i < terms; i++)
  {
    data[i] = 0;
  }
}

template <class T>
Vector<T>::Vector(const int t)
{
  if(t < 1)
  {
    throw std::invalid_argument("Zero or negative argument provided to constructor!");
  }
  terms = t;
  data = new T[terms];

  for(int i = 0; i < terms; i++)
  {
    data[i] = 0;
  }
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
    throw std::length_error("Left-hand side and right-hand side are of differing length!");
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
    throw std::out_of_range("Illegal range provided to Vector[]!");
  }
  return data[x];
}

template <class T>
const T& Vector<T>::operator[] (const int x) const
{
  if(x < 0 || x >= terms)
  {
    throw std::out_of_range("Illegal range provided to Vector[]!");
  }
  return data[x];
}

template <class T>
int Vector<T>::numTerms() const
{
  return terms;
}
template <class T>
const T operator* (const Vector<T>& lhs, const Vector<T>& rhs)
{
  if(rhs.terms != lhs.terms)
  {
    throw std::length_error("Left-hand side and right-hand side are of differing length!");
  }

  T temp;

  if(rhs.terms != 0)
  {
    temp = lhs.data[0] * rhs.data[0];
    for (int i = 1; i < rhs.terms; i++)
    {
      temp += lhs.data[i] * rhs.data[i];
    }
  }
  return temp;
}

template <class T>
const Vector<T> operator* (const Vector<T>& lhs, const T& rhs)
{
  Vector<T> scalarProduct(lhs);

  for(int i = 0; i < lhs.terms; i++)
  {
    scalarProduct.data[i] *= rhs;
  }

  return scalarProduct;
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
      out << "<";
    }

    out << rhs.data[i];

    if(i == rhs.terms - 1)
    {
      out << ">";
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