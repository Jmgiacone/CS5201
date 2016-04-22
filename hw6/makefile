# Programmer: Jordan Giacone
# Class: CS5201 Section A
# Instructor: Clayton Price
# Homework 6
# Student ID: 12400927
# Login: Jmgv27
# Date: 4/22/16
# Filename: makefile
# Description: This is the makefile for homework 6

CXX = /usr/bin/g++
FLAGS = -std=c++11 -g -W -Wall -pedantic-errors

OBJECTS = driver.o

.SUFFIXES: .cpp
.cpp.o: $<
	${CXX} -c ${FLAGS} $< -o $@

default: all
all: driver

driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

driver.o: driver.cpp SymmetricDenseMatrix.h AbstractMatrix.h Vector.h \
 Vector.hpp AbstractMatrix.hpp SymmetricDenseMatrix.hpp DenseMatrix.h \
 DenseMatrix.hpp DiagonalMatrix.h DiagonalMatrix.hpp \
 UpperTriangularMatrix.h UpperTriangularMatrix.hpp \
 LowerTriangularMatrix.h LowerTriangularMatrix.hpp QRDecomposition.h \
 QRDecomposition.hpp TwoNorm.h TwoNorm.hpp TriDiagonalMatrix.h \
 TriDiagonalMatrix.hpp
