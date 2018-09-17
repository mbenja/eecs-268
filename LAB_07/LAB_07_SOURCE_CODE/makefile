LAB7: main.o Executive.o
	g++ -g -std=c++11 -Wall main.o Executive.o -o LAB7

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Sorts.h Sorts.hpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

clean:
	rm *.o LAB7