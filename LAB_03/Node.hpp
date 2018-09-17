/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: NODE.HPP
@ DATE: 09/26/17
@ BRIEF: IMPLEMENTATION FILE FOR NODE CLASS
*/

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
Node<ItemType>::Node(ItemType t_value) {
  m_value = t_value;
  m_next = nullptr;
};

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
Node<ItemType>::Node() {
  m_next = nullptr;
}

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
  return m_next;
}

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
ItemType Node<ItemType>::getValue() const {
  return m_value;
}

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* t_next) {
  m_next = t_next;
}

// @ pre-condition:
// @ post-condition:
template <typename ItemType>
void Node<ItemType>::setValue(ItemType t_value) {
  m_value = t_value;
}
