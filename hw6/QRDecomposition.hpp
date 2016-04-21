#include "DenseMatrix.h"
#include "TwoNorm.h"

template <class T>
std::vector<AbstractMatrix<T>*> QRDecomposition<T>::operator()(const AbstractMatrix<T>& aMatrix)
{
  std::vector<AbstractMatrix<T>*> matrices;
  DenseMatrix<T> q(aMatrix.numRows(), aMatrix.numRows());
  UpperTriangularMatrix<T> r(aMatrix.numRows());
  T normResult;
  TwoNorm<T> norm;

  for(int i = 0; i < aMatrix.numRows(); i++)
  {
    normResult = norm(aMatrix.getColumn(0));
    if(i == 0)
    {
      if(normResult == 0)
      {
        throw std::domain_error("Error in QRDecomposition: Attempted division by zero");
      }

      for(int j = 0; j < aMatrix.numRows(); j++)
      {
        q(j, 0) = aMatrix(j, 0) * (1 / normResult);
      }
    }
    else
    {
      Vector<T> temp(aMatrix.numRows());

      temp = r(0, i) * q.getColumn(0);

      for(int k = 1; k < i; k++)
      {
        temp += r(k, i) * q.getColumn(k);
      }

      temp = aMatrix.getColumn(i) - temp;

      r(i, i) = norm(temp);

      if(r(i, i) == 0)
      {
        throw std::domain_error("QRDecomposition: Attempted division by zero");
      }
    }

    for(int j = 0; j < aMatrix.numRows(); j++)
    {
      r(i, j) = aMatrix.getColumn(j) * q.getColumn(i);
    }
  }


  matrices.push_back(&q);
  matrices.push_back(&r);
  return matrices;
}