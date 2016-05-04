//============================================================================
// Name        : CS5201_Project_Vector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iomanip>
#include <fstream>
#include <string>
//#include "gaussiansolver.h"
#include "tridiagonalmatrix.h"
#include "triangularmatrix.h"
#include "diagonalmatrix.h"
#include "symmetricmatrix.h"
#include "qrdecompose.h"
//#include "cubicsplineinterpolate.h"

#define line_width 20
#define number_max 9
using namespace std;

///@brief sends a message out with cout with format so output appears centered
///and uses '=' for filling
///@pre none
///@post message is formatted to terminal
void print_seperator(string message)
{
  cout << setfill('=');
  cout << setw((line_width + 5) - (message.size() / 2)) << left << "====="
      << setw(line_width + (message.size() / 2)) << left << message << setw(7)
      << left << "=====" << endl;
  cout << setfill(' ');
}

///@brief sets the format for the given os object
///@pre none
/// message is formatted with width set width, precision of precision, and right alignment
void print_formater(std::ostream & os, const int precision = 5,
    const int width = number_max)
{
  os << setw(width) << fixed << setprecision(precision) << right;
}

///@brief prints the middle indexes of an matrix
/// @pre none
/// prints out middle in a row
void print_middle(const AbstractMatrix<double>& matrix)
{
  size_t min_dim =
      (matrix.rows() < matrix.columns()) ? matrix.rows() : matrix.columns();
  for (int i = 0; i < min_dim; i++)
  {
    print_formater(cout);
    cout << matrix[i][i];
  }
  cout << endl;
}

///@brief calculates y based on the equation 1/(1 + 10*(x^2))
///@pre none
///@post returns the value of y for the stated equation by value
double realF_x(double x)
{
  return (1 / (1 + (10 * (x * x))));
}

///@brief caculates absolute error based on x_real an approximation
///@pre none
///@post returns the absolute error of the two arguments by value
double absolute_error(const double x_real, const double x_approximate)
{
  return abs(x_real - x_approximate);
}

///@brief calculates relative error based on x_real an approximation
///@pre none
///@post returns the relative error of the two arguments by value
double relative_error(const double x_real, const double x_approximate)
{
  return absolute_error(x_real, x_approximate) / x_real;
}

///@brief calculates the approximation of x using vandermonde interpolation
///@pre solved is the vector result of solving the Xa = y equation, a, for the same
/// function that x corresponds to
///@post returns the approximated value of y from an arbitrary x from an arbitrary function
double vandermonde_interpolate(const AlgebraVector<double>& solved,
    const double x)
{
  DynamicArray<double> x_co_factors;
  x_co_factors.append(1.0);
  double set_x = x;
  for (size_t i = 1; i < solved.size(); i++)
  {
    x_co_factors.append(set_x);
    set_x *= x;
  }
  return solved * AlgebraVector<double>(x_co_factors);
}
int main(int argc, char** argv)
{

  if (argc == 1)
  {
    cerr << "No file detected in parameters, quitting" << endl;
    return 1;
  }

  ifstream file(argv[1]);
  if (!file.is_open())
  {
    cerr << "Could Not Open File \n" << "exiting" << endl;
    return 1;
  }

  GenericMatrix<double> matrix_1;
  GenericMatrix<double> matrix_2;
  try
  {
    file >> matrix_1;
    file >> matrix_2;
  }
  catch (std::logic_error& e)
  {
    std::cerr << e.what() << std::endl;
  }
  file.close();

  for (size_t i = 0; i < matrix_1.rows(); i++)
  {
    if (matrix_1[i].size() != matrix_1[0].size())
    {
      cerr
          << "Error, size mismatch, vector size does not match given dimention. size "
          << matrix_1[i].size() << " vs given dimension " << matrix_1[0].size()
          << endl;
      return 1;
    }
  }

  cout << "//note, vectors are output horizontally" << endl;
  cout << "//note, output set to fixed and precision 5" << endl;
  cout << "//note, using absolute value of difference for Absolute Error"
      << endl;

  cout << "== printing input" << endl;

  print_formater(cout);
  cout << matrix_1 << endl;
  print_formater(cout);
  cout << matrix_2 << endl;


  double r1[] = { 12, -51, 4, 3 };
  double r2[] = { 6, 167, -68, 4, 3 };
  double r3[] = { -4, 24, -41, 3 };
  DynamicArray<double> dr1(4, 4, r1);
  DynamicArray<double> dr2(5, 5, r2);
  DynamicArray<double> dr3(4, 4, r3);
  AlgebraVector<double> av1(dr1);
  AlgebraVector<double> av2(dr2);
  AlgebraVector<double> av3(dr3);
  AlgebraVector<double> avr[] = { av1, av2, av3 };
  DynamicArray<AlgebraVector<double> > dv(3, 3, avr);
  GenericMatrix<double> gm(dv);
  print_formater(cout, 4, 20);
  cout << gm << endl;

  print_formater(cout, 4, 20);
  //cout << GenericMatrix<double>(Q) << endl;
  print_formater(cout, 4, 20);
  //cout << GenericMatrix<double>(R) << endl;
  cout << "== diagonal * diagonal " << std::endl;
  DiagonalMatrix<double> diagonal(av2);

  print_formater(cout, 4, 20);

  cout << (diagonal * diagonal) << std::endl;
/*
  cout << "== tridiagonal * tridiagonal " << std::endl;
  TriDiagonalMatrix<double> tridiagonal(av1, av2, av3);
  print_formater(cout, 4, 20);
  cout << tridiagonal * tridiagonal << std::endl;

  cout << "== uppertriangular by upper triangular" << endl;
  AlgebraVector<double> v1(DynamicArray<double>(5, 5.0));
  AlgebraVector<double> v2(DynamicArray<double>(4, 4.0));
  AlgebraVector<double> v3(DynamicArray<double>(3, 3.0));
  AlgebraVector<double> v4(DynamicArray<double>(2, 2.0));
  AlgebraVector<double> v5(DynamicArray<double>(1, 1.0));
  DynamicArray<AlgebraVector<double>> triangleu;
  triangleu.append(v1);
  triangleu.append(v2);
  triangleu.append(v3);
  triangleu.append(v4);
  triangleu.append(v5);
  TriangularMatrix<double> trimat(UPPER, triangleu);
  print_formater(cout, 4, 20);
  cout << trimat * trimat << std::endl;
  */
  try
  {
/*
    GenericMatrix<double> A(matrix_1);
    GenericMatrix<double> A2(matrix_2);
    GenericMatrix<double> A1(matrix_1);
    GenericMatrix<double> A_old;
    GenericMatrix<double>  Q;
    GenericMatrix<double>  R;

    int iters;

    //QR(A, Q, R);
    print_formater(cout);
    cout << GenericMatrix<double>(Q) << endl;
    print_formater(cout);
    cout << GenericMatrix<double>(R) << endl;
    print_formater(cout);
    cout << GenericMatrix<double>(Q) * GenericMatrix<double>(R) << endl;

    print_formater(cout);
    cout << GenericMatrix<double>(R) * GenericMatrix<double>(Q) << endl;
    print_seperator(" Iteration 5 - Matrix 1 ");
    QR.iterate(A1, A_old, Q, R, 30);
    print_formater(cout);
    cout << A1 << endl;
    print_seperator(" Iteration 10 - Matrix 1 ");
    //QR.iterate(A1, A_old, Q, R, 5);
    print_formater(cout);
    cout << A1 << endl;
    print_seperator(" Final iteration - Matrix 1 ");
    QR.iterate_tolerance(A1, A_old, Q, R, 0.0001);
    print_formater(cout);
    cout << A1 << endl;
    print_seperator(" Reason - Matrix 1 ");
    cout
        << "tolerance met for diagonal value differences between previous iteration and current"
        << std::endl;
    cout << "tolerance value met: " << 0.00001 << std::endl;
    print_seperator(" Eigenvalues - Matrix 1 ");
    print_middle(A1);
    print_seperator(" Iteration 5 - Matrix 2 ");
    QR.iterate(A2, A_old, Q, R, 10000);
    print_formater(cout);
    cout << A2 << endl;
    print_seperator(" Iteration 10 - Matrix 2 ");
    QR.iterate(A2, A_old, Q, R, 5);
    print_formater(cout);
    cout << A2 << endl;
    print_seperator(" Final iteration - Matrix 2 ");
    QR.iterate_tolerance(A2, A_old, Q, R, 0.0000001);
    print_formater(cout);
    cout << A2 << endl;
    print_seperator(" Reason - Matrix 2 ");
    cout
        << "tolerance met for diagonal value differences between previous iteration and current"
        << std::endl;
    cout << "tolerance value met: " << 0.00001 << std::endl;
    print_seperator(" Eigenvalues - Matrix 2 ");
    print_middle(A2);
    */
  }
  catch (std::logic_error& e)
  {
    std::cerr << e.what() << std::endl;
  }
  print_seperator(" end ");
  return 0;
}
