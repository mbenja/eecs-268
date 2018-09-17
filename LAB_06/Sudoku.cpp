/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 06
FILE NAME: SUDOKU.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR SUDOKU CLASS
*/

#include "Sudoku.h"

#include <string>
#include <iostream>
#include <stdexcept>

Sudoku::Sudoku() {
    m_rows = 9;
    m_cols = 9;

    m_board = new Square*[m_rows];
    for (int i = 0; i < m_rows; i++) {
        m_board[i] = new Square[m_cols];
    }
}

Sudoku::~Sudoku() {
    for (int i = 0; i < m_rows; i++) {
        delete [] m_board[i];
    }
    delete [] m_board;
}

void Sudoku::setValue(std::string t_value, bool t_is_fixed, int t_row, int t_col) throw (std::runtime_error) {
    if (t_row < 0 || t_col < 0 || t_row > m_rows || t_col > m_cols) {
        throw std::runtime_error("SET VALUE ERROR: Index out of range.");
    } else {
        m_board[t_row][t_col] = Square(t_value, t_is_fixed);
    }
}

bool Sudoku::checkRow(std::string t_value, int t_row) {
    for (int i = 0; i < m_cols; i++) {
        if (m_board[t_row][i].getValue() == t_value) {
            return true;
        }
    }

    return false;
}

bool Sudoku::checkCol(std::string t_value, int t_col) {
    for (int i = 0; i < m_rows; i++) {
        if (m_board[i][t_col].getValue() == t_value) {
            return true;
        }
    }

    return false;
}

bool Sudoku::checkSubSquare(std::string t_value, int t_row, int t_col) {
    int box_row = t_row - (t_row % 3);
    int box_col = t_col - (t_col % 3);

    // searching 2d array with regards to bounds
    for (int i = box_row; i < (box_row + 3); i++) {
        for (int j = box_col; j < (box_col + 3); j++) {
            if (m_board[i][j].getValue() == t_value) {
                return true;
            }
        }
    }

    return false;
}

void Sudoku::printBoard() {
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            std::cout << m_board[i][j].getValue();
            if (((j + 1) % 3) == 0 && j != 0) {
                std::cout << '\t';
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        if (((i + 1) % 3) == 0 && i != 0) {
            std::cout << std::endl;
        }
    }
}

bool Sudoku::boardFull() {
    bool is_full = true;

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (m_board[i][j].getValue() == "_") {
                is_full = false;
            }
        }
    }

    return is_full;
}

bool Sudoku::solveBoard(int t_row, int t_col, bool backtrack) {
    int start_val = 1;

    // base condition
    if (boardFull()) {
        return true;
    // board is not complete
    } else {
        if (backtrack) {
            // moves back to last index that was not a fixed(given) value
            do {
                if (t_col == 0) {
                    if (t_row != 0) {
                        t_row--;
                        t_col = 8;
                    } else {
                        return false;
                    }
                } else {
                    t_col--;
                }
            } while (!(m_board[t_row][t_col].getIsFixed())); 
            start_val = stoi(m_board[t_row][t_col].getValue());
        } else {
            // getting next empty("_") square
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    if (m_board[i][j].getValue() == "_") {
                        t_row = i;
                        t_col = j;
                        i = 10;
                        j = 10;
                    }
                }
            }
        }

        std::string str_num = "";
        bool in_row = true;
        bool in_col = true;
        bool in_sub_square = true;
        bool able_to_place = false;

        // placing value at square, or applying set up for backtracking
        // blanking out square because we've tried 1 - 10 for current status of board to no avail
        if (start_val + 1 == 10) {
            m_board[t_row][t_col].setValue("_");
        } else {
            for (int i = start_val; i < 10; i++) {
                str_num = std::to_string(i);
                in_row = checkRow(str_num, t_row);
                in_col = checkCol(str_num, t_col);
                in_sub_square = checkSubSquare(str_num, t_row, t_col);
    
                // if i works for index
                if (!(in_row) && !(in_col) && !(in_sub_square)) {
                    m_board[t_row][t_col].setValue(str_num);
                    able_to_place = true;
                    i = 10;
                }
            }
        }

        // weren't able to change status of board but have not tried every number yet for square, so blank it out
        // so we can backtrack and try to change this square once the status of the board has changed
        if (able_to_place != true) {
            m_board[t_row][t_col].setValue("_");
        }

        if (m_board[t_row][t_col].getValue() == "_") {
            // backtracking
            solveBoard(t_row, t_col, true);
        } else {
            // continuing on
            solveBoard(t_row, t_col, false);
        }
    }
}