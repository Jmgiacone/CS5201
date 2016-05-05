/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 4
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: GaussianElimination.hpp
 * Description: HImplementation File for Gaussian Elimination functor
 */

#include <cmath>
#include <stdexcept>
template <class T>
Vector<T> GaussianElimination<T>::operator() (Matrix<T> a, Vector<T> b, bool pivoting)
{
  if(a.numRows() != b.numTerms())
  {
    //B vector isn't same size as input matrix
    throw std::invalid_argument("Dimension mismatch! input matrix and answer vector are of differening dimensions");
  }
  else if(a.numRows() != a.numColumns())
  {
    //Non-square Matrix
    throw std::invalid_argument("Input Matrix is not square! Please only use Gaussian Elimination on a square or Augmented Matrix");
  }
  Matrix<T> augmented(a.numRows(), a.numColumns()+1);
  Vector<T> result(a.numRows());

  //Create an augmented matrix from A and B
  for(int i = 0; i < augmented.numRows(); i++)
  {
    for(int j = 0; j < augmented.numColumns()-1; j++)
    {
      augmented[i][j] = a[i][j];
    }
    augmented[i][augmented.numColumns()-1] = b[i];
  }

  augmented = (*this)(augmented, pivoting);

  for(int i = 0; i < result.numTerms(); i++)
  {
    result[i] = augmented[i][augmented.numColumns()-1];
  }

  return result;
}

template <class T>
Matrix<T> GaussianElimination<T>::operator()(Matrix <T> a, bool pivoting)
{
  if(a.numRows() != a.numColumns() - 1)
  {
    //Matrix is not augmented
    throw std::invalid_argument("Input Matrix is not augmented (Rows != Columns - 1)");
  }
  else if(a.numRows() == 0 || a.numColumns() == 0)
  {
    //Zero Dimensions
    throw std::invalid_argument("Matrix dimensions are zero!");
  }

  int numMultipliers = a.numRows() - 1;
  if(numMultipliers > 0)
  {
    T* multipliers = new T[numMultipliers];

    //Forward Elimination
    for(int i = 0; i < a.numRows(); i++)
    {
      for(int j = i + 1; j < a.numColumns() - 1; j++)
      {
        if(pivoting)
        {
          //Search for largest magnitude
          T largestMagnitude = std::abs(a[i][i]), tmp;
          int largestMagnitudeIndex = i;

          for(int l = i+1; l < a.numRows(); l++)
          {
            tmp = std::abs(a[l][i]);

            if(tmp > largestMagnitude)
            {
              largestMagnitude = tmp;
              largestMagnitudeIndex = l;
            }
          }
          if(largestMagnitudeIndex != i)
          {
             swap(a[i], a[largestMagnitudeIndex]);
          }
        }

        if(a[i][i] == 0)
        {
          throw std::domain_error("Attempted Division by zero in forward elimination");
        }

        multipliers[j - i - 1] = a[j][i] / a[i][i];
        a[j][i] = 0;
        for(int k = i+1; k < a.numColumns(); k++)
        {
          a[j][k] = a[j][k] - multipliers[j - i - 1] * a[i][k];
        }
      }
    }

    //Back substitution
    for(int i = a.numRows() - 1; i >= 0; i--)
    {
      for(int j = a.numColumns() - 2; j > i; j--)
      {
        a[i][a.numColumns()-1] = a[i][a.numColumns()-1] - a[j][a.numColumns()-1] * a[i][j];
        a[i][j] = 0;
      }

      if(a[i][i] == 0)
      {
        throw std::domain_error("Attempted Division by zero in backward substitution");
      }
      a[i][a.numColumns()-1] = a[i][a.numColumns()-1] / a[i][i];
      a[i][i] = 1;
    }
    delete [] multipliers;
  }

  return a;
}

template <class T>
Vector<T> GaussianElimination<T>::operator()(AbstractMatrix<T>& aMatrix, const Vector<T>& bVector)
{
  return aMatrix.gaussElimation(bVector);
}