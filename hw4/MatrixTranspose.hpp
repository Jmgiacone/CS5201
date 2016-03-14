/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 4
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 3/14/16
 * Filename: MatrixTranspose.hpp
 * Description: Implementation File for Gaussian Elimination functor
 */

template <class T>
Matrix<T> MatrixTranspose<T>::operator()(const Matrix<T>& m)
{
  Matrix<T> transpose(m.getColumns(), m.getRows());

  for(int i = 0; i < m.getRows(); i++)
  {
    for(int j = 0; j < m.getColumns(); j++)
    {
      transpose[j][i] = m[i][j];
    }
  }

  return transpose;
}