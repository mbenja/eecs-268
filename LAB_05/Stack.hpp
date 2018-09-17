/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: STACK.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR STACK CLASS
*/

#include "Card.h"
#include "Node.h"

#include <stdexcept>
#include <iostream>

template <typename ItemType>
Stack<ItemType>::Stack() {
    m_top = nullptr;
    m_size = 0;
}

template <typename ItemType>
Stack<ItemType>::~Stack() {
    while (m_top != nullptr) {
        pop();
    }
}

template <typename ItemType>
bool Stack<ItemType>::isEmpty() const {
    if (m_top == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <typename ItemType>
void Stack<ItemType>::push(const ItemType& t_card_suit, const ItemType& t_card_value) throw (std::runtime_error) {
    Node<ItemType>* temp_new = new Node<ItemType>(t_card_suit, t_card_value);
    temp_new->setNext(m_top);
    m_top = temp_new;
    m_size++;
}

template <typename ItemType>
void Stack<ItemType>::pop() throw (std::runtime_error) {
    if (m_top == nullptr) {
        throw std::runtime_error("POP ERROR: Stack is empty.");
    } else {
        Node<ItemType>* temp_old = m_top;
        m_top = m_top->getNext();
        delete temp_old;
        m_size--;
    }
    
}

template <typename ItemType>
std::string Stack<ItemType>::peek() const throw (std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error("PEEK ERROR: Empty stack.\n");
    } else {
        return (m_top->getValue());
    }
}

template <typename ItemType>
std::string Stack<ItemType>::peekSuit() const throw (std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error("PEEK SUIT ERROR: Empty stack.\n");
    } else {
        return (m_top->getCardSuit());
    }
}

template <typename ItemType>
std::string Stack<ItemType>::peekValue() const throw (std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error("PEEK VALUE ERROR: Empty stack.\n");
    } else {
        return (m_top->getCardValue());
    }
}
