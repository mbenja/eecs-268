LAB6: main.o Executive.o Sudoku.o Square.o
	g++ -g -std=c++11 -Wall main.o Executive.o Sudoku.o Square.o -o LAB6

main.o: main.cpp Executive.h Sudoku.h Square.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Sudoku.h Square.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

Sudoku.o: Sudoku.h Square.h
	g++ -g -std=c++11 -Wall -c Sudoku.cpp

Square.o: Square.h
	g++ -g -std=c++11 -Wall -c Square.cpp

clean:
	rm *.o LAB6