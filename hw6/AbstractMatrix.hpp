template <class T>
ostream& operator<< (ostream& out, const AbstractMatrix<T>& rhs)
{
  return rhs.output(out);
}