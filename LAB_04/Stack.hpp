/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: STACK.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR STACK CLASS
*/

#include "Node.h"
#include <stdexcept>
#include <iostream>

template <typename ItemType>
Stack<ItemType>::Stack() {
    //m_top = nullptr;
    m_items = nullptr;
    m_items = new ItemType[5];
    for (int i = 0; i < 5; i++) {
        m_items[i] = "";
    }
    m_size = 5;
    m_top = 0;
}

template <typename ItemType>
Stack<ItemType>::~Stack() {
    /*
    while (m_top != nullptr) {
        pop();
    }
    */
    //delete[] m_items;
}

template <typename ItemType>
bool Stack<ItemType>::isEmpty() const {
    /*
    if (m_top == nullptr) {
        return true;
    } else {
        return false;
    }
    */
    if (m_top == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename ItemType>
void Stack<ItemType>::push(const ItemType& t_new_entry) throw (std::runtime_error) {
    /*
    Node<ItemType>* temp_new = new Node<ItemType>(t_new_entry);
    temp_new->setNext(m_top);
    m_top = temp_new;
    std::cout << "M_TOP VALUE IS: " << m_top->getValue() << std::endl;
    if (m_top->getNext() != nullptr) {
        std::cout << "VALUE BELOW M_TOP IS: " << m_top->getNext()->getValue() << std::endl;  
    }
    */
    // doubling array size
    if (m_top == m_size) {
        ItemType* temp_items = m_items;
        m_items = new ItemType[m_size * 2];
        for (int i = 0; i < m_size; i++) {
            m_items[i] = "";
        }
        for (int i = 0; i < (m_size / 2); i++) {
            m_items[i] = temp_items[i];
        }
    }
    //std::cout << "PUSH METHOD - PUSHING ITEM INTO STACK: " << t_new_entry << std::endl;
    m_items[m_top] = t_new_entry;
    m_top++;

    // printing out stack

    /*
    std::cout << "PRINTING OUT STACK AFTER PUSH" << std::endl;
    for (int i = 0; i < m_top; i++) {
        std::cout << m_items[i];
        if (i == (m_top - 1)) {
            std::cout << " <- TOP";
        }
        std::cout << std::endl;
    }
    */
}

template <typename ItemType>
void Stack<ItemType>::pop() throw (std::runtime_error) {
    /*
    Node<ItemType>* temp_old = m_top;
    m_top = m_top->getNext();
    delete temp_old;
    */
    
    /*
    std::cout << "PRINTING OUT STACK BEFORE POP" << std::endl;
    for (int i = 0; i < m_size; i++) {
        std::cout << m_items[i];
        if (i == (m_top - 1)) {
            std::cout << " <- TOP";
        }
        std::cout << std::endl;
    }
    */
    

    if (m_top < 0) {
        throw std::runtime_error("POP ERROR: Stack is empty.");
    } else {
        m_top--;
    }

    /*
    std::cout << "PRINTING OUT STACK AFTER POP" << std::endl;
    for (int i = 0; i < m_size; i++) {
        std::cout << m_items[i];
        if (i == (m_top - 1)) {
            std::cout << " <- TOP";
        }
        std::cout << std::endl;
    }
    */
    
}

template <typename ItemType>
std::string Stack<ItemType>::peek() const throw (std::runtime_error) {
    /*
    if (isEmpty()) {
        throw std::runtime_error("ERROR: Empty stack.\n");
    } else {
        return (m_top->getValue());
    }
    */
    /*
    if (isEmpty()) {
        throw std::runtime_error("PEEK ERROR: Empty stack.");
    } else {
        return (m_items[m_top]);
    }
    */
    //std::cout << "PEEK METHOD: " << m_items[m_top-1] << std::endl;

    /*
    std::cout << "PRINTING OUT STACK BEFORE PEEK" << std::endl;
    for (int i = 0; i < (m_top); i++) {
        std::cout << m_items[i];
        if (i == (m_top - 1)) {
            std::cout << " <- TOP";
        }
        std::cout << std::endl;
    }
    */
    

    if (m_top == 0) {
        return (m_items[0]);
    } else {
        return (m_items[m_top]);
    }
}
