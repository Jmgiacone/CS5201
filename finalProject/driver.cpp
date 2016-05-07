/**
 *  @file driver.cpp
 *  @author Jordan Giacone, Shae Bolt , CS5201 Section A
 *  @date May 5, 2016
 *  @brief Description: driver that tests PDE solving techniques.
 *  @details Details:
 */


#include <iostream>
#include "LaplaceBVector.h"
#include "LaplaceMatrix.h"
#include "QRDecomposition.h"
using std::cout;
using std::cin;
using std::endl;

#define line_width 20
#define number_max 14
#define default_precision 20
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
void print_formatter(std::ostream & os, const int precision = default_precision,
    const int width = number_max)
{
  os << setw(width) << fixed << setprecision(precision) << right;
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

double topFunction(double x, double y);
double bottomFunction(double x, double y);
double leftFunction(double x, double y);
double rightFunction(double x, double y);
double gFunction(double x, double y);
double realFunction(double x, double y);

int main()
{
  const size_t n = 25;
  AlgebraVector<double> laplace_result_QRDEC = laplaceMatrixSolver<topFunction,
      bottomFunction, leftFunction, rightFunction, gFunction, double>(n, true);
  AlgebraVector<double> laplace_result_GAUSS = laplaceMatrixSolver<topFunction,
      bottomFunction, leftFunction, rightFunction, gFunction, double>(n, false);



  const double h = 1 / static_cast<double>(n);
  int i = 0;
  print_seperator(" Laplace comparison for Gaussian Elimination ");
  for(size_t y = 1; y < n; y++)
  {
    for(size_t x = 1; x < n; x++)
    {
      double real_val = realFunction(x*h, y*h);
      double laplace_val = laplace_result_GAUSS[i];
      double a_err = relative_error(real_val, laplace_val);
      print_formatter(cout);
      cout << "Point (" << x*h << ", " << y*h << "): real value = " << real_val << " laplace approximation = " << laplace_val << " Relative error = " << a_err << endl;
      i++;
    }
  }
  i = 0;
  print_seperator(" Laplace comparison for QR Decomposition ");
  for(size_t y = 1; y < n; y++)
  {
    for(size_t x = 1; x < n; x++)
    {
      double real_val = realFunction(x*h, y*h);
      double laplace_val = laplace_result_QRDEC[i];
      double a_err = absolute_error(real_val, laplace_val);
      print_formatter(cout);
      cout << "Point (" << x*h << ", " << y*h << "): real value = " << real_val << " laplace approximation = " << laplace_val << " Relative error = " << a_err << endl;
      i++;
    }
  }
  return 0;
}

double topFunction(double x, double y)
{
  return 2 * bottomFunction(x, y);
}
double bottomFunction(double x, double y)
{
  double tmp = y;
  y = tmp;
  return 1 - x * x;
}

double leftFunction(double x, double y)
{
  double tmp = x;
  x = tmp;
  return 1 + y * y;
}

double rightFunction(double x, double y)
{
  double tmp = x;
  x = tmp;
  tmp = y;
  return 0.0;
}

double gFunction(double x, double y)
{
  return -2 * ((x * x) + (y * y));
}

double realFunction(double x, double y)
{
  return (1 - (x * x)) * (1 + (y * y));
}
