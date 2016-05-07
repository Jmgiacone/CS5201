/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: QRDecomposition.hpp
 * Description: This is the header for the QRDecomposition class
 */


template <class T>
QRDecomposition<T>::QRDecomposition()
{
  //Do nothing
  r = TriangularMatrix<T>(5, TRIANGLE_TYPE::UPPER);
}

template <class T>
void QRDecomposition<T>::operator()(const AbstractMatrix<T>& aMatrix)
{
  q = GenericMatrix<T>(aMatrix.rows());
  r = TriangularMatrix<T>(aMatrix.rows(), TRIANGLE_TYPE::UPPER);
  T normResult;
  TwoNorm<T> norm;

  /*for(int i = 0; i < aMatrix.rows(); i++)
  {
    for(int j = 0; j < aMatrix.rows(); j++)
    {
      q[i][j] = 0;
      r[i][j] = 0;
      //q(i, j) = 0;
      //r(i, j) = 0;
    }
  }*/

  for(int i = 0; i < aMatrix.rows(); i++)
  {
    if(i == 0)
    {
      normResult = norm(aMatrix.getColumn(0));
      if(normResult == 0)
      {
        throw std::domain_error("Error in QRDecomposition: Attempted division by zero");
      }

      for(int j = 0; j < aMatrix.rows(); j++)
      {
        q[j][0] = aMatrix[j][0] * (1 / normResult);
      }
    }
    else
    {
      AlgebraVector<T> temp(aMatrix[0]);

      temp = r[0][i] * q.getColumn(0);
      //temp = r(0, i) * q.getColumn(0);

      for(int k = 1; k < i; k++)
      {
        temp += r[k][i] * q.getColumn(k);
        //temp += r(k, i) * q.getColumn(k);
      }

      temp = aMatrix.getColumn(i) - temp;

      r[i][i] = norm(temp);
      //r(i, i) = norm(temp);

      //if(r(i, i) == 0)
      if(r[i][i] == 0)
      {
        throw std::domain_error("QRDecomposition: Attempted division by zero");
      }

      for(int j = 0; j < aMatrix.rows(); j++)
      {
        q[j][i] = (1 / r[i][i]) * temp[j];
        //q(j, i) = (1 / r(i, i)) * temp[j];
      }
    }

    for(int j = 0; j < aMatrix.rows(); j++)
    {
      r[i][j] = aMatrix.getColumn(j) * q.getColumn(i);
      //r(i, j) = aMatrix.getColumn(j) * q.getColumn(i);
    }
  }
}
