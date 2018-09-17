/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: LINKEDLIST.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR LINKEDLIST CLASS
*/

#include <stdexcept>
#include <iostream>
#include <string>

#include "Node.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList() {
  m_front = nullptr;
  m_size = 0;
};

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {
  for (int i = 0; i < m_size; i++) {
    remove(i);
  }
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
  Node<ItemType>* temp = m_front;
  Node<ItemType>* trail = nullptr;

  if (t_new_position > m_size || t_new_position < 0) {
    throw(std::runtime_error("Invalid position."));
  } else {
    for (int i = 0; i < t_new_position; i++) {
      trail = temp;
      temp = temp->getNext();
    }
    if (t_new_position == 0) {
      // adding node at head
      if (m_front == nullptr) {
        m_front = new Node<ItemType>(t_new_entry);
      } else {
        temp = new Node<ItemType>(t_new_entry);
        temp->setNext(m_front);
        m_front = temp;
      }
    } else {
      // adding node at position
      Node<ItemType>* temp_tail = new Node<ItemType>(t_new_entry);
      trail->setNext(temp_tail);
      trail->getNext()->setNext(temp);
    }
  }

  // updating size of linked list
  m_size++;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int t_position) const throw(std::runtime_error) {
  Node<ItemType>* temp = m_front;

  if (t_position > m_size || t_position < 0) {
    throw(std::runtime_error("Invalid position."));
  } else {
    for (int i = 0; i < t_position; i++) {
      temp = temp->getNext();
    }
    return temp->getValue();
  }
}

template <typename ItemType>
void LinkedList<ItemType>::remove(int t_position) throw(std::runtime_error) {
  Node<ItemType>* temp = m_front;
  Node<ItemType>* trail = nullptr;
  Node<ItemType>* forward = nullptr;

  if (t_position > m_size || t_position < 0) {
    throw(std::runtime_error("Invalid position."));
  } else {
    // traversing linked list
    for (int i = 0; i < t_position; i++) {
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
  Node<ItemType>* temp = nullptr;

  while (m_front != nullptr) {
    temp = m_front;
    m_front = temp->getNext();
    delete temp;

    m_size--;
  }
}

template <typename ItemType>
void LinkedList<ItemType>::setEntry(int t_position, const ItemType& t_new_entry) throw(std::runtime_error) {
  Node<ItemType>* temp = m_front;

  // traversing linked list
  for (int i = 0; i < t_position - 1; i++) {
    temp = temp->getNext();
  }

  temp->setValue(t_new_entry);
}

template <typename ItemType>
void LinkedList<ItemType>::printLinkedList() const {
    Node<ItemType>* temp = nullptr;

    std::cout << "STATUS OF TABLE" << std::endl;

    for (int i = 0; i < m_size; i++) {
        std::cout << "NAME: ";
        // prints out name and card of player
        if (temp == nullptr) {
          temp = m_front;

          std::cout << temp->getValue() << std::endl;
          std::cout << temp->getCard();
          std::cout << std::endl << std::endl;
        } else {
          temp = temp->getNext();
          std::cout << temp->getValue() << std::endl;
          std::cout << temp->getCard();
          std::cout << std::endl << std::endl;
        }
    }
}

template <typename ItemType>
void LinkedList<ItemType>::dealCards(std::string t_suit, std::string t_value, int t_position) {
  Node<ItemType>* temp = m_front;

  for (int i = 0; i < t_position; i++) {
    temp = temp->getNext();
  }

  temp->setCardSuit(t_suit);
  temp->setCardValue(t_value);
}

template <typename ItemType>
int LinkedList<ItemType>::showdown() {
  int min = -1;
  int loser = -1;
  Node<ItemType>* temp = nullptr;

  for (int i = 0; i < m_size; i++) {
    if (temp == nullptr) {
      temp = m_front;
      min = std::stoi(temp->getCardValue());
      loser = 0;
    } else {
      temp = temp->getNext();
      if ((std::stoi(temp->getCardValue()) < min)) {
        min = std::stoi(temp->getCardValue());
        loser = i;
      }
    }
  }

  return loser;
}
