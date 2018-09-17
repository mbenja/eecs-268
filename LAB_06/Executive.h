/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 06
FILE NAME: EXECUTIVE.H
FILE CONTENTS: HEADER FILE FOR EXECUTIVE CLASS
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Sudoku.h"

#include <string>

class Executive {
public:
    // @ pre-condition: expects string of file name as parameter
    // @ post-condition: instance of soduku class has been created and recursive solution begins
    // @ thows: none
    Executive(std::string t_file_name);

    // @ pre-condition: none
    // @ post-condition: all memory allocated to executive class has been deallocated
    // @ throws: none
    ~Executive();

private:
    Sudoku m_game;
};
#endif