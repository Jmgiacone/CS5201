/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: Matrix.hpp
 * Description: This is a function definition file for the Matrix friend functions
 */

template <class T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T>& rhs)
{
  return (*this = operatorPlus(*this, rhs));
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& rhs)
{
  return (*this = operatorMinus(*this, rhs));
}