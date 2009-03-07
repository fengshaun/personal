INCLUDES=`pkg-config --cflags sigc++-2.0`
LIBS=`pkg-config --libs sigc++-2.0`
OBJECTS=main.o sender.o receiver.o
EXECUTABLE=demo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ $(OBJECTS) $(LIBS) $(INCLUDES) -o $(EXECUTABLE)
	
main.o: main.cpp
	g++ -c main.cpp $(INCLUDES)
	
sender.o: sender.cpp
	g++ -c sender.cpp $(INCLUDES)
	
receiver.o: receiver.cpp
	g++ -c receiver.cpp
	
clean:
	rm -rf *.o