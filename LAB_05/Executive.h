/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: EXECUTIVE.H
FILE CONTENTS: HEADER FILE FOR EXECUTIVE CLASS
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Queue.h"
#include "LinkedList.h"
#include "Stack.h"

#include <string>

class Executive {
public:
    // @ pre-condition: accepts string as parameter for file name
    // @ post-condition: an instance of executive class has been made and file has been read
    // @ throw: none
    Executive(std::string t_file_name);

    // @ pre-condition: none
    // @ post-condition: all memory allocated to executive class has been deallocated
    // @ throw: none
    ~Executive();

private:
    Queue<std::string> m_waiting_list;
    LinkedList<std::string> m_table;
    Stack<std::string> m_deck;
};
#endif