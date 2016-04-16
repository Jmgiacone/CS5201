template <class T>
ostream& operator<< (ostream& out, const AbstractMatrix<T>& rhs)
{
  return rhs.output(out);
}

template <class T>
Vector<T> operator* (const AbstractMatrix<T>& lhs, const Vector<T>& rhs)
{
  return lhs.vectorMultiplication(rhs);
}