CC=g++

all: prog

prog: main.o PersonData.o
	$(CC) main.o PersonData.o -o prog

main.o: main.cpp
	$(CC) -c -Wall main.cpp

PersonData.o: PersonData.cpp PersonData.h
	$(CC) -c -Wall PersonData.cpp

clean:
	rm -rf *.o


