 LAB3: main.o Executive.o BrowserHistory.o
	g++ -g -std=c++11 -Wall main.o Executive.o BrowserHistory.o -o LAB3

main.o: main.cpp Executive.h BrowserHistory.h LinkedList.h LinkedList.hpp Node.h Node.hpp ListInterface.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp BrowserHistory.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

BrowserHistory.o: BrowserHistory.h BrowserHistory.cpp BrowserHistoryInterface.h
	g++ -g -std=c++11 -Wall -c BrowserHistory.cpp

clean:
	rm *.o LAB3
