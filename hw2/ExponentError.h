/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 2
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: ExponentError.h
 * Description: This is the header file for the ExponentError class
 */

#ifndef EXPONENT_ERROR_H
#define EXPNOENT_ERROR_H

class ExponentError
{
  private:
    std::string message;
  public:
    ExponentError() {message = "Generic Exponent Error";};
    ExponentError(std::string m) : message(m){};
    
    friend std::ostream& operator<< (std::ostream& out, const ExponentError& rhs)
    {
      out << "Exponent Error: "  << rhs.message;
      return out;
    }
};
#endif

