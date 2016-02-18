# Programmer: Jordan Giacone
# Class: CS5201 Section A
# Instructor: Clayton Price
# Homework 2
# Student ID: 12400927
# Login: Jmgv27
# Date: 2/11/2016
# Filename: makefile
# Description: A makefile to facilitate compiling homework 2

CXX = /usr/bin/g++
FLAGS = -std=c++11 -g -Wall -W -pedantic-errors

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

driver.o: driver.cpp Polynomial.h Term.h Polynomial.hpp InfinityNorm.h InfinityNorm.hpp RangeError.h SizeError.h
