CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: songmain2.o song.o song.h
	$(CC) songmain2.o song.o -o prog

songmain2.o: songmain2.cpp
	$(CC) $(CFLAGS) songmain2.cpp

song.o: song.cpp
	$(CC) $(CFLAGS) song.cpp


clean:
	rm -rf *.o
