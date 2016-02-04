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

