/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: QUEUE.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR QUEUE CLASS
*/

#include <iostream>

template <typename ItemType>
Queue<ItemType>::Queue() {
    m_front = nullptr;
    m_back = m_front;
    m_size = 0;
}

template <typename ItemType>
Queue<ItemType>::~Queue() {
    for (int i = 0; i < m_size; i++) {
        dequeue();
    }
}

template <typename ItemType>
bool Queue<ItemType>::isEmpty() const {
    if (m_front == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <typename ItemType>
void Queue<ItemType>::enqueue(const ItemType &t_new_entry) throw (std::runtime_error) {
    if (isEmpty()) {
        m_front = new Node<ItemType>(t_new_entry);
        m_back = m_front;
    } else {
        Node<ItemType>* temp_new = new Node<ItemType>(t_new_entry);
        temp_new->setNext(m_back);
        m_back = temp_new;
    }
    m_size++;
}

template <typename ItemType>
void Queue<ItemType>::dequeue() throw (std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error("DEQUEUE ERROR: Queue is empty.");
    } else {
        Node<ItemType>* temp = m_back;
        for (int i = 0; i < m_size - 2; i++) {
            temp = temp->getNext();
        }
        m_front = temp;
        m_size--;
    }
}

template <typename ItemType>
ItemType Queue<ItemType>::peekFront() const throw (std::runtime_error) {
    if (isEmpty()) {
        throw std::runtime_error("PEEK FRONT ERROR: Queue is empty.");
    } else {
        return m_front->getValue();
    }
}

template <typename ItemType>
int Queue<ItemType>::getSize() const {
    return m_size;
}

template <typename ItemType>
void Queue<ItemType>::printQueue() const {
    Node<ItemType>* temp = m_back;

    std::cout << "STATUS OF WAIT LIST" << std::endl;
    std::cout << "====== BACK OF QUEUE ======" << std::endl;

    for (int i = 0; i < m_size; i++) {
        if (i == 0) {
            std::cout << temp->getValue() << std::endl;
        } else {
            temp = temp->getNext();
            std::cout << temp->getValue() << std::endl;
        }
    }

    std::cout << "====== FRONT OF QUEUE ======" << std::endl << std::endl;
}