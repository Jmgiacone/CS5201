#include <fstream>
#include "SymmetricDenseMatrix.h"
#include "DenseMatrix.h"
#include "DiagonalMatrix.h"
#include "UpperTriangularMatrix.h"
#include "LowerTriangularMatrix.h"
#include "QRDecomposition.h"
#include "TriDiagonalMatrix.h"

using std::ifstream;
using std::cout;
using std::endl;
const int MAX_ITERATIONS = 1000000, NUM_MATRICES = 2;
const double ERROR_TOLERANCE = .000000001;
void getEigenValues(const DenseMatrix<double>& matrix, int matrixNumber);
void matrixShowcase();
Vector<double> getDiagonal(AbstractMatrix<double>& matrix);

int main(int argc, char* argv[])
{
  int dimensions;
  ifstream fileIn;
  DenseMatrix<double> input;

  if(argc != 2)
  {
    cout << "Error: Command-Line argument must be the filename" << endl;
    return 1;
  }
  matrixShowcase();

  fileIn.open(argv[1]);

  //Does the file exist?
  if(fileIn)
  {
    for(int i = 0; i < NUM_MATRICES; i++)
    {
      fileIn >> dimensions;

      input = DenseMatrix<double>(dimensions, dimensions);

      //Read in the matrix
      for (int i = 0; i < dimensions; i++)
      {
        for (int j = 0; j < dimensions; j++)
        {
          fileIn >> input[i][j];
        }
      }

      getEigenValues(input, i + 1);
    }
    cout << "===" << endl;
    fileIn.close();
  }
  else
  {
    cout << "Error: File " << argv[1] << " does not exist. Please try again";
    return 1;
  }

  return 0;
}

Vector<double> getDiagonal(AbstractMatrix<double>& matrix)
{
  Vector<double> diagonal(matrix.numRows());

  for(int i = 0; i < diagonal.numTerms(); i++)
  {
    diagonal[i] = matrix(i, i);
  }

  return diagonal;
}

void getEigenValues(const DenseMatrix<double>& matrix, int matrixNumber)
{
  QRDecomposition<double> qrDecomposition;
  TwoNorm<double> twoNorm;
  DenseMatrix<double> q, rq = matrix;
  UpperTriangularMatrix<double> r;
  Vector<double> currentDiagonal, previousDiagonal;
  double absoluteError = 100;
  int iterations = 1;

  //Do at least one iteration
  do
  {
    //Decompose: Ak = QkRk
    qrDecomposition(rq);
    q = qrDecomposition.getQ();
    r = qrDecomposition.getR();

    //Ak+1 = RkQk
    rq = r * q;
    currentDiagonal = getDiagonal(rq);

    //Second time and forward, calculate absolute error
    if(iterations != 1)
    {
      //Absolute Error: TwoNorm(current) - TwoNorm(previous)
      absoluteError = twoNorm(currentDiagonal - previousDiagonal);

      if(iterations == 5 || iterations == 10)
      {
        cout << "=== Iteration " << iterations << " - Matrix "<< matrixNumber << " ===" << endl;
        cout << rq << endl;
      }
    }
    previousDiagonal = currentDiagonal;
    iterations++;
  }
  while(iterations < MAX_ITERATIONS && absoluteError >= ERROR_TOLERANCE);

  //We're done. What are our results?
  cout << "=== Final iteration - Matrix " << matrixNumber << " ===" << endl;
  cout << rq << endl;
  cout << "=== Reason - Matrix " << matrixNumber << " ===" << endl;

  if(iterations == MAX_ITERATIONS)
  {
    cout << "Hit the maximum number of iterations" << endl;
  }
  else
  {
    cout << "Absolute error of " << std::setprecision(10) << absoluteError << " dropped below the threshold of "
    << ERROR_TOLERANCE << endl;
  }

  cout << "=== Eigenvalues - Matrix " << std::setprecision(5) << matrixNumber << " ===" << endl;
  cout << currentDiagonal << endl;
}

void matrixShowcase()
{
  TriDiagonalMatrix<double> tdm1(4,4), tdm2(4,4);
  UpperTriangularMatrix<double> utm1(4), utm2(4);
  DiagonalMatrix<double> dm1(4), dm2(4);

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      if(!( i > j + 1 || j > i + 1))
      {
        tdm1(i, j) = i+4;
        tdm2(i, j) = 2*i + 4;
      }
    }
  }
  cout << "TriDiagonal Multiplication" << endl;
  
  
  cout << "Matrix 1" << endl;
  cout << tdm1 << endl;
  cout << "Matrix 2" << endl;
  cout << tdm2 << endl;
  cout << "M1 * M2" << endl;
  cout << tdm1 * tdm2 << endl << endl;

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      if(j >= i)
      {
        utm1(i, j) = i+4;
        utm2(i, j) = 2*i + 4;
      }
    }
  }

  cout << "UpperTriangular Multiplication" << endl;
  

  cout << "Matrix 1" << endl;
  cout << utm1 << endl;
  cout << "Matrix 2" << endl;
  cout << utm2 << endl;
  cout << "M1 * M2" << endl;
  cout << utm1 * utm2 << endl << endl;

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      if(i == j)
      {
        dm1(i, j) = i+4;
        dm2(i, j) = 2*i + 4;
      }
    }
  }

  cout << "Diagonal Multiplication" << endl;

  cout << "Matrix 1" << endl;
  cout << dm1 << endl;
  cout << "Matrix 2" << endl;
  cout << dm2 << endl;
  cout << "M1 * M2" << endl;
  cout << dm1 * dm2 << endl << endl;
}