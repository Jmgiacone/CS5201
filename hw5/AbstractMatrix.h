//
// Created by Jordan on 4/7/2016.
//

#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H
#include <iostream>
#include "Vector.h"
template <class T>
class AbstractMatrix
{
  public:
    virtual std::ostream& output(std::ostream& out) const = 0;
    friend std::ostream& operator<< (std::ostream& out, const AbstractMatrix<T>& rhs) {return rhs.output(out);}
    virtual int numRows() const = 0;
    virtual int numColumns() const = 0;
    virtual ~AbstractMatrix() {}
};
#endif
