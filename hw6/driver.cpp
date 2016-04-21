#include <fstream>
#include "SymmetricDenseMatrix.h"
#include "DenseMatrix.h"
#include "DiagonalMatrix.h"
#include "UpperTriangularMatrix.h"
#include "LowerTriangularMatrix.h"
#include "QRDecomposition.h"

using std::ifstream;
using std::cout;
using std::endl;
int main(int argc, char* argv[])
{
  ifstream fileIn;
  QRDecomposition<double> qrDecomposition;
  std::vector<AbstractMatrix<double>*> qr;
  int dimensions;

  if(argc != 2)
  {
    cout << "Error: Command-Line argument must be the filename" << endl;
    return 1;
  }

  fileIn.open(argv[1]);

  //Does the file exist?
  if(fileIn)
  {
    fileIn >> dimensions;

    DenseMatrix<double> input(dimensions, dimensions);

    for(int i = 0; i < dimensions; i++)
    {
      for(int j = 0; j < dimensions; j++)
      {
        fileIn >> input[i][j];
      }
    }

    cout << input << endl;
    UpperTriangularMatrix<double> r;
    qr = qrDecomposition(input);
    AbstractMatrix<double>* q = qr[0];
    cout << *q << endl;
  }
  else
  {
    cout << "Error: File " << argv[1] << " does not exist. Please try again";
    return 1;
  }

  return 0;
}