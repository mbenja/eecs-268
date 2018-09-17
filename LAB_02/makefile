RosterProgram: main.o Executive.o Roster.o ItemNotFoundException.o
	g++ -g -std=c++11 -Wall main.o Executive.o Roster.o -o RosterProgram

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Collection.h Collection.hpp Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

Roster.o: Roster.h Roster.cpp
	g++ -g -std=c++11 -Wall -c Roster.cpp

ItemNotFoundException.o: ItemNotFoundException.h ItemNotFoundException.cpp
	g++ -g -std=c++11 -Wall -c ItemNotFoundException.cpp

clean: 
	rm *.o RosterProgram


#RosterProgram: main.o Executive.o Roster.o
#	g++ -g -std=c++11 -Wall main.o Executive.o Roster.o -o RosterProgram
#
#main.o: main.cpp Collection.h Collection.hpp
#	g++ -g -std=c++11 -Wall -c main.cpp
#
#Executive.o: Executive.h Executive.cpp
#	g++ -g -std=c++11 -Wall -c Executive.cpp
#
#Roster.o: Roster.h Roster.cpp
#	g++ -g -std=c++11 -Wall -c Roster.cpp
#
#clean: 
#	rm *.o RosterProgram