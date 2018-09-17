/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: PROCESS.H
FILE CONTENTS: HEADER FILE FOR PROCESS CLASS
*/

#ifndef PROCESS_H
#define PROCESS_H

#include "Stack.h"
#include <string>

class Process {
public:
    // @ pre-condition: node
    // @ post-condition: an instance of process class has been created
    // @ throws: none
    Process();

    // @ pre-condition: std::string has been passed in for name of process
    // @ post-condition: a process of given name has been instanced
    // @ throws: none
    Process(std::string t_name);

    // @ pre-condition: none
    // @ post-condition: stack and all memory for process has been deallocated
    // @ throws: none
    ~Process();

    // @ pre-condition: 
    // @ post-condition: returns string of name of process
    // @ throws: none
    std::string getName();

    // @ pre-condition: process ptr as parameter
    // @ post-condition: parameter has been set as next
    // @ throws: none
    void setNext(Process* t_next);

    // @ pre-condition: 
    // @ post-condition: returns next process ptr
    // @ throws: none
    Process* getNext() const;

    // @ pre-condition: std::string as value to be set
    // @ post-condition: parameter is set as value
    // @ throws: none
    void setValue(std::string t_value);

    // @ pre-condition: 
    // @ post-condition: m_size is returned
    // @ throws: none
    int getSize();

    // @ pre-condition: std::string as parameter
    // @ post-condition: pushes value onto stack
    // @ throws: none
    void pushMethod(std::string t_value);

    // @ pre-condition: 
    // @ post-condition: pops method off the stack
    // @ throws: none
    void popMethod();

    // @ pre-condition: 
    // @ post-condition: returns value of peek into stack
    // @ throws: none
    std::string peekMethod();

private:
    Process* m_next;
    Stack<std::string>* m_stack;
    int m_size;
    std::string m_name;
};
#endif