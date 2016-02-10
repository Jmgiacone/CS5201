#ifndef INFINITYNORM_H
#define INFINITYNORM_H
template<class T>
class InfinityNorm
{
  public:
    const T operator() (const std::vector<Polynomial<T>>& vect) const;
};
#include "InfinityNorm.hpp"
#endif
