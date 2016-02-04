#include <cmath>

template <class T>
Polynomial<T>::Polynomial()
{
  numTerms = 0;
  data = NULL;
}

template <class T>
Polynomial<T>::Polynomial(const int n)
{
  numTerms = n;
  data = new Term<T>[numTerms];
}

template<typename T>
Polynomial<T>::Polynomial(const Polynomial<T> &src)
{
  numTerms = src.numTerms;

  data = new Term<T>[numTerms];

  copyArray(src.data, data, numTerms);
}

template <typename T>
Polynomial<T>::Polynomial(Term<T>* terms, int n)
{
  data = new Term<T>[n];
  numTerms = n;

  for(int i = 0; i < numTerms; i++)
  {
    data[i] = terms[i];
  }
}

template<typename T>
Polynomial<T>::~Polynomial()
{
  delete [] data;
  data = NULL;
}

//Operators
template<typename T>
Polynomial<T>& Polynomial<T>::operator+(const Polynomial<T> &rhs) const
{

}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-(const Polynomial<T> &rhs) const
{

}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-() const
{

}

template<typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T> &rhs)
{

}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial<T> &rhs)
{

}

template<typename T>
bool Polynomial<T>::operator==(const Polynomial<T> &rhs) const
{

}

template<typename T>
bool Polynomial<T>::operator!=(const Polynomial<T> &rhs) const
{
  return !(*this == rhs);
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator*(const float f) const
{

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T> &rhs)
{
  if(rhs.numTerms > 0)
  {
    if(data != NULL)
    {
      delete [] data;
    }
    numTerms = rhs.numTerms;
    data = new Term<T>[numTerms];

    for(int i = 0; i < numTerms; i++)
    {
      data[i] = rhs.data[i];
    }
  }
}

template <typename T>
T& Polynomial<T>::operator[](const int i) const
{

}

template <typename T>
T Polynomial<T>::operator()(const int x) const
{
  T answer = 0;
  for(int i = 0; i < numTerms; i++)
  {
    answer += data[i].coefficient * std::pow(x, data[i].exponent);
  }

  return answer;
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator~() const
{
}

template <typename T>
void Polynomial<T>::copyArray(Term<T>* src, Term<T>* dest, int numTerms)
{
  for(int i = 0; i < numTerms; i++)
  {
    dest[i] = src[i];
  }
}
