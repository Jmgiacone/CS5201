/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 2
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: RangeError.h
 * Description: This is the header file for the RangeError class
 */

#ifndef RANGE_ERROR_H
#define RANGE_ERROR_H

class RangeError
{
  private:
    std::string message;
  public:
    RangeError() {message = "Generic Range Error";};
    RangeError(std::string m) : message(m){};
    
    friend std::ostream& operator<< (std::ostream& out, const RangeError& rhs)
    {
      out << "Range Error: "  << rhs.message;
      return out;
    }
};
#endif
