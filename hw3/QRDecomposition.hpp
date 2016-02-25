#include <iostream>
#include <vector>
#include "TwoNorm.h"
#include "Vector.h"

template<class T>
std::vector<std::vector<Vector<T>>>& QRDecomposition<T>::operator()(const std::vector<Vector<T>>& a)
{
  int n = a[0].numTerms();
  TwoNorm<T> norm;
  std::vector<Vector<T>> r(n), q(n);

  //Initialize Q and R matrices
  for(int i = 0; i < n; i++)
  {
    Vector<T> temp(n);

    q.push_back(temp);
    r.push_back(temp);
  }

  //r[i][j] -> jth element of the ith vector

  //Q1 = A1/||A1||2
  q[0] = a[0] * (1 / (norm(a[0])));

  for(int i = 0; i < n; i++)
  {
    //Generate r[i][0] for i < n (first element of every vector)
    for (int j = i; j < n; j++)
    {
      //r[i][j] = (a[j], q[i]) <- Dot product
      r[i][j] = a[j] * q[i];
    }

    //Generate r[i][i]
    if (i != 0)
    {
      Vector<T> temp(n);

      temp = r[i][0] * q[0];
      for(int k = 1; k < i; k++)
      {
        temp += r[i][k] * q[k];
      }

      temp = a[i] - temp;

      r[i][i] = (norm(temp));

      q[i] = (1 / r[i][i]) * (temp);
    }
  }

  std::vector<std::vector<Vector<T>>> qr;
  qr.push_back(q);
  qr.push_back(r);

  return qr;
}