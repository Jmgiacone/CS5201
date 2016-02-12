/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 2
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 2/11/2016
 * Filename: SizeError.h
 * Description: This is the header file for the SizeError class
 */

#ifndef SIZE_ERROR_H
#define SIZE_ERROR_H
class SizeError
{
  private:
    std::string message;
  public:
    SizeError() {message = "Generic Size Error";};
    SizeError(std::string m) : message(m){};

    friend std::ostream& operator<< (std::ostream& out, const SizeError& rhs)
    {
      out << "Size Error: "  << rhs.message;
      return out;
    }
};
#endif
