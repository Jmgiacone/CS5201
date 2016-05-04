/**
 *  @file unrestricteddimmatrix.h
 *  @author shae, CS5201 Section A
 *  @date Apr 18, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef UNRESTRICTEDDIMMATRIX_H_
#define UNRESTRICTEDDIMMATRIX_H_
#include "abstractmatrix.h"

///@brief represents a matrix whos rows and columns are not bound
template<typename T>
class UnrestrictedDimMatrix: public virtual AbstractMatrix<T>
{
  protected:
    size_t m_num_rows;
    size_t m_num_cols;
  public:
    ///@brief default constructor
    ///@pre non
    ///@post construct matrix default
    UnrestrictedDimMatrix() :
        m_num_rows(0), m_num_cols(0)
    {
    }
    ///@brief parameterized constructor
    /// @pre T = T defined
    /// @post constructs matrix rows and cols
    UnrestrictedDimMatrix(const size_t rows, const size_t cols) :
        m_num_rows(rows), m_num_cols(cols)
    {
    }
    ///@brief copy constructor
    /// @pre T = T defined
    /// @post constructs matrix rows and cols
    UnrestrictedDimMatrix(const UnrestrictedDimMatrix<T>& udm) :
        m_num_rows(udm.rows()), m_num_cols(udm.columns())
    {
    }
    ///@brief returns number of rows
    /// @pre
    /// @post returns number of rows by value
    virtual size_t rows() const;
    ///@brief returns number of cols
    /// @pre
    /// @post returns number of cols by value
    virtual size_t columns() const;

    virtual ~UnrestrictedDimMatrix()
    {
    }
    ;

};

#include "unrestricteddimmatrix.hpp"

#endif /* UNRESTRICTEDDIMMATRIX_H_ */
