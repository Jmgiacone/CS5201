#include <cmath>
#include <stdexcept>
template <class T>
Vector<T> GaussianElimination<T>::operator() (Matrix<T> a, Vector<T> b, bool pivoting)
{
  //Check to make sure b Vector has same number of rows as A matrix has rows
  if(a.getRows() != b.numTerms())
  {
    throw std::invalid_argument("Error: Matrix rows and Vector rows do not match");
  }
  else if(a.getRows() == 0 || a.getColumns() == 0 || b.numTerms() == 0)
  {
    throw std::invalid_argument("Matrix or Vector dimensions are zero!");
  }

  Vector<T> result(a.getColumns());
  int numMultipliers = a.getRows() - 1;
  if(numMultipliers > 0)
  {
    float* multipliers = new float[numMultipliers];

    //Pivoting: At each step, find the largest element in the x position and swap that row to the y position
    if(pivoting)
    {
      for(int i = 0; i < a.getRows(); i++)
      {
        //Search for largest magnitude
        T largestMagnitude = std::abs(a[i][i]), tmp;
        int largestMagnitudeIndex = i;

        for(int l = i+1; l < a.getRows(); l++)
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
          //std::cout << "Largest magnitude is " << a[largestMagnitudeIndex][i] << " at position "
          //<< largestMagnitudeIndex << std::endl;

          //std::cout << "Swapping rows " << i + 1 << " and " << largestMagnitudeIndex + 1 << std::endl;
          swap(a[i], a[largestMagnitudeIndex]);
          std::swap(b[i], b[largestMagnitudeIndex]);

          //std::cout << a << std::endl;
          //std::cout << b << std::endl;
        }

        for(int j = i + 1; j < a.getColumns(); j++)
        {
          multipliers[j - i - 1] = a[j][i] / a[i][i];
          //std::cout << "Multiplying Row " << i << " by " << multipliers[j - i - 1] <<
          //             " and subtracting it from row " << j << std::endl;

          for(int k = i; k < a.getColumns(); k++)
          {
            a[j][k] = a[j][k] - multipliers[j - i - 1] * a[i][k];
          }

          b[j] = b[j] - multipliers[j - i - 1] * b[i];
          //std::cout << a << std::endl;
          //std::cout << b << std::endl;
        }
      }
    }
    else
    {
      //Forward elimination
      for(int i = 0; i < a.getRows(); i++)
      {
        //Get all the multipliers in one go
        for(int j = i + 1; j < a.getColumns(); j++)
        {
          multipliers[j - i - 1] = a[j][i] / a[i][i];
          //std::cout << "Multiplying Row " << i << " by " << multipliers[j - i - 1] <<
          //             " and subtracting it from row " << j << std::endl;
          for(int k = i; k < a.getRows(); k++)
          {
            a[j][k] = a[j][k] - multipliers[j - i - 1] * a[i][k];
          }
          b[j] = b[j] - multipliers[j - i - 1] * b[i];
          //std::cout << a << std::endl;
          //std::cout << b << std::endl;
        }
      }
    }

    //std::cout << "Forward Elim complete" << std::endl;
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;

    //std::cout << "Begin back sub" << std::endl;

    //Back substitution
    for(int i = a.getRows() - 1; i >= 0; i--)
    {
      for(int j = a.getColumns() - 1; j > i; j--)
      {
        //std::cout << "b" << i+1 << " = " << b[i] << " - " << result[j] << " * " << a[j][i] << " = ";
        b[i] = b[i] - result[j] * a[i][j];
        //std::cout << b[i] << std::endl;
      }

      //std::cout << "x" << i+1 << " = " << b[i] << " / " << a[i][i] << " = ";
      result[i] = b[i] / a[i][i];
      //std::cout << result[i] << std::endl;
    }
    //std::cout << "Back sub complete. Answer = " << result << std::endl;
    delete [] multipliers;
  }
  return result;
}