#include <iostream>
#include "LaplaceBVector.h"
#include "LaplaceMatrix.h"
#include "QRDecomposition.h"
using std::cout;
using std::cin;
using std::endl;

double topFunction(double x, double y);
double bottomFunction(double x, double y);
double leftFunction(double x, double y);
double rightFunction(double x, double y);
double gFunction(double x, double y);

int main()
{
  const size_t x = 4;
  laplaceBVector<topFunction, bottomFunction, leftFunction, rightFunction, gFunction, double>(x);
  return 0;
}

double topFunction(double x, double y)
{
  return 1.0;
}
double bottomFunction(double x, double y)
{
  return 1.0;
}

double leftFunction(double x, double y)
{
  return 1.0;
}

double rightFunction(double x, double y)
{
  return 1.0;
}

double gFunction(double x, double y)
{
  return 1.0;
}