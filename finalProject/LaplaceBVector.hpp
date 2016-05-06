#include <iostream>
using std::cout;
using std::endl;

template <double topFunction(double x, double y),
          double bottomFunction(double x, double y),
          double leftFunction(double x, double y),
          double rightFunction(double x, double y),
          double gFunction(double x, double y),
          class T>
AlgebraVector<T> laplaceBVector(const size_t n)
{
  T tmp;
  size_t matrixDimensions = (n - 1) * (n - 1);
  AlgebraVector<T> answer(matrixDimensions, 0), gVector(matrixDimensions, 0), uVector(matrixDimensions, 0);
  const double h = 1 / static_cast<double>(n);
  int i = 0;
  for(int y = 1; y < n; y++)
  {
    for(int x = 1; x < n; x++)
    {
      //Get the g vector all set
      gVector[i] = gFunction(x*h, y*h);

      //Add in border functions, if any
      cout << "Checking neighbors for (" << x*h << ", " << y*h << ")" << endl;

      try
      {
        tmp = evaluateBorderFunction<topFunction, bottomFunction, leftFunction, rightFunction, T>((x-1)*h, y*h);
        uVector[i] += tmp;
      }
      catch (std::invalid_argument a)
      {
        //Not a border point
        //cout << "Not a border point" << endl;
      }

      try
      {
        tmp = evaluateBorderFunction<topFunction, bottomFunction, leftFunction, rightFunction, T>((x+1)*h, y*h);
        uVector[i] += tmp;
      }
      catch (std::invalid_argument a)
      {
        //Not a border point
        //cout << "Not a border point" << endl;
      }

      try
      {
        tmp = evaluateBorderFunction<topFunction, bottomFunction, leftFunction, rightFunction, T>(x*h, (y-1)*h);
        uVector[i] += tmp;
      }
      catch (std::invalid_argument a)
      {
        //Not a border point
        //cout << "Not a border point" << endl;
      }

      try
      {
        tmp = evaluateBorderFunction<topFunction, bottomFunction, leftFunction, rightFunction, T>(x*h, (y+1)*h);
        uVector[i] += tmp;
      }
      catch (std::invalid_argument a)
      {
        //Not a border point
        //cout << "Not a border point" << endl;
      }
      cout << endl;
      i++;
    }
  }
  answer = ((h*h/4) * gVector) - (.25 * uVector);

  cout << answer << endl;

  return answer;
}

template <double topFunction(double x, double y),
    double bottomFunction(double x, double y),
    double leftFunction(double x, double y),
    double rightFunction(double x, double y),
    class T>
T evaluateBorderFunction(const double x, const double y)
{
  cout << "Checking Point (" << x << ", " << y << ")" << endl;
  T solution = 0;

  if(x == 1)
  {
    return rightFunction(x, y);
  }
  else if(x == 0)
  {
    return leftFunction(x, y);
  }
  else if(y == 1)
  {
    return topFunction(x, y);
  }
  else if(y == 0)
  {
    return bottomFunction(x, y);
  }
  else
  {
    //Argument isn't on the border, continue as normal
    //throw std::invalid_argument("Argument is not on the border");
  }
}

template <double topFunction(double x, double y),
          double bottomFunction(double x, double y),
          double leftFunction(double x, double y),
          double rightFunction(double x, double y),
          double gFunction(double x, double y),
          class T>
AlgebraVector<T> laplaceMatrixSolver(const size_t n, bool pivoting)
{
  AlgebraVector<T> answer(n, 0);

  return answer;
}