/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: NODE.H
@ DATE: 09/26/17
@ BRIEF: HEADER FILE FOR NODE CLASS
*/

#ifndef NODE_H
#define NODE_H

template <typename ItemType>
class Node {
public:
  Node(ItemType t_value);
  Node();
  // returns next node pointer in list
  Node<ItemType>* getNext() const;
  // gets value stored in node
  ItemType getValue() const;
  // sets next pointer node
  void setNext(Node<ItemType>* t_next);
  // sets value of node
  void setValue(ItemType t_value);

private:
  ItemType m_value;
  Node<ItemType>* m_next;
};
#include "Node.hpp"
#endif
