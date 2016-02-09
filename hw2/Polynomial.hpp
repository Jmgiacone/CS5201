template <class T>
Polynomial<T>::Polynomial()
{
  numTerms = 0;
  maxTerms = DEFAULT_MAX_TERMS;
  data = NULL;
}

template <class T>
Polynomial<T>::Polynomial(const int n)
{
  maxTerms = n;
  numTerms = 0;

  if(maxTerms < 0)
  {
    //throw an error
  }
  data = (maxTerms == 0 ? NULL : new Term<T>[maxTerms]);
}

template <class T>
Polynomial<T>::Polynomial(const Polynomial<T> &p)
{
  numTerms = 0;
  maxTerms = 0;
  data = NULL;
  *this = p;
}

template <class T>
Polynomial<T>::Polynomial(const Term<T> &t)
{
  numTerms = 1;
  maxTerms = DEFAULT_MAX_TERMS;
  data = new Term<T>[maxTerms];
  data[0] = t;
}

template <class T>
Polynomial<T>::~Polynomial()
{
  numTerms = 0;
  maxTerms = 0;
  
  if(data != NULL)
  {
    delete [] data;
  }
  data = NULL;
}

template <class T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial<T> &rhs)
{
  //Return calling object if we're setting it equal to itself
  if(*this == rhs)
  {
    return *this;
  }
  //Delete current data if there is any
  if(data != NULL)
  {
    numTerms = 0;
    maxTerms = 0;
    delete [] data;
    data = NULL;
  }

  numTerms = rhs.numTerms;
  maxTerms = rhs.maxTerms;
  data = new Term<T>[maxTerms];

  for(int i = 0; i < numTerms; i++)
  {
    data[i] = rhs.data[i];
  }

  return *this;
}

template <class T>
bool Polynomial<T>::operator== (const Polynomial<T>& rhs) const
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
const Polynomial<T> Polynomial<T>::operator* (const T& x) const
{
  Polynomial<T> temp(*this);

  for(int i = 0; i < numTerms; i++)
  {
    temp.data[i].coefficient *= x;
  }

  return temp;
}

template <class T>
const Polynomial<T> Polynomial<T>::operator+ (const Polynomial<T>& rhs) const
{
  Polynomial<T> temp(numTerms + rhs.numTerms);

  int thisIndex = 0, rhsIndex = 0, tempIndex = 0;

  while(thisIndex < numTerms && rhsIndex < rhs.numTerms)
  {
    if(data[thisIndex].exponent < rhs.data[rhsIndex].exponent)
    {
      temp.data[tempIndex] = rhs.data[rhsIndex];
      temp.numTerms++;
      rhsIndex++;
      tempIndex++;
    }
    else if(data[thisIndex].exponent > rhs.data[rhsIndex].exponent)
    {
      temp.data[tempIndex] = data[thisIndex];
      temp.numTerms++;
      thisIndex++;
      tempIndex++;
    }
    else
    {
      //Same exponents, add coefficients
      T x = data[thisIndex].coefficient + rhs.data[rhsIndex].coefficient;
      T exp = data[thisIndex].exponent;
      rhsIndex++;
      thisIndex++;
      if(x == 0)
      {
        //Coefficients cancel out, skip this term
      }
      else
      {
        Term<T> t(x, exp);
        temp.data[tempIndex] = t;
        temp.numTerms++;
        tempIndex++;
      }
    }
  }

  if(thisIndex < numTerms)
  {
    for(int i = thisIndex; i < numTerms; i++)
    {
      temp.data[tempIndex] = data[i];
      tempIndex++;
      temp.numTerms++;
    }
  }
  else
  {
    for(int i = rhsIndex; i < rhs.numTerms; i++)
    {
      temp.data[tempIndex] = rhs.data[i];
      tempIndex++;
      temp.numTerms++;
    }
  }

  //Complete cancellation check
  if(temp.numTerms == 0)
  {
    delete [] temp.data;
    temp.data = NULL;
  }
  return temp;
}

template <class T>
const Polynomial<T>& Polynomial<T>::operator+= (const Polynomial<T>& rhs)
{
  *this = *this + rhs;

  return *this;
}

template <class T>
const Polynomial<T> Polynomial<T>::operator~ () const
{
  Polynomial<T> tmp(*this);

  for(int i = 0; i < numTerms; i++)
  {
    if(tmp.data[i].coefficient > 0)
    {
      tmp.data[i].coefficient *= -1;
    }
  }

  return tmp;
}

template <class T>
const Polynomial<T> Polynomial<T>::operator- () const
{
  Polynomial<T> tmp(*this);

  for(int i = 0; i < numTerms; i++)
  {
    tmp.data[i].coefficient *= -1;
  }

  return tmp;
}

template <class T>
const Polynomial<T> Polynomial<T>::operator- (const Polynomial<T>& rhs) const
{
  Polynomial<T> tmp(15);

  return tmp;
}

template <class T>
const Polynomial<T>& Polynomial<T>::operator-= (const Polynomial<T>& rhs)
{
  *this = *this - rhs;

  return *this;
}