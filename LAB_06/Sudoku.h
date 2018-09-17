/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 06
FILE NAME: SUDOKU.H
FILE CONTENTS: HEADER FILE FOR SUDOKU CLASS
*/

#ifndef SUDOKU_H
#define SUDOKU_H

#include "Square.h"

#include <string>
#include <stdexcept>

class Sudoku {
public:
    // @ pre-condition: none
    // @ post-condition: m_rows, m_cols, and m_board are initialized
    // @ throws: none
    Sudoku();

    // @ pre-condition:
    // @ post-condition: all memory allocated to instance of sudoku class has been deallocated
    // @ throws:
    ~Sudoku();

    // @ pre-condition: expects string, is fixed flag for indices, and indices to set value
    // @ post-condition: value is set at given indices in the form of a new instance of square class
    // @ throws: std::runtime_error if indices are outside of range
    void setValue(std::string t_value, bool t_is_fixed, int t_row, int t_col) throw (std::runtime_error);

    // @ pre-condition: expects string value, int row as parameter
    // @ post-condition: returns true or false dependent on whether or not parameter was found in row of 2d array
    // @ throws: none
    bool checkRow(std::string t_value, int t_row);

    // @ pre-condition: expects string value, int col as parameter
    // @ post-condition: returns true or false dependent on whether or not parameter was found in column of 2d array
    // @ throws: none
    bool checkCol(std::string t_value, int t_col);

    // @ pre-condition: expects string value, int row, int col as parameters
    // @ post-condition: returns true or false dependent on whether or not string parameter was found in row of 2d array
    // @ throws: none
    bool checkSubSquare(std::string t_value, int t_row, int t_col);

    // @ pre-condition: none
    // @ post-condition: prints out entire board in its current state
    // @ throws: none
    void printBoard();

    // @ pre-condition: none
    // @ post-condition: returns true or false dependent on if every position on board has been filled
    // @ throws: none
    bool boardFull();

    // @ pre-condition: expects int for row, col, and bool for backtrack as parameters
    // @ post-condition: returns true or false dependent on if the puzzle was solved
    // @ throws: std::runtime_error if outside of range
    bool solveBoard(int t_row, int t_col, bool backtrack);

private:
    Square** m_board;
    int m_rows;
    int m_cols;
};
#endif