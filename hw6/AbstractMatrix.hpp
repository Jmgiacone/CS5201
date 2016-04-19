template <class T>
ostream& operator<< (ostream& out, const AbstractMatrix<T>& rhs)
{
  for(int i = 0; i < rhs.numRows(); i++)
  {
    for(int j = 0; j < rhs.numColumns(); j++)
    {
      if(j != 0)
      {
        out << std::setw(10);
      }
      else if (rhs(i, j) >= 0)
      {
        out << " ";
      }
      out << std::fixed << std::setprecision(5) << rhs(i, j) << "\t";
    }

    if (i == rhs.numRows() - 1)
    {

    }
    else
    {
      out << std::endl;
    }
  }

  return out;
}

template <class T>
Vector<T> operator* (const AbstractMatrix<T>& lhs, const Vector<T>& rhs)
{
  return lhs.vectorMultiplication(rhs);
}