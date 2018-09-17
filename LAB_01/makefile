FantasyFootball: main.o Executive.o Quarterback.o
	g++ -std=c++11 -g -Wall main.o Executive.o Quarterback.o -o FantasyFootball

main.o: main.cpp Executive.h Quarterback.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Quarterback.o: Quarterback.h Quarterback.cpp
	g++ -std=c++11 -g -Wall -c Quarterback.cpp

clean:
	rm *.o FantasyFootball
