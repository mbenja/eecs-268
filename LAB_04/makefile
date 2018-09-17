LAB4: main.o Executive.o Process.o
	g++ -g -std=c++11 -Wall main.o Executive.o Process.o -o LAB4

main.o: main.cpp Executive.h LinkedList.h LinkedList.hpp ListInterface.h Stack.h Stack.hpp StackInterface.h Node.h Node.hpp Process.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Process.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

Process.o: Process.h Process.cpp
	g++ -g -std=c++11 -Wall -c Process.cpp

clean:
	rm *.o LAB4
