#include <fstream>
#include <iostream>
#include "GaussianElimination.h"
#include "MatrixTranspose.h"

using std::cout;
using std::cerr;
using std::endl;
int main(int argc, char* argv[])
{
  std::ifstream fileIn;
  std::string fileName;
  GaussianElimination<double> elim;
  MatrixTranspose<double> transpose;

  //One CLI argument
  if(argc == 2)
  {
    fileName = argv[1];

    fileIn.open(fileName);

    //File exists?
    if(fileIn)
    {
      int t;
      double x;
      fileIn >> t;

      Matrix<double> m(t, t), augmented(t, t+1);
      Vector<double> v(t), pivoting(t), noPivoting(t);

      //Build the Vandermonde Matrix
      for(int i = 0; i < t; i++)
      {
        fileIn >> x;

        for(int j = 0; j < t; j++)
        {
          m[i][j] = pow(x, j);
          augmented[i][j] = m[i][j];
        }
        fileIn >> v[i];
        augmented[i][t] = v[i];
      }

      fileIn.close();

      cout << "A and b" << endl;
      cout << m << endl;
      cout << v << endl;
      
      cout << "Elim without pivoting" << endl;
      noPivoting = elim(m, v, false);
      cout << noPivoting << endl;
      cout << "Elim with pivoting" << endl;
      pivoting = elim(m, v, true);
      cout << pivoting << endl;
      cout << "Augmented Elim without pivoting" << endl;
      cout << elim(augmented, false) << endl;
      cout << "Augmented Elim with pivoting" << endl;
      cout << elim(augmented, true) << endl << endl;
      cout << "M" << endl;
      cout << m << endl;
      cout << "M Transpose" << endl;
      cout << transpose(m) << endl;
      cout << "M * M Transpose" << endl;
      cout << m * transpose(m) << endl;
      cout << "M Transpose * M" << endl;
      cout << transpose(m) * m << endl;

      cout << "Checking our answers" << endl;

      for(int i = 0; i < t; i++)
      {
        double answer = 0;
        for(int j = 0; j < t; j++)
        {
          answer += pivoting[j] * pow(m[i][1], j);
          cout << std::setprecision(3)<< pivoting[j] << "(" << m[i][1] << ")^" << j;
          
          if(j < t-1)
          {
            cout << " + ";
          } 
          else
          {
            cout << " = ";
          }
        }
        cout << answer << "(" << v[i] << ")" << endl;
      }
    }
    else
    {
      cerr << "Error: File " << fileName << " does not exist.";
      return 0;
    }
  }
  else
  {
    cerr << "Error: Invalid number of parameters provided. Please provide a single parameter" << endl;
    return 0;
  }
  return 0;
}
