/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 3
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/26/16
 * Filename: driver.cpp
 * Description: The main driver to calculate QR decomposition
 */

#include <fstream>
#include <iomanip>
#include <vector>
#include "QRDecomposition.h"

/**
 * Purpose: operator<< vector<Vector<double>> insertion operator
 * Pre: Parameter out must be connected to a valid stream
 * Param: out - The ostream to be output to
 *        matrix - The matrix to be output
 * Post: Parameter out will have parameter matrix inserted in to it
 * Return: Parameter out for purposes of chaining << operators
 */
std::ostream& operator<< (std::ostream& out, const std::vector<Vector<double>> matrix);

int main(int argc, char* argv[])
{
  QRDecomposition<double> qrDecomposition;
  std::vector<Vector<double>> a, q, r;
  std::vector<std::vector<Vector<double>>> result;
  std::ifstream fileIn;
  std::string fileName, temp;
  int n;

  //One parameter was provided
  if(argc == 2)
  {
    fileName = argv[1];
    fileIn.open(fileName);

    //Does the file exist?
    if(fileIn)
    {
      try
      {
        fileIn >> temp;
        n = stoi(temp);

        for(int i = 0; i < n; i++)
        {
          Vector<double> v(n);

          fileIn >> v;

          a.push_back(v);
        }

        std::cout << "=== Homework 3 ===" << std::endl;
        std::cout << a[0] + a[1] << std::endl;
        std::cout << "=== v1 + v2 ===" << std::endl;
        std::cout << a[0] - a[1] << std::endl;
        std::cout << "=== v1 - v2 ===" << std::endl;
        std::cout << a[0] * a[2] << std::endl;
        std::cout << "=== v1 * v2 ===" << std::endl;
        std::cout << a[0] << std::endl;
        std::cout << "=== Output stream for v1 ===" << std::endl;
        std::cout << a[0][0] << ", " << a[1][3] << std::endl;
        std::cout << "=== v1[1], v2[4] (Non-zero indexed) ===" << std::endl;

        try
        {
          result = qrDecomposition(a);
        }
        catch(std::domain_error e)
        {
          std::cerr << e.what() << std::endl;
        }

        q = result[0];
        r = result[1];

        //Set specific formatting
        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpos);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(5);

        std::cout << q << std::endl;
        std::cout << "=== Q ===" << std::endl;

        std::cout << r << std::endl;
        std::cout << "=== R ===" << std::endl;

        //Undo specific formatting
        std::cout.unsetf(std::ios::fixed);
        std::cout.unsetf(std::ios::showpos);
        std::cout.unsetf(std::ios::showpoint);

        //Output Q1 * Q1
        for(int i = 0; i < q.size(); i++)
        {
          std::cout << (q[i] * q[i]) << std::endl;
        }
        std::cout << "=== Q[i] * Q[i] ===" << std::endl;
      }
      catch(std::invalid_argument)
      {
        std::cerr << "Error: " << temp << " is not a numeric type" << std::endl;
        exit(-1);
      }
    }
    else
    {
      std::cerr << "Error: File " << fileName << " does not exist. Please re-run with a valid file." << std::endl;
      exit(-1);
    }
  }
  else
  {
    std::cerr << "Error: Invalid number of arguments provided. " <<
                         "Please provide exactly one argument, the filename" << std::endl;
    exit(-1);
  }
}

std::ostream& operator<< (std::ostream& out, const std::vector<Vector<double>> matrix)
{
  int n = matrix[0].numTerms();
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      out << matrix[j][i] << " ";
    }

    if(i < n - 1)
    {
      out << std::endl;
    }
  }
  return out;
}