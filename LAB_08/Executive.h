/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 08
FILE NAME: EXECUTIVE.H
FILE CONTENTS: HEADER FILE FOR EXECUTIVE.H
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "BinaryNodeTree.h"
#include "LinkedStack.h"

#include <string>

class Executive {
public:
    // @ pre-condition: expects string as parameter for file name
    // @ post-condition: file is read and postfix expression is parsed
    // @ throws: none
    Executive(std::string t_file_name);

    // @ pre-condition: none
    // @ post-condition: all memory allocated to executive class is deallocated
    // @ throws: none
    ~Executive();

    // @ pre-condition: expects string as parameter to check if it is an operand or operator
    // @ post-condition: returns true if parameter is an operator, false otherwise
    // @ throws: none
    bool isOperator(std::string t_char);

private:
    LinkedStack<BinaryNodeTree<std::string>*> m_stack;
};
#endif