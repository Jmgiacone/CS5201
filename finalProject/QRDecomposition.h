/**
 * Programmer: Jordan Giacone
 * Class: CS5201 Section A
 * Instructor: Clayton Price
 * Homework 6
 * Student ID: 12400927
 * Login: Jmgv27
 * Date: 4/22/16
 * Filename: QRDecomposition
 * Description: This is the header for the QRDecomposition class
 */
#ifndef QRDECOMPOSITION_H
#define QRDECOMPOSITION_H

#include "abstractmatrix.h"
#include "genericmatrix.h"
#include "triangularmatrix.h"
#include "genericmatrix.h"
#include "TwoNorm.h"
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
#include "QRDecomposition.hpp"
#endif
