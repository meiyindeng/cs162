# Project 3 - Meiyin Deng
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: project3.o task.o task.h
	$(CC) project3.o task.o -o prog

project3.o: project3.cpp
	$(CC) $(CFLAGS) project3.cpp

task.o: task.cpp
	$(CC) $(CFLAGS) task.cpp


clean:
	rm -rf *.o
