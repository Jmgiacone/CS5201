#Programmer: Jordan Giacone
#Class: CS5201 Section A
#Instructor: Clayton Price
#Homework 5
#Student ID: 12400927
#Login: Jmgv27
#Date: 4/8/16
#Filename: driver.cpp
#Description: This is the driver file for homework 5

CXX = /usr/bin/g++
FLAGS = -std=c++11 -g -W -Wall -pedantic-errors

OBJECTS = driver.o

.SUFFIXES: .cpp
.cpp.o: $<
	${CXX} -c ${FLAGS} $< -o $@

default: all

all:driver

driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

driver.o: driver.cpp TriDiagonalMatrix.h AbstractMatrix.h Vector.h \
 Vector.hpp Matrix.h Matrix.hpp SmartVector.h SmartVector.hpp \
 TriDiagonalMatrix.hpp GaussianElimination.h GaussianElimination.hpp
