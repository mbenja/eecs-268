LAB5: main.o Executive.o Card.o
	g++ -g -std=c++11 -Wall main.o Executive.o Card.o -o LAB5

main.o: main.cpp Executive.h Card.o
	g++ -g -std=c++11 -Wall -c main.cpp 

Executive.o: Executive.h Executive.cpp Card.h Node.h Node.hpp QueueInterface.h Queue.h Queue.hpp ListInterface.h LinkedList.h LinkedList.hpp StackInterface.h Stack.h Stack.hpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

Card.o: Card.h Card.cpp
	g++ -g -std=c++11 -Wall -c Card.cpp

clean:
	rm *.o LAB5