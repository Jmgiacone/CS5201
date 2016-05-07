#include <iostream>
#include "LaplaceBVector.h"
#include "LaplaceMatrix.h"
#include "QRDecomposition.h"
using std::cout;
using std::cin;
using std::endl;

#define line_width 20
#define number_max 14
#define default_precision 10
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


double topFunction(double x, double y);
double bottomFunction(double x, double y);
double leftFunction(double x, double y);
double rightFunction(double x, double y);
double gFunction(double x, double y);

int main()
{
  const size_t x = 3;
  AlgebraVector<double> vect = laplaceBVector<topFunction, bottomFunction, leftFunction, rightFunction, gFunction, double>(x);
  print_formatter(cout);
  cout << vect << endl;
  return 0;
}

double topFunction(double x, double y)
{
  return 2 * bottomFunction(x, y);
}
double bottomFunction(double x, double y)
{
  return 1 - x*x;
}

double leftFunction(double x, double y)
{
  return 1 + y*y;
}

double rightFunction(double x, double y)
{
  return 1.0;
}

double gFunction(double x, double y)
{
  return -2 * ((x * x) + (y * y));
}
