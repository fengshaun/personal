#makefile for TicTacToe

CC=g++
CFLAGS=-c -g
OBJECTS=Board.o Player.o main.o Game.o
SOURCES=Board.cpp Player.cpp main.cpp Game.cpp
EXECUTABLE=TicTacToe

all: $(EXECUTABLE)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)

Board.o: Board.cpp
	$(CC) $(CFLAGS) Board.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) Player.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) Game.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o $(EXECUTABLE)
