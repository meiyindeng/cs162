# Project 4 - Meiyin Deng
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: project4.o Task.o Task.h Tasklist.o Tasklist.h
	$(CC) project3.o task.o -o prog

project3.o: project4.cpp
	$(CC) $(CFLAGS) project4.cpp

Task.o: Task.cpp
	$(CC) $(CFLAGS) Task.cpp

Tasklist.o: Tasklist.cpp
	$(CC) $(CFLAGS) Tasklist.cpp

clean:
	rm -rf *.o
