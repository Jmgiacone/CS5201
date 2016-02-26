# Programmer: Jordan Giacone
# Class: CS5201 Section A
# Instructor: Clayton Price
# Homework 3
# Student ID: 12400927
# Login: Jmgv27
# Date: 2/26/16
# Filename: makefile
# Description: A makefile to build homework 3

CXX = /usr/bin/g++
FLAGS = -std=c++11 -g -w -Wall -pedantic-errors

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

driver.o: driver.cpp QRDecomposition.h QRDecomposition.hpp Vector.h Vector.hpp TwoNorm.h TwoNorm.hpp
