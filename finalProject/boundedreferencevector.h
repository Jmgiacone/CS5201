/**
 *  @file boundedreferencevector.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 3, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef BOUNDEDREFERENCEVECTOR_H_
#define BOUNDEDREFERENCEVECTOR_H_

//#include "abstractmatrix.h"
#include "algebravector.h"

template<typename T>
class BoundedReferenceVector;

template<typename T>
void boundVecBoundCheck(const BoundedReferenceVector<T>& lhs,
    const BoundedReferenceVector<T>& rhs);

///@brief a specialized type of non algebraic vector
/// for intermediate reference passing
template<typename T>
class BoundedReferenceVector: public virtual AbstractVector<T>
{
  protected:
    DynamicArray<T*> t_pointer_references;
    size_t m_ref_size;
    size_t m_bound_lower;
    size_t m_bound_upper;
    T m_zero;
    virtual std::ostream& print(std::ostream& os) const;
    virtual std::istream& readin(std::istream& is);
    virtual T vectorMultiply(const AbstractVector<T>& rhs) const;
  public:
    BoundedReferenceVector() :
        m_ref_size(0), m_bound_lower(0), m_bound_upper(0)
    {
    }
    BoundedReferenceVector(const DynamicArray<T*>& pointer_references,
        const size_t size, const size_t bound_lower, const size_t bound_upper);

    BoundedReferenceVector(const DynamicArray<T*>& pointer_references);

    const BoundedReferenceVector<T>& operator =(
        const BoundedReferenceVector<T>& rhs);

    const BoundedReferenceVector<T>& operator =(
        const BoundedReferenceVector<T> && rhs);

    virtual const BoundedReferenceVector<T>& operator +=(
        const BoundedReferenceVector<T>& rhs);
    virtual const BoundedReferenceVector<T>& operator -=(
        const BoundedReferenceVector<T>& rhs);
    virtual const AbstractVector<T>& operator *=(const T& rhs);
    virtual const AbstractVector<T>& operator /=(const T& rhs);
    virtual T& operator [](const size_t index);
    virtual const T& operator [](const size_t index) const;
    virtual size_t size() const;

    virtual size_t getUpper() const;
    virtual size_t getLower() const;

    virtual ~BoundedReferenceVector();

};

template<typename T>
AlgebraVector<T> operator *(const BoundedReferenceVector<T>& rhs, const T& lhs);

template<typename T>
AlgebraVector<T> operator *(const T& lhs, const BoundedReferenceVector<T>& rhs);

template<typename T>
AlgebraVector<T> operator /(const BoundedReferenceVector<T>& lhs, const T& rhs);

template<typename T>
AlgebraVector<T> operator +(const BoundedReferenceVector<T>& lhs,
    const AbstractVector<T>& rhs);

template<typename T>
AlgebraVector<T> operator -(const BoundedReferenceVector<T>& lhs,
    const AbstractVector<T>& rhs);

#include "boundedreferencevector.hpp"

#endif /* BOUNDEDREFERENCEVECTOR_H_ */
