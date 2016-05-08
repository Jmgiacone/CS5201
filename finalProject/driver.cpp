/**
 *  @file driver.cpp
 *  @author Jordan Giacone, Shae Bolt , CS5201 Section A
 *  @date May 5, 2016
 *  @brief Description: driver that tests PDE solving techniques.
 *  @details Details:
 */


#include <iostream>
#include <cstdlib>
#include <chrono>
#include "laplacebvector.h"
#include "laplacematrix.h"
#include "qrdecomposition.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setfill;
using std::left;
using std::right;
using std::abs;
using std::pow;
using std::atoi;
#define line_width 15
#define number_max 20
#define default_precision 20

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
  os << setw(width) << fixed << setprecision(precision) << left;
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
void solveLaplaceEquation(const size_t n, bool verbose);
int main(int argc, char* argv[])
{
  size_t n;

  switch(argc - 1)
  {
    case 0:
      n = 4;
      break;
    case 1:
      n = static_cast<size_t>(atoi(argv[1]));
      break;
    default:
      cout << "Error: Invalid parameters given. Usage: " << argv[0] << " n" << endl;
      exit(1);
  }

  solveLaplaceEquation(n, true);

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

void solveLaplaceEquation(const size_t n, bool verbose)
{
  cout << "Input Size: " << n;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<double> qrTime, gaussTime;

  start = std::chrono::system_clock::now();
  AlgebraVector<double> laplace_result_QRDEC = laplaceMatrixSolver<topFunction,
          bottomFunction, leftFunction, rightFunction, gFunction, double>(n, true);
  end = std::chrono::system_clock::now();
  qrTime = end - start;

  start = std::chrono::system_clock::now();
  AlgebraVector<double> laplace_result_GAUSS = laplaceMatrixSolver<topFunction,
          bottomFunction, leftFunction, rightFunction, gFunction, double>(n, false);
  end = std::chrono::system_clock::now();
  gaussTime = end - start;

  std::ios oldState(nullptr);
  oldState.copyfmt(std::cout);

  const double h = 1 / static_cast<double>(n);
  int i = 0;
  print_seperator(" Laplace comparison for Gaussian Elimination ");
  cout << "Time Duration: " << gaussTime.count() << " sec" << endl;
  double totalError = 0;
  for(size_t y = 1; y < n; y++)
  {
    for(size_t x = 1; x < n; x++)
    {
      double real_val = realFunction(x*h, y*h);
      double laplace_val = laplace_result_GAUSS[i];
      double a_err = relative_error(real_val, laplace_val);

      if(verbose)
      {
        std::cout.copyfmt(oldState);
        print_formatter(cout, 4, 4);
        cout << "Point (" << x * h << ", " << y * h << "): Real Value = ";
        print_formatter(cout);
        cout << real_val << " Approximation = " << laplace_val << " Relative Error = " << a_err << endl;
      }
      totalError += a_err;
      i++;
    }
  }
  cout << "Average Error: " << totalError / pow(n-1, 2);
  totalError = 0;
  i = 0;
  cout << endl;
  print_seperator(" Laplace comparison for QR Decomposition ");
  cout << "Elapsed Time: " << qrTime.count() << " sec" << endl;
  for(size_t y = 1; y < n; y++)
  {
    for(size_t x = 1; x < n; x++)
    {
      double real_val = realFunction(x*h, y*h);
      double laplace_val = laplace_result_QRDEC[i];
      double a_err = absolute_error(real_val, laplace_val);

      if(verbose)
      {
        std::cout.copyfmt(oldState);
        print_formatter(cout, 4, 4);
        cout << setw(4) << "Point (" << x * h << ", " << y * h << "): Real Value = ";
        print_formatter(cout);
        cout << real_val << " Approximation = " << laplace_val << " Relative Error = " << a_err << endl;
      }
      totalError += a_err;
      i++;
    }
  }
  cout << "Average Error: " << totalError / pow(n-1, 2) << "\n" << endl;
}
