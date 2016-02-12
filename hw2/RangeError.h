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
