CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: prog

prog: songmain.o song.o song.h
	$(CC) songmain.o song.o -o prog

songmain.o: songmain.cpp
	$(CC) $(CFLAGS) songmain.cpp

song.o: song.cpp
	$(CC) $(CFLAGS) song.cpp


clean:
	rm -rf *.o
