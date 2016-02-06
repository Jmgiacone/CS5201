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
    maxTerms = 0;
    delete [] data;
    data = NULL;
  }

  if(*this == rhs)
  {
    return *this;
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
  std::cout << "Entered + operator" << std::endl;
  int x = numTerms + rhs.numTerms;
  Polynomial<T> temp((x > DEFAULT_MAX_TERMS ? x : DEFAULT_MAX_TERMS));
  int thisIndex = 0, rhsIndex = 0, tempIndex = 0;
  //Term<T> thisTerm, rhsTerm;
  //Case 1: This is empty and adding rhs in
  //Case 2: This is not empty and adding in empty rhs
  //Case 3: Both are empty

  if(numTerms == 0 && rhs.numTerms == 0)
  {
    std::cout << "Both are empty" << std::endl;
    //Both are empty
    //return empty polynomial
    return temp;
  }
  else if(numTerms == 0)
  {
    std::cout << "This object is empty" << std::endl;
    temp.numTerms = rhs.numTerms;
    for(int i = 0; i < rhs.numTerms; i++)
    {
      temp.data[i] = rhs.data[i];
    }
  }
  else if(rhs.numTerms == 0)
  {
    std::cout << "RHS is empty" << std::endl;
    temp.numTerms = numTerms;
    for(int i = 0; i < numTerms; i++)
    {
      temp.data[i] = data[i];
    }
  }
  else
  {
    //Merge the two lists in descending order

    std::cout << "Neither is empty - merging" << std::endl;
    //thisTerm = data[thisIndex];
    //rhsTerm = rhs.data[rhsIndex];
    while(thisIndex < numTerms || rhsIndex < rhs.numTerms)
    {
      while(thisIndex < numTerms && data[thisIndex].exponent > rhs.data[rhsIndex].exponent)
      {
        std::cout << "Checking this object" << std::endl;
        temp.data[tempIndex] = data[thisIndex];
        temp.numTerms++;
        tempIndex++;
        thisIndex++;
      }

      while(rhsIndex < rhs.numTerms && rhs.data[rhsIndex].exponent > data[thisIndex].exponent)
      {
        std::cout << "Checking other object" << std::endl;
        temp.data[tempIndex] = rhs.data[rhsIndex];
        temp.numTerms++;
        tempIndex++;
        rhsIndex++;
      }
    }
  }

  return temp;
}