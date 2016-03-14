/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 4
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 3/14/16
 * Filename: driver.cpp
 * Description: driver file for homework4
 */

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
  double answer;
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

      try
      {
        cout << "Vandermonde Matrix A" << endl;
        cout << m << endl;
        cout << "\nResultant Vector b" << endl;
        cout << v << endl;
        cout << "\nAugmented Vandermonde Matrix" << endl;
        cout << augmented << endl;
        cout << "\nGaussian Elimination without pivoting" << endl;
        noPivoting = elim(m, v, false);
        cout << noPivoting << endl;
        cout << "\nGaussian Elimination with pivoting" << endl;
        pivoting = elim(m, v, true);
        cout << pivoting << endl;
        cout << "\nAugmented Gaussian Elimination without pivoting" << endl;
        cout << elim(augmented, false) << endl;
        cout << "\nAugmented Gaussian Elimination with pivoting" << endl;
        cout << elim(augmented, true) << endl;
        cout << "\nM" << endl;
        cout << m << endl;
        cout << "\nM Transpose" << endl;
        cout << transpose(m) << endl;
        cout << "\nM * M Transpose" << endl;
        cout << "########################################" << endl;
        cout << m * transpose(m) << endl;
        cout << "########################################" << endl;
      }
      catch(std::domain_error d)
      {
        cerr << "Caught domain_error exception. What()->" << d.what() << endl;
        return 1;
      }
      catch(std::invalid_argument i)
      {
        cerr << "Caught invalid_argument exception. What()->" << i.what() << endl;
        return 1;
      }
      catch(std::length_error l)
      {
        cerr << "Caught length_error exception. What()->" << l.what() << endl;
        return 1;
      }
      catch(std::out_of_range o)
      {
        cerr << "Caught out_of_range exception. What()->" << o.what() << endl;
        return 1;
      }

      cout << "\nFinal Equation:" << endl;
      cout << "f(x) = ";
      for(int i = 0; i < pivoting.numTerms(); i++)
      {
        cout << std::setprecision(5)<< pivoting[i] << "x^" << i;

        if(i < pivoting.numTerms()-1)
        {
          cout << " + ";
        }
      }
      cout << endl;
      cout << "\nChecking our answers" << endl;

      for(int i = 0; i < t; i++)
      {
        answer = 0;
        cout << "Equation " << i+1 << endl;
        for(int j = 0; j < t; j++)
        {
          answer += pivoting[j] * pow(m[i][1], j);
          cout << std::setprecision(10)<< pivoting[j] << "*(" << m[i][1] << ")^" << j;
          
          if(j < t-1)
          {
            cout << " + " << endl;
          } 
          else
          {
            cout << endl << " = ";
          }
        }
        cout << answer << "(Expected: " << v[i] << ")" << endl;
        cout << endl;
      }
    }
    else
    {
      cerr << "Error: File " << fileName << " does not exist." << endl;
      return 1;
    }
  }
  else
  {
    cerr << "Error: Invalid number of parameters provided. Please provide a single parameter" << endl;
    return 1;
  }
  return 0;
}
