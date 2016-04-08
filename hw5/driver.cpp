/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 5
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/8/16
 * Filename: driver.cpp
 * Description: This is the driver file for homework 5
 */

#include <fstream>
#include "TriDiagonalMatrix.h"
#include "GaussianElimination.h"

using std::cout;
using std::endl;
using std::ifstream;

double getH(int i, const Vector<double>& v);
double trueFunction(const double x);
double relativeError(const double trueValue, const double approx);
double absoluteError(const double trueValue, const double approx);

const double TEST_VALUES[] = {-2, -.9, -.7, .1};
int main(int argc, char* argv[])
{
  ifstream fileIn;
  int numDataPoints;
  Matrix<double> vandermonde;
  Vector<double> xVals, yVals, vandermondeAnswer;

  //One CLI argument
  if(argc == 2)
  {
    fileIn.open(argv[1]);

    //Does the file exist?
    if(fileIn)
    {
      try
      {
        fileIn >> numDataPoints;

        xVals = Vector<double>(numDataPoints);
        yVals = Vector<double>(numDataPoints);
        vandermonde = Matrix<double>(numDataPoints, numDataPoints);

        //Read in X and Y
        for (int i = 0; i < numDataPoints; i++)
        {
          fileIn >> xVals[i];
          for(int j = 0; j < vandermonde.numColumns(); j++)
          {
            vandermonde[i][j] = std::pow(xVals[i], j);
          }
          fileIn >> yVals[i];
        }

        cout << "Read in datapoints. Generating diagonals" << endl;
        Vector<double> diag1(numDataPoints - 1), diag2(numDataPoints), diag3(numDataPoints - 1);

        for (int i = 0; i < diag1.numTerms() - 1; i++)
        {
          diag1[i] = getH(i, xVals);
        }

        diag1[diag1.numTerms() - 1] = 0;

        diag2[0] = 1;

        for (int i = 1; i < diag2.numTerms() - 1; i++)
        {
          diag2[i] = 2 * (getH(i - 1, xVals) + getH(i, xVals));
        }

        diag2[diag2.numTerms() - 1] = 1;

        diag3[0] = 0;

        for (int i = 1; i < diag3.numTerms(); i++)
        {
          diag3[i] = getH(i, xVals);
        }

        TriDiagonalMatrix<double> aMatrix(numDataPoints, numDataPoints, diag1, diag2, diag3);

        cout << endl << "Diagonals Generated: Spline Matrix: " << endl;
        cout << aMatrix << endl << endl;

        cout << "Generating answer Vector" << endl;

        Vector<double> bVector(aMatrix.numRows());

        bVector[0] = 0;

        for (int i = 1; i < bVector.numTerms() - 1; i++)
        {
          bVector[i] = (3 * (yVals[i + 1] - yVals[i])) / getH(i, xVals);
          bVector[i] -= (3 * (yVals[i] - yVals[i - 1])) / getH(i - 1, xVals);
        }

        bVector[bVector.numTerms() - 1] = 0;

        cout << bVector << endl;

        cout << "Trying Gaussian Elimination..." << endl;
        GaussianElimination<double> elim;

        Vector<double> cVector = elim(aMatrix, bVector);
        vandermondeAnswer = elim(vandermonde, yVals, true);
        cout << "Results: " << cVector << endl << endl;

        cout << "Displaying Splines:" << endl;
        Vector<double> bCoefficientVector(cVector.numTerms()), dVector(cVector.numTerms());

        for(int i = 0; i < dVector.numTerms() - 1; i++)
        {
          dVector[i] = getH(i, cVector) / (3 * getH(i, xVals));
          bCoefficientVector[i] = (getH(i, yVals)/getH(i, xVals)) - (getH(i, xVals)/3)*(2*cVector[i] + cVector[i+1]);
        }

        for(int i = 0; i < cVector.numTerms(); i++)
        {
          cout << "Spline " << i << endl;

          cout << yVals[i] << " + " << bCoefficientVector[i] << "(x - " << xVals[i] << ") + " << cVector[i]
               << "(x - " << xVals[i] <<")^2 + " << dVector[i] << "(x - " <<  xVals[i] << ")^3" << endl << endl;
        }

        cout << endl << "Testing test data" << endl;
        int chosenSpline = xVals.numTerms() - 1;
        for(int i = 0; i < 4; i++)
        {
          cout << "=== Input of: " << TEST_VALUES[i] << " ===" << endl;
          for(int j = 0; j < xVals.numTerms(); j++)
          {
            if(TEST_VALUES[i] <= xVals[i])
            {
              chosenSpline = i;
              break;
            }
          }

          double result = yVals[chosenSpline] + bCoefficientVector[chosenSpline] * (TEST_VALUES[i] - xVals[i]) +
                                                cVector[i]* std::pow(TEST_VALUES[i] - xVals[i], 2) +
                                                dVector[i] * std::pow(TEST_VALUES[i] - xVals[i], 3);
          double vandermondeResult = 0;
          for(int j = 0; j < vandermondeAnswer.numTerms(); j++)
          {
            vandermondeResult += vandermondeAnswer[j] * std::pow(TEST_VALUES[i], j);
          }

          cout << "== Relative Error: " << endl;
          cout << "Vandermonde: " << relativeError(trueFunction(TEST_VALUES[i]), vandermondeResult) << endl;
          cout << "Spline     : " << relativeError(trueFunction(TEST_VALUES[i]), result) << endl << endl;
          cout << "== Absolute Error: " << endl;
          cout << "Vandermonde: " << absoluteError(trueFunction(TEST_VALUES[i]), vandermondeResult) << endl;
          cout << "Spline     : " << absoluteError(trueFunction(TEST_VALUES[i]), result) << endl << endl;
        }
      }
      catch (std::out_of_range e)
      {
        cout << "Out of Range" << endl;
        cout << e.what();
        exit(-1);
      }
      catch (std::invalid_argument e)
      {
        cout << "Invalid Argument" << endl;
        exit(-1);
      }
    }
    else
    {
      cout << "Error: filename " << argv[1] << " is invalid. Please try again";
      exit(-1);
    }
  }
  else
  {
    cout << "Error: Invalid CLI arguments provided. Please only provide the filename of the data";
    exit(-1);
  }

  cout << "==============================================" << endl;
  return 0;
}

double getH(int i, const Vector<double>& v)
{
  return v[i+1] - v[i];
}

double trueFunction(const double x)
{
  return (1 / (1 + 10*std::pow(x, 2)));
}

double relativeError(const double trueValue, const double approx)
{
  return std::abs(1 - (approx / trueValue));
}

double absoluteError(const double trueValue, const double approx)
{
  return std::abs(trueValue - approx);
}