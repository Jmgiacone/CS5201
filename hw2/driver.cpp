#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Polynomial.h"
#include "InfinityNorm.h"

void readPoly(std::ifstream& fileIn, Polynomial<float>& poly, int totalTerms);

int main(int argc, char *argv[])
{
  int totalPolynomials, foundPolynomials = 0, numTerms;
  std::string filename, tmp;
  std::vector<Polynomial<float>> vect;
  InfinityNorm<float> norm;

  if(argc == 2)
  {
    filename = argv[1];
    std::ifstream fileIn(filename);
    std::cout << "Attempting to open file " << filename << std::endl;    
 
    //File Exists
    if(fileIn)
    {
      std::cout << "File opened successfully" << std::endl;
      try
      {
        fileIn >> tmp;
        totalPolynomials = std::stoi(tmp);
      }
      catch(std::invalid_argument)
      {
        std::cerr << "Error: Token Mismatch! Token " << tmp << " is not a valid integer type. Terminating" << std::endl;
        exit(0);
      }

      //std::cout << "Displaying " << totalPolynomials << " Polynomials" << std::endl;
      for(int i = 0; (fileIn >> tmp) && i < totalPolynomials; i++)
      {
        try
        {
          numTerms = std::stoi(tmp);
        }
        catch(std::invalid_argument)
        {
          std::cerr << "Error: Term token Mismatch! Token " << tmp << " is not a valid integer type. Terminating" << std::endl;
        }  

        Polynomial<float> poly;
        readPoly(fileIn, poly, numTerms);

        foundPolynomials++;
        
        //std::cout << (i + 1) << ") " << poly << std::endl;
        vect.push_back(poly);
      }
    
      if(foundPolynomials != totalPolynomials)
      {
        std::cerr << "Error: Polynomial Mismatch! Expected " << totalPolynomials << " Polynomials, but only encountered " << foundPolynomials << std::endl;
        exit(0);
      }

      std::cout << "Read " << vect.size() << " Polynomials successfully" << std::endl;
      std::cout << "\nRESULTS\n-------------------------------------------" << std::endl;

      std::cout << "Performing p1 += p2" << std::endl;

      vect[0] += vect[1];
      std::cout << "Now, p1 = " << vect[0] << std::endl;
      std::cout << "-p1 = " << (-vect[0]) << std::endl;
      std::cout << "p1(-1) = " << (vect[0](-1)) << std::endl;
      std::cout << "4*p3 = " << (4 * vect[2]) << std::endl;
      std::cout << "~p4(2) = " << ((~vect[3])(2)) << std::endl;
      std::cout << "The infinity norm for this set of " << vect.size() << " Polynomials is: " << norm(vect) << std::endl;
    }
    else
    {
      std::cerr << "Error: File " << filename << " does not exist. Please re-run with a valid filename." << std::endl;
    }
  }
  return 0;
}

void readPoly(std::ifstream& fileIn, Polynomial<float>& poly, int totalTerms)
{
  std::string str, tmp;
  float coefficient, exponent;
  int foundTerms = 0;;

  std::getline(fileIn, str, '\n');
  std::istringstream iss(str);

  while(iss >> tmp)
  {
    try
    {
      coefficient = std::stof(tmp);
      iss >> tmp;
      exponent = std::stof(tmp);
    }
    catch(std::invalid_argument)
    {
      std::cerr << "Error: Token Mismatch! Token " << tmp << " is not a valid numeric type. Terminating" << std::endl;
      exit(0);
    }
  
    foundTerms++;
    Polynomial<float> p(coefficient, exponent);
    poly += p;
  }
  
  //Term Mismatch
  if(foundTerms != totalTerms)
  {
    std::cerr << "Error: Term Mismatch! Expected " << totalTerms << " terms, but only encountered " << foundTerms << std::endl;
    exit(0);
  }
}
