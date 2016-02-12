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
