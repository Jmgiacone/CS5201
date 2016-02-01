#Filename: makefile1.txt
#Author: Jordan Giacone
#Email: Jmgv27@mst.edu
#Student ID: 12400927
#Class: CS 5201
#Instructor: Clayton Price
#Date: 1/26/16
#Purpose: This is a description file to compile the code provided for part 1
# of homework 1

#Default target if no parameters given
default: all

#Target to build all targets
all: driver

#Compile the main output file called "driver"
driver: brewMain.o beer.o additives.o
	g++ -Wall -W -pedantic-errors brewMain.o beer.o additives.o -o driver

#Instructions for compiling brewMain.o	
brewMain.o: brewMain.cpp \
            wine.h       \
            yeast.h      \
            additives.h  \
            wine.hpp     \
            beer.h       \
            hops.h       \
            grains.h
	g++ -c brewMain.cpp -o brewMain.o

#Instructions for compiling beer.o	
beer.o: beer.cpp \
        beer.h   \
        yeast.h  \
        hops.h   \
        grains.h
	g++ -c beer.cpp -o beer.o

#Instructions for compiling additives.o	
additives.o: additives.cpp \
             additives.h
	g++ -c additives.cpp -o additives.o

#A clean target that will wipe out compiled files as well as core dumps	
clean:
	-@rm -f brewMain.o > /dev/null 2>&1
	-@rm -f beer.o > /dev/null 2>&1
	-@rm -f additives.o > /dev/null 2>&1
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
