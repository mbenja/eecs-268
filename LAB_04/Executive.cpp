/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: EXECUTIVE.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR EXECUTIVE CLASS
*/

#include "Executive.h"
#include "Process.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

Executive::Executive(std::string t_file_name) {
    std::ifstream inFile;
    std::string input = "";
    std::string process_name = "";
    std::string method_name = "";

    m_linked_list = new LinkedList<Process>();

    inFile.open(t_file_name);

    while (!(inFile.eof())) {
        inFile >> input;

        if (input == "start") {
            // read in process name
            inFile >> process_name;
            // calls start process method
            startProcess(process_name);
        } else {
            process_name = input;
            inFile >> input;
            if (input == "calls") {
                inFile >> method_name;
                // calls method to push stack
                try{
                    callMethod(process_name, method_name);
                } catch (std::runtime_error &err) {
                    std::cout << err.what() << std::endl;
                }
            } else {
                // calls method to pop off stack
                try {
                    returnMethod(process_name);
                } catch (std::runtime_error &err) {
                    std::cout << err.what() << std::endl;
                }
            }
        }
    }
}

Executive::~Executive() {

}

void Executive::startProcess(std::string t_process_name) {
    // create new process with name
    m_linked_list->addFront(t_process_name);

    // output information
    std::cout << "Process " << t_process_name << " has started." << std::endl;
}

void Executive::callMethod(std::string t_process_name, std::string t_method_name) throw (std::runtime_error) {
    bool isFound = false;
    int index = 0;
    //Process* temp_ptr = new Process();
    Process temp_process;
    // checking if process exists in linked list
    for (int i = 0; i < m_linked_list->getLength(); i++) {
        temp_process = m_linked_list->getEntry(i);
        if (t_process_name == temp_process.getName()) {
            isFound = true;
        }
        if (!isFound) {
            index++;
        }
    }
    if (isFound) {
        try {
            temp_process = m_linked_list->getEntry(index);
            temp_process.pushMethod(t_method_name);
            std::cout << "Process " << t_process_name << " called method " << t_method_name << "." << std::endl;
        } catch (std::runtime_error &err) {
            std::cout << err.what() << std::endl;
        }
    } else {
        throw std::runtime_error("ERROR: Process not found.");
    }
}

void Executive::returnMethod(std::string t_process_name) throw (std::runtime_error) {
    bool isFound = false;
    int index = 0;
    //Process* temp_ptr = new Process();
    Process temp_process;
    std::string popped_method = "";

    // checking to see if process exists in linked list
    for (int i = 0; i < m_linked_list->getLength(); i++) {
        temp_process = m_linked_list->getEntry(i);
        if (t_process_name == temp_process.getName()) {
            isFound = true;
        }
        if (!isFound) {
            index++;
        }
    }

    // if process was found
    if (isFound) {
        temp_process = m_linked_list->getEntry(index);
        popped_method = temp_process.peekMethod();
        if (temp_process.getSize() == 0) {
            try {
                temp_process.popMethod();
                //m_linked_list->remove(index);
            } catch (std::runtime_error &err) {
                std::cout << err.what() << std::endl;
            }
            std::cout << "Process " << t_process_name << " has terminated." << std::endl;
        } else {
            try {
                temp_process.popMethod();
            } catch (std::runtime_error &err) {
                std::cout << err.what() << std::endl;
            }
            std::cout << "Process " << t_process_name << " has returned." << std::endl;
        }
    } else {
        std::cout << "POP METHOD - PROCESS WAS NOT FOUND" << std::endl;
    }
}