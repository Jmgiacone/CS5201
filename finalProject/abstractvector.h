/**
 *  @file abstractvector.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 11, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef ABSTRACTVECTOR_H_
#define ABSTRACTVECTOR_H_
#include "dynamicarray.h"
#include  <sstream>

template<typename T>
class AbstractVector;

template<typename T>
void vecArithmeticSizeCheck(const AbstractVector<T>& lhs,
    const AbstractVector<T>& rhs);

template<typename T>
std::ostream& operator <<(std::ostream& os, const AbstractVector<T>& rhs);

template<typename T>
std::istream& operator >>(std::istream& is, AbstractVector<T>& rhs);

template<typename T>
T operator *(const AbstractVector<T>& lhs, const AbstractVector<T>& rhs);

template<typename T>
class AbstractVector
{
  public:
    ///@brief multiplies a vector by value
    ///@pre T *= T defined
    ///@post returns a reference to the calling object and multiplies by rhs
    virtual const AbstractVector<T>& operator *=(const T& rhs) = 0;
    ///@brief divides a vector by value
    ///@pre T /= T defined
    ///@post returns a reference to the calling object and divides by rhs
    virtual const AbstractVector<T>& operator /=(const T& rhs) = 0;
    ///@brief indexes into calling object
    ///@pre
    ///@post returns a reference to the indexed location
    virtual T& operator [](const size_t index) = 0;
    ///@brief indexes into calling object
    ///@pre
    ///@post returns a reference to the indexed location
    virtual const T& operator [](const size_t index) const = 0;
    ///@brief returns the size of the calling object
    ///@pre
    ///@post returns the size of the calling object by value
    virtual size_t size() const = 0;
    virtual ~AbstractVector()
    {
    }
    ;

    ///@brief prints the given object to the terminal
    /// os << T defined
    /// prints rhs to the screen and returns os by reference
    friend std::ostream& operator <<<T>(std::ostream& os,
        const AbstractVector<T>& rhs);
    ///@brief prints the given object to the terminal
    /// os << T defined
    /// prints rhs to the screen and returns is by reference
    friend std::istream& operator >><T>(std::istream& is,
        AbstractVector<T>& rhs);
    ///@brief multiplies by vector
    /// T * T defined T + T defined
    /// multiplies by vector and returns the product by value
    friend T operator *<T>(const AbstractVector<T>& lhs,
        const AbstractVector<T>& rhs);

  protected:
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual std::istream& readin(std::istream& is) = 0;
    virtual T vectorMultiply(const AbstractVector<T>& rhs) const = 0;

};

#include "abstractvector.hpp"

#endif /* ABSTRACTVECTOR_H_ */
