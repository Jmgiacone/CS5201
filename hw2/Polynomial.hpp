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

template <class T>
Polynomial<T>::Polynomial(const Polynomial<T> &p)
{
  numTerms = 0;
  data = NULL;
  *this = p;
}

template <class T>
Polynomial<T>::Polynomial(const Term<T> &t)
{
  numTerms = 1;
  data = new Term<T>[numTerms];
  data[0] = t;
}

template <class T>
Polynomial<T>::~Polynomial()
{
  numTerms = 0;
  delete [] data;
  data = NULL;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T> &rhs)
{
  //Delete current data if there is any
  if(data != NULL)
  {
    numTerms = 0;
    delete [] data;
    data = NULL;
  }

  numTerms = rhs.numTerms;
  data = new Term<T>[numTerms];

  for(int i = 0; i < numTerms; i++)
  {
    data[i] = rhs.data[i];
  }

  return *this;
}

template <class T>
bool Polynomial<T>::operator== (const Polynomial& rhs) const
{
  if(numTerms == rhs.numTerms)
  {
    for(int i = 0; i < numTerms; i++)
    {
      if(data[i] != rhs.data[i])
      {
        return false;
      }
    }
    return true;
  }

  //Automatically not equal if they have different terms
  return false;
}

template <class T>
bool Polynomial<T>::operator!= (const Polynomial& rhs) const
{
  return !(*this == rhs);
}

template <class T>
const T& Polynomial<T>::operator() (const T& x) const
{
  T result;
  if(numTerms > 0)
  {
    result = data[0](x);
    for (int i = 1; i < numTerms; i++)
    {
      result += data[i](x);
    }
  }
  return result;
}

template <class T>
const Term<T>& Polynomial<T>::operator[] (const int i) const
{
  if(i > 0)
  {
    if(i < numTerms)
    {
      return data[i];
    }
    //i is too big
  }
  //i is too small
}

template <class T>
const Polynomial<T>& Polynomial<T>::operator* (const T& x) const
{
  Polynomial<T> temp(*this);

  for(int i = 0; i < numTerms; i++)
  {
    temp.data[i].coefficient *= x;
  }

  return temp;
}