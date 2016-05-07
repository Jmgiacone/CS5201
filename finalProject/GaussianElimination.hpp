/**
 *  @file GaussianElimination.hpp
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 8, 2016
 *  @brief Description: Header File for Gaussian Elimination functor
 *  @details Details:
 */

#include <cmath>
#include <stdexcept>
template <class T>
AlgebraVector<T> GaussianElimination<T>::operator() (GenericMatrix<T> a, AlgebraVector<T> b)
{
  if(a.rows() != b.size())
  //if(a.numRows() != b.numTerms())
  {
    //B vector isn't same size as input matrix
    throw std::invalid_argument("Dimension mismatch! input matrix and answer vector are of differening dimensions");
  }
  else if(a.rows() != a.columns())
  //else if(a.numRows() != a.numColumns())
  {
    //Non-square Matrix
    throw std::invalid_argument("Input Matrix is not square! Please only use Gaussian Elimination on a square or Augmented Matrix");
  }
  GenericMatrix<T> augmented(a.rows(), a.columns()+1, 0);
  //Matrix<T> augmented(a.numRows(), a.numColumns()+1);
  AlgebraVector<T> result(a.rows(), 0);
  //Vector<T> result(a.numRows());

  //Create an augmented matrix from A and B
  int rows = static_cast<int>(augmented.rows());
  int columns = static_cast<int>(augmented.columns());
  for(int i = 0; i < rows; i++)
  //for(int i = 0; i < augmented.numRows(); i++)
  {
    for(int j = 0; j < columns - 1; j++)
    //for(int j = 0; j < augmented.numColumns()-1; j++)
    {
      augmented[i][j] = a[i][j];
    }
    augmented[i][augmented.columns()-1] = b[i];
    //augmented[i][augmented.numColumns()-1] = b[i];
  }

  augmented = (*this)(augmented);

  int vectSize = static_cast<int>(result.size());
  for(int i = 0; i < vectSize; i++)
  //for(int i = 0; i < result.numTerms(); i++)
  {
    result[i] = augmented[i][augmented.columns()-1];
    //result[i] = augmented[i][augmented.numColumns()-1];
  }

  return result;
}

template <class T>
GenericMatrix<T> GaussianElimination<T>::operator()(GenericMatrix <T> a)
{
  if(a.rows() != a.columns() - 1)
  //if(a.numRows() != a.numColumns() - 1)
  {
    //Matrix is not augmented
    throw std::invalid_argument("Input Matrix is not augmented (Rows != Columns - 1)");
  }
  else if(a.rows() == 0 || a.columns() == 0)
  //else if(a.numRows() == 0 || a.numColumns() == 0)
  {
    //Zero Dimensions
    throw std::invalid_argument("Matrix dimensions are zero!");
  }

  int numMultipliers = static_cast<int>(a.rows()) - 1;
  int rows = static_cast<int>(a.rows());
  int columns = static_cast<int>(a.columns());
  //int numMultipliers = a.numRows() - 1;
  if(numMultipliers > 0)
  {
    T* multipliers = new T[numMultipliers];

    //Forward Elimination
    for(int i = 0; i < rows; i++)
    //for(int i = 0; i < a.numRows(); i++)
    {
      for(int j = i + 1; j < columns - 1; j++)
      //for(int j = i + 1; j < a.numColumns() - 1; j++)
      {
        if(a[i][i] == 0)
        {
          throw std::domain_error("Attempted Division by zero in forward elimination");
        }

        multipliers[j - i - 1] = a[j][i] / a[i][i];
        a[j][i] = 0;
        for(int k = i+1; k < columns; k++)
        //for(int k = i+1; k < a.numColumns(); k++)
        {
          a[j][k] = a[j][k] - multipliers[j - i - 1] * a[i][k];
        }
      }
    }

    //Back substitution
    for(int i = rows - 1; i >=0; i--)
    //for(int i = a.numRows() - 1; i >= 0; i--)
    {
      for(int j = columns - 2; j > i; j--)
      //for(int j = a.numColumns() - 2; j > i; j--)
      {
        a[i][a.columns() - 1] = a[i][a.columns() - 1] - a[j][a.columns() - 1] * a[i][j];
        //a[i][a.numColumns()-1] = a[i][a.numColumns()-1] - a[j][a.numColumns()-1] * a[i][j];
        a[i][j] = 0;
      }

      if(a[i][i] == 0)
      {
        throw std::domain_error("Attempted Division by zero in backward substitution");
      }
      a[i][a.columns()-1] = a[i][a.columns()-1] / a[i][i];
      //a[i][a.numColumns()-1] = a[i][a.numColumns()-1] / a[i][i];
      a[i][i] = 1;
    }
    delete [] multipliers;
  }

  return a;
}

/*template <class T>
AlgebraVector<T> GaussianElimination<T>::operator()(AbstractMatrix<T>& aMatrix, const Vector<T>& bVector)
{
  return aMatrix.gaussElimation(bVector);
}*/
