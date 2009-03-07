#makefile for test.cpp

all: a.out 
	g++ test.o array.o -o a.out

a.out: array.o test.o

array.o: array.cpp
	g++ -c array.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm test.o array.o a.out
