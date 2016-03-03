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

driver.o: driver.cpp Matrix.h Matrix.hpp Vector.h Vector.hpp GaussianElimination.h GaussianElimination.hpp
