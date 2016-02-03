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

}

template <typename T>
T& Polynomial<T>::operator[](const int i) const
{

}

template <typename T>
float Polynomial<T>::operator()(const int x) const
{

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator~() const
{
}

/*template <typename U>
ostream& operator<<(ostream& out, const Term<U> &rhs)
{
  string output = "";
  int coefficient = rhs.coefficient;
  int exponent = rhs.exponent;
  if(coefficient == 0)
  {
    //Zero coefficient -> term is simply zero
    return out;  
  }
  else if(exponent == 0)
  {
    //Zero exponent -> term is simply the coefficient
    output = coefficient;
  }
  else
  {
    //Output coefficient in cx^e format
    output = coefficient + "x^" + exponent;
  }

  out << output;
  return out;
}*/
template <typename T>
void Polynomial<T>::copyArray(T* src, T* dest, int numTerms)
{
  for(int i = 0; i < numTerms; i++)
  {
    dest[i] = src[i];
  }
}
