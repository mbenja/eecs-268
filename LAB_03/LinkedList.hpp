/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: LINKEDLIST.HPP
@ DATE: 09/26/17
@ BRIEF: IMPLEMENTATION FILE FOR LINKEDLIST CLASS
*/

#include <stdexcept>
#include <iostream>
#include <string>

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
LinkedList<ItemType>::LinkedList() {
  m_front = nullptr;
  m_size = 0;
};

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {

};

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
  if (m_front == nullptr) {
    return true;
  } else {
    return false;
  }
};

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
int LinkedList<ItemType>::getLength() const {
  return m_size;
};

// @ pre-condition:
// @ post-condition:
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
        //std::cout << "ADDING NODE AT HEAD" << std::endl;
        m_front = new Node<ItemType>(t_new_entry);
      } else {
        temp = new Node<ItemType>(t_new_entry);
        temp->setNext(m_front);
        m_front = temp;
      }
    } else {
      // adding node at position
      //std::cout << "ADDING NODE AT POSITION" << std::endl;
      Node<ItemType>* temp_tail = new Node<ItemType>(t_new_entry);
      trail->setNext(temp_tail);
      trail->getNext()->setNext(temp);
    }
  }

  // updating size of linked list
  m_size++;

  /*
  // printing linked list
  std::cout << "PRINTING LINKED LIST" << std::endl;
  for (int i = 0; i < m_size; i++) {
    std::cout << getEntry(i) << std::endl;
  }
  */
}

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int t_position) throw(std::runtime_error) {
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

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
void LinkedList<ItemType>::remove(int t_position) throw(std::runtime_error) {
  Node<ItemType>* temp = m_front;
  Node<ItemType>* trail = nullptr;
  Node<ItemType>* forward = nullptr;

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

  /*
  // printing linked list
  std::cout << "PRINTING LINKED LIST" << std::endl;
  for (int i = 0; i < m_size; i++) {
    std::cout << getEntry(i) << std::endl;
  }
  */
}

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
void LinkedList<ItemType>::clear() {
  Node<ItemType>* temp = nullptr;

  while (m_front != nullptr) {
    temp = m_front;
    m_front = temp->getNext();
    delete temp;

    m_size--;
  }

  /*
  // printing linked list
  std::cout << "PRINTING LINKED LIST" << std::endl;
  for (int i = 0; i < m_size; i++) {
    std::cout << getEntry(i) << std::endl;
  }
  */
}

// @ pre-condition: 
// @ post-condition:
template <typename ItemType>
void LinkedList<ItemType>::setEntry(int t_position, const ItemType& t_new_entry) throw(std::runtime_error) {
  Node<ItemType>* temp = m_front;

  // traversing linked list
  for (int i = 0; i < t_position - 1; i++) {
    temp = temp->getNext();
  }

  temp->setValue(t_new_entry);

  /*
  // printing linked list
  std::cout << "PRINTING LINKED LIST" << std::endl;
  for (int i = 0; i < m_size; i++) {
    std::cout << getEntry(i) << std::endl;
  }
  */
}
