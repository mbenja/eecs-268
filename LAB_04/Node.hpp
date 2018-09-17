/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: NODE.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR NODE CLASS
*/

template <typename ItemType>
Node<ItemType>::Node(ItemType t_value) {
  m_value = t_value;
  m_next = nullptr;
};

template <typename ItemType>
Node<ItemType>::Node() {
  m_next = nullptr;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
  return m_next;
}

template <typename ItemType>
ItemType Node<ItemType>::getValue() const {
  return m_value;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* t_next) {
  m_next = t_next;
}

template <typename ItemType>
void Node<ItemType>::setValue(ItemType t_value) {
  m_value = t_value;
}
