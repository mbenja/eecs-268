/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 09
FILE NAME: EXECUTIVE.H
FILE CONTENTS: HEADER FILE FOR EXECUTIVE.H
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>

class Executive {
    public:
    // @ pre-condition: expects string as parameter for file name to be opened
    // @ post-condition: file has been read and binary search tree has been created
    // @ throw: none
    Executive(std::t_file_name);

    // @ pre-condition: none
    // @ post-condition: all memory allocated to executive class has been deallocated
    // @ throw: none
    ~Executive();

    private:
    // binary search tree
};
#endif