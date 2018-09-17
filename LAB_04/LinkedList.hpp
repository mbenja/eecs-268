/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: LINKEDLIST.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR LINKEDLIST CLASS
*/

#include <stdexcept>
#include <iostream>
#include "Node.h"
#include "Process.h"
#include <string>

template <typename ItemType>
LinkedList<ItemType>::LinkedList() {
  m_front = nullptr;
  m_size = 0;
};

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {

};

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
  if (m_front == nullptr) {
    return true;
  } else {
    return false;
  }
};

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {
  return m_size;
};

template <typename ItemType>
void LinkedList<ItemType>::insert(int t_new_position, const ItemType& t_new_entry) throw(std::runtime_error) {
  Process* temp = m_front;
  Process* trail = nullptr;

  std::cout << "IN INSERT METHOD" << std::endl;

  if (t_new_position >= m_size || t_new_position < 0) {
    throw (std::runtime_error("Invalid position."));
  } else {
    for (int i = 0; i < t_new_position; i++) {
      trail = temp;
      temp = temp->getNext();
    }
    if (t_new_position == 0) {
      // adding node at head
      if (m_front == nullptr) {
        std::cout << "ADDING NODE AT HEAD" << std::endl;
        m_front = new Process(t_new_entry);
      } else {
        temp = new Process(t_new_entry);
        temp->setNext(m_front);
        m_front = temp;
      }
    } else {
      // adding node at position
      //std::cout << "ADDING NODE AT POSITION" << std::endl;
      Process* temp_tail = new Process(t_new_entry);
      trail->setNext(temp_tail);
      trail->getNext()->setNext(temp);
    }
  }

  // updating size of linked list
  m_size++;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int t_position) throw(std::runtime_error) {
  Process* temp = m_front;

  if (t_position > m_size || t_position < 0) {
    throw(std::runtime_error("Invalid position."));
  } else {
    for (int i = 0; i < t_position; i++) {
      temp = temp->getNext();
    }
    return temp->getName();
  }
}

template <typename ItemType>
void LinkedList<ItemType>::remove(int t_position) throw(std::runtime_error) {
  Process* temp = m_front;
  Process* trail = nullptr;
  Process* forward = nullptr;

  if (t_position > m_size || t_position < 0) {
    throw(std::runtime_error("Invalid position."));
  } else {
    // traversing linked list
    for (int i = 0; i < t_position - 1; i++) {
      trail = temp;
      temp = temp->getNext();
    }

    if (t_position == 0) {
      // removing at front
      temp = m_front;
      m_front = temp->getNext();
      delete temp;
    } else {
      // removing node at position
      forward = temp->getNext();
      trail->setNext(forward);
      delete temp;
    }
  }

  m_size--;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {
  Process* temp = nullptr;

  while (m_front != nullptr) {
    temp = m_front;
    m_front = temp->getNext();
    delete temp;

    m_size--;
  }
}
/*
template <typename ItemType>
void LinkedList<ItemType>::setEntry(int t_position, const ItemType& t_new_entry) throw(std::runtime_error) {
  Process* temp = m_front;

  // traversing linked list
  for (int i = 0; i < t_position - 1; i++) {
    temp = temp->getNext();
  }

  temp->setValue(t_new_entry);
  
}
*/

template <typename ItemType>
void LinkedList<ItemType>::addFront(ItemType t_new_entry) {
  Process* temp = nullptr;
  //std::cout << "ATTEMPTING TO ADD TO FRONT OF LIST" << std::endl;
  if (m_front == nullptr) {
    //std::cout << "M_FRONT IS NULLPTR" << std::endl;
    m_front = new Process(t_new_entry);
  } else {
    temp = new Process(t_new_entry);
    temp->setNext(m_front);
    m_front = temp;
  }
  m_size++;
}

template <typename ItemType>
void LinkedList<ItemType>::traverseList(int t_position, Process* t_ptr) throw(std::runtime_error) {
  t_ptr = m_front;

  if (t_position > m_size || t_position < 0) {
    throw(std::runtime_error("Invalid position."));
  } else {
    // traversing linked list
    for (int i = 0; i < t_position - 1; i++) {
      t_ptr = t_ptr->getNext();
    }
  }
}
