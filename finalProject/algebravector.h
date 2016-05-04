/**
 *  @file algebravector.h
 *  @author shae, CS5201 Section A
 *  @date Feb 23, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef ALGEBRAVECTOR_H_
#define ALGEBRAVECTOR_H_

#include <cmath>
#include <stdexcept>
#include "abstractvector.h"

#define NEAR_ZERO 0.0000000001f

template<typename T>
class AlgebraVector;

template<typename T>
T twoNorm(const AlgebraVector<T>& vector);

template<typename T>
void swap(AlgebraVector<T>& lhs, AlgebraVector<T>& rhs);

///@brief a type of vector for striaght arithmetic
template<typename T>
class AlgebraVector: public virtual AbstractVector<T>
{
  protected:
    //array for data storage for vector
    DynamicArray<T> m_dynamic_array;

    virtual std::ostream& print(std::ostream& os) const;
    virtual std::istream& readin(std::istream& is);
    /// @brief performs a dot product on the lhs and rhs
    /// @pre T = T is defined
    /// T += T is defined
    /// T * T is defined
    /// T default construction is defined
    /// @post returns the dot product of lhs and rhs
    virtual T vectorMultiply(const AbstractVector<T>& rhs) const;
  public:
    /// @brief default initializes values
    /// @pre none
    /// @post none
    AlgebraVector()
    {
    }

    /// @brief parameterized constructor
    /// @pre T = T defined
    /// @post the calling objects m_dynamic_array is set to dyanmic_array
    AlgebraVector(const DynamicArray<T>& dynamic_array) :
        m_dynamic_array(dynamic_array)
    {
    }

    /// @brief copy constructor
    /// @pre T = T defined
    /// @post calling objects member variables deep copied from vector
    AlgebraVector(const AlgebraVector<T> & vector) :
        m_dynamic_array(vector.m_dynamic_array)
    {
    }
    /// @brief move constructor
    /// @pre T = T defined
    /// @post calling objects member variables shallow swapped from vectorS
    AlgebraVector(AlgebraVector<T> && vector) :
        m_dynamic_array(std::move(vector.m_dynamic_array))
    {
    }

    /// @brief single item constructor
    /// @pre T = T defined
    /// @post calling objects m_dynamic_array initialized with item
    AlgebraVector(T& item) :
        m_dynamic_array(item)
    {
    }

    /// @brief m_dynamic_array is initialized with size = size and values = value
    /// @pre T = T defined
    /// @post calling objects m_dynamic_array is set to size = size and all values = value
    AlgebraVector(const size_t size, const T& value) :
        m_dynamic_array(size, value)
    {
    }

    /// @brief copy constructor
    /// @pre T = T defined
    /// @post calling objects member variables deep copied from vector
    AlgebraVector(const AbstractVector<T>& rhs);

    /// @brief assignment operator, calling object set to rhs
    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const AlgebraVector<T>& operator =(const AbstractVector<T>& rhs);
    /// @brief assignment operator, calling object set to rhs
    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const AlgebraVector<T>& operator =(const AlgebraVector<T>& rhs);
    /// @brief move assignment operator, calling object set to rhs
    /// @pre T = T defined
    /// @post calling objects member variables are set to rhs's and a
    /// reference to the calling object is returned
    const AlgebraVector<T>& operator =(AlgebraVector<T> && rhs);

    /// @brief performs assignment addition of the calling object and rhs
    /// @pre T = T is defined
    /// T += T is defined
    /// @post adds rhs from *this and returns the reference to the current object
    virtual const AbstractVector<T>& operator +=(const AbstractVector<T>& rhs);

    /// @brief assignment subtraction of the calling object and rhs
    /// @pre T = T is defined
    /// T -= T is definfed
    /// @post subtracts rhs from *this and returns the reference to the current object
    virtual const AbstractVector<T>& operator -=(const AbstractVector<T>& rhs);
    /// @brief performs assignment scalar multiplication with rhs
    /// @pre T = T is defined
    /// T *= T is defined
    /// @post multiplies rhs to *this and returns the reference to the current object
    virtual const AbstractVector<T>& operator *=(const T& rhs);

    /// @brief performs assignment scalar division on the calling object
    /// @pre T = T is defined
    /// T /= T is defined
    /// @post multiplies rhs to *this and returns the reference to the current object
    virtual const AbstractVector<T>& operator /=(const T& rhs);
    /// @brief indexes into m_dynamic_array
    /// @pre index < m_dynamic_array.size()
    /// @post if index is not out of bounds, the corresponding constant
    /// reference at the index is returned from the array.
    virtual T& operator [](const size_t index);
    /// @brief indexes into m_dynamic_array
    /// @pre index < m_dynamic_array.size()
    /// @post if index is not out of bounds, the corresponding constant
    /// reference at the index is returned from the array.
    virtual const T& operator [](const size_t index) const;
    /// @brief retrieves the size of the calling objects internal array
    /// @pre none
    /// @post m_dynamic_array.size() returned
    virtual size_t size() const;

    /// @brief swaps the elements from first and second
    /// @pre array swapping for T is defined
    /// @post all elements first is now the same as the initial state of second
    /// and second is the same as the initial state of first
    friend void swap<T>(AlgebraVector<T>& lhs, AlgebraVector<T>& rhs);
    /// @brief calculates the two norm of the given vector
    /// @pre T = T is defined
    /// T * T is defined
    /// T += T is defined
    /// T default construction is defined
    /// sqrt(T) is defined
    /// @post returns the two norm of the given vector
    friend T twoNorm<T>(const AlgebraVector<T>& vector);

    virtual ~AlgebraVector()
    {
    }
    ;
};

/// @brief performs a scalar multiplication on lhs
/// @pre T = T is defined
/// T *= T is defined
/// @post returns the scalar multiplication of lhs and rhs
template<typename T>
AlgebraVector<T> operator *(const AlgebraVector<T>& rhs, const T& lhs);

/// @brief performs a scalar multiplication on rhs
/// @pre T = T is defined
/// T *= T is defined
/// @post returns the scalar multiplication of lhs and rhs
template<typename T>
AlgebraVector<T> operator *(const T& lhs, const AlgebraVector<T>& rhs);

/// @brief performs a scalar multiplication on rhs
/// @pre T = T is defined
/// T /= T is defined
/// @post returns the scalar multiplication of lhs and rhs
template<typename T>
AlgebraVector<T> operator /(const AlgebraVector<T>& lhs, const T& rhs);

/// @brief performs addition of lhs and rhs
/// @pre T = T is defined
/// T += T is defined
/// @post returns the addition of lhs vector and rhs vector
template<typename T>
AlgebraVector<T> operator +(const AlgebraVector<T>& lhs,
    const AbstractVector<T>& rhs);

/// @brief binary - operator, subtracts lhs and rhs
/// @pre T = T is defined
/// T -= T is defined
/// @post the result of the subtraction of rhs and lhs is returned
template<typename T>
AlgebraVector<T> operator -(const AlgebraVector<T>& lhs,
    const AbstractVector<T>& rhs);

#include "algebravector.hpp"

#endif /* ALGEBRAVECTOR_H_ */
