# Project 5 - Meiyin Deng
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: project5.o Task.o Task.h TaskList.o TaskList.h Node.o Node.h
	$(CC) project5.o Task.o TaskList.o Node.o -o prog

project5.o: project5.cpp
	$(CC) $(CFLAGS) project5.cpp

Task.o: Task.cpp
	$(CC) $(CFLAGS) Task.cpp

TaskList.o: TaskList.cpp
	$(CC) $(CFLAGS) TaskList.cpp

Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp

clean:
	rm -rf *.o

