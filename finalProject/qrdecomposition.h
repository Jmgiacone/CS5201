/**
 *  @file qrdecomposition.h
 *  @author Jordan Giacone, Shae Bolt, CS5201 Section A
 *  @date Apr 22, 2016
 *  @brief Description: This is the header for the QRDecomposition class,
 *  which contains functionality for QR Decomposition
 *  @details Details:
 */



#ifndef QRDECOMPOSITION_H
#define QRDECOMPOSITION_H

#include "abstractmatrix.h"
#include "genericmatrix.h"
#include "triangularmatrix.h"
#include "genericmatrix.h"
#include "twonorm.h"
template <class T>
class QRDecomposition
{
  public:
    /**
     * Purpose: Default Constructor
     * Pre: None
     * Param: None
     * Post: The object is initialized to a DenseMatrix of DEFAULT_ROWS x DEFAULT_COLUMNS
     * Return: None
     */
    QRDecomposition();

    /*
     * Purpose: Operator() - Do the decomposition
     * Pre: None
     * Param: aMatrix - The Matrix to be QR decomposed
     * Post: If there is a division by zero, a domain_error exception will be thrown
     *       q and r are set equal to the Q and R respectively
     * Return: None
     */
    void operator()(const AbstractMatrix<T>& aMatrix);

    /*
     * Purpose: Get Q matrix
     * Pre: operator() has been run
     * Param: None
     * Post: None
     * Return: Q matrix
     */
    GenericMatrix<T> getQ() {return q;}

    /*
     * Purpose: Get R matrix
     * Pre: operator() has been run
     * Param: None
     * Post: None
     * Return: R matrix
     */
    TriangularMatrix<T> getR() {return r;}
  private:
    GenericMatrix<T> q;
    TriangularMatrix<T> r;
};
#include "qrdecomposition.hpp"
#endif
