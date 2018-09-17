/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: PROCESS.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR PROCESS CLASS
*/

#include "Process.h"
#include <string>
#include <iostream>
#include "Stack.h"

Process::Process() {
    m_next = nullptr;
    std::string temp_new = "main";
    m_stack = new Stack<std::string>();
    m_stack->push(temp_new);
    m_size = 0;
};

Process::Process(std::string t_name) {
    m_next = nullptr;
    m_name = t_name;
    std::string temp_new = "main";
    m_stack = new Stack<std::string>();
    m_stack->push(temp_new);
    m_size = 0;
}

Process::~Process() {

}

std::string Process::getName() {
    return m_name;
}

void Process::setNext(Process* t_next) {
    m_next = t_next;
}

Process* Process::getNext() const {
    return m_next;
}

void Process::setValue(std::string t_value) {
    m_name = t_value;
}

int Process::getSize() {
    return m_size;
}

void Process::pushMethod(std::string t_value) {
    m_size++;
    m_stack->push(t_value);
}

void Process::popMethod() {
    m_size--;
    m_stack->pop();
}

std::string Process::peekMethod() {
    return m_stack->peek();
}