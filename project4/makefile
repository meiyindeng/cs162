# Project 4 - Meiyin Deng
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: project4.o Task.o Task.h TaskList.o TaskList.h
	$(CC) project4.o Task.o TaskList.o -o prog

project4.o: project4.cpp
	$(CC) $(CFLAGS) project4.cpp

Task.o: Task.cpp
	$(CC) $(CFLAGS) Task.cpp

TaskList.o: TaskList.cpp
	$(CC) $(CFLAGS) TaskList.cpp

clean:
	rm -rf *.o

