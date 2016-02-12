#ifndef INFINITYNORM_H
#define INFINITYNORM_H
template<class T>
class InfinityNorm
{
  public:
    /**
     * Purpose: To find the Infinity Norm given a vector of Polynomials
                The Infinity Norm is defined as the maximum of the 
                magnitudes of the given Polynomials
     * Pre: Template type T must have the '=' operator defined
            Template type T must have the '*' operator defined
            Template type T must have the '+=' operator defined
            Template type T must be compatible with function sqrt()
     * Post: None
     * Return: The Infinity Norm of the given vector
     */
    const T operator() (const std::vector<Polynomial<T>>& vect) const;
};
#include "InfinityNorm.hpp"
#endif
