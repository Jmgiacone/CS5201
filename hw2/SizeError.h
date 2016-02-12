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
