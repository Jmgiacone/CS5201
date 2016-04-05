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

template <class T>
ostream& operator<< (ostream& out, const Matrix<T>& rhs)
{
  return operatorOutput(out, rhs);
}

template <class T>
Matrix<T> operator+ (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return operatorPlus(lhs, rhs);
}

template <class T>
Matrix<T> operator- (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return operatorMinus(lhs, rhs);
}

template <class T>
Matrix<T> operator* (const T& lhs, const Matrix<T>& rhs)
{
  return operatorAsterisk(lhs, rhs);
}

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const T& rhs)
{
  return operatorAsterisk(lhs, rhs);
}

template <class T>
Matrix<T> operator* (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return operatorAsterisk(lhs, rhs);
}

template <class T>
Vector<T> operator* (const Matrix<T>& lhs, const Vector<T>& rhs)
{
  return operatorAsterisk(lhs, rhs);
}

template <class T>
Vector<T> operator* (const Vector<T>& lhs, const Matrix<T>& rhs)
{
  return operatorAsterisk(lhs, rhs);
}

template <class T>
bool operator== (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return operatorDoubleEqual(lhs, rhs);
}

template <class T>
bool operator!= (const Matrix<T>& lhs, const Matrix<T>& rhs)
{
  return operatorBangEqual(lhs, rhs);
}