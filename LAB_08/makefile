LAB8: main.o Executive.o
	g++ -g -std=c++11 -Wall main.o Executive.o -o LAB8

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h PrecondViolatedExcep.h Node.h Node.hpp BinaryNode.h BinaryNode.hpp BinaryNodeTree.h BinaryNodeTree.hpp LinkedStack.h LinkedStack.hpp StackInterface.h BinaryTreeInterface.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

clean:
	rm *.o LAB8