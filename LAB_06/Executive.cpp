/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 06
FILE NAME: EXECUTIVE.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR EXECUTIVE CLASS
*/

#include "Executive.h"
#include "Sudoku.h"

#include <string>
#include <fstream>
#include <iostream>

Executive::Executive(std::string t_file_name) {
    std::fstream inFile;
    std::string read_data;
    int count_rows = 0;
    int count_cols = 0;

    inFile.open(t_file_name);

    // verify proper formatting of input data for a soduku puzzle
    // checking number of rows
    while (inFile.peek() != EOF) {
        std::getline(inFile, read_data);
        count_rows++;
    }
    inFile.close();
    
    // have correct number of rows
    if (count_rows == 9) {
        // checking number of columns
        inFile.open(t_file_name);
        while (inFile.peek() != EOF) {
            read_data = inFile.get();
            if (read_data != " " && read_data != "\n") {
                count_cols++;
            }
        }
        inFile.close();

        // have correct number of columns too, proceed with program
        if (count_cols / 9 == count_rows) {
            inFile.open(t_file_name);
            // filling sudoku board with values from input file
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    read_data = inFile.get();
                    if (read_data != " " && read_data != "\n") {
                        try {
                            if (read_data != "_") {
                                m_game.setValue(read_data, false, i, j);
                            } else {
                                m_game.setValue(read_data, true, i, j);
                            }
                        } catch (std::runtime_error &err) {
                            std::cout << err.what() << std::endl;
                        }
                    } else {
                        j--;
                    }
                }
            }
        
            // closing file
            inFile.close();
        
            // printing out sudoku board before beginning solution
            std::cout << "Sudoku puzzle: UNSOLVED" << std::endl;
            m_game.printBoard();
        
            // calling recursive method to solve board 
            m_game.solveBoard(0,0, false);
        
            if (m_game.solveBoard(0, 0, false)) {
                // printing out sudoku board after finishing solution
                std::cout << "Sudoku puzzle: SOLVED" << std::endl;
                m_game.printBoard();
            } else {
                std::cout << "Sudoku puzzle was impossible to solve." << std::endl;
            }
        } else {
            std::cout << "ERROR: Improperly formatted input file." << std::endl;
        }
    } else {
        std::cout << "ERROR: Improperly formatted input file." << std::endl;
    }
}

Executive::~Executive() {

}