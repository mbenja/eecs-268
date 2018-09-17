/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: EXECUTIVE.H
FILE CONTENTS: HEADER FILE FOR EXECUTIVE CLASS
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "LinkedList.h"
#include "Process.h"
#include <string>
#include <stdexcept>

class Executive {
public:
    // @ pre-condition: a string for file name is being passed in as parameter
    // @ post-condition: an executive class instance has been created and file has been read
    // @ throws: none
    Executive(std::string t_file_name);

    // @ pre-condition: none
    // @ post-condition: linked list has been destroyed to free memory
    // @ throws: none
    ~Executive();

    // @ pre-condition: a string for process name is being passed in as parameter
    // @ post-condition: the process has been created and added into linked list
    // @ throws: none
    void startProcess(std::string t_process_name);

    // @ pre-condition: a string for process name and for method name is being passed in as parameter
    // @ post-condition: a method has been pushed to the stack for the given process
    // @ throws: runtime_error if the process is not found in the linked list
    void callMethod(std::string t_process_name, std::string t_method_name) throw (std::runtime_error);

    // @ pre-condition: a string for process name is being passed in as parameter
    // @ post-condition: a method has been popped to the stack for the given process
    // @ throws: runtime_error if the process is not found in the linked list
    void returnMethod(std::string t_process_name) throw (std::runtime_error);

private:
    LinkedList<Process>* m_linked_list;
};
#endif