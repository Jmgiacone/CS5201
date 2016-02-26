#include <iostream>
#include <vector>
#include "TwoNorm.h"
#include "Vector.h"

template<class T>
std::vector<std::vector<Vector<T>>> QRDecomposition<T>::operator()(const std::vector<Vector<T>>& a)
{
  int n = a[0].numTerms();
  TwoNorm<T> norm;
  std::vector<Vector<T>> r(n), q(n);

  //Initialize Q and R matrices
  for(int i = 0; i < n; i++)
  {
    Vector<T> temp(n);

    q[i] = temp;
    r[i] = temp;
  }

  //r[i][j] -> jth element of the ith vector
  for(int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      //Q1 = A1/twoNorm(A1)
      q[0] = a[0] * (1 / (norm(a[0])));
    }
    else
    {
      //Generate r[i][i]
      Vector<T> temp(n);

      temp = r[i][0] * q[0];
      for(int k = 1; k < i; k++)
      {
        temp += r[i][k] * q[k];
      }

      temp = a[i] - temp;

      r[i][i] = norm(temp);

      q[i] = (1 / r[i][i]) * temp;
    }

    //Generate r[j][i]
    for (int j = 0; j < n; j++)
    {
      if(j < i)
      {
        r[j][i] = 0;
      }
      else
      {
        //r[j][i] = (a[j], q[i]) <- Dot product
        r[j][i] = a[j] * q[i];
      }
    }
  }
  std::vector<std::vector<Vector<T>>> qr;
  qr.push_back(q);
  qr.push_back(r);

  return qr;
}