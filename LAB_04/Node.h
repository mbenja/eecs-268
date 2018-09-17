/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: NODE.H
FILE CONTENTS: HEADER FILE FOR NODE CLASS
*/

#ifndef NODE_H
#define NODE_H

template <typename ItemType>
class Node {
public:
  // @ pre-condition: ItemType is passed in as parameter
  // @ post-condition: a node of ItemType has been created
  // @ throws: none
  Node(ItemType t_value);

  // @ pre-condition: none
  // @ post-condition: an empty node has been created
  // @ throws: none
  Node();

  // @ pre-condition: none
  // @ post-condition: returns node<ItemType> pointer of next node
  // @ throws: none
  Node<ItemType>* getNext() const;

  // @ pre-condition: 
  // @ post-condition: returns value stored in node
  // @ throws: none
  ItemType getValue() const;

  // @ pre-condition: a node pointer is being passed in as parameter
  // @ post-condition: the parameter has been set as the next node
  // @ throws: none
  void setNext(Node<ItemType>* t_next);

  // @ pre-condition: ItemType is being passed in as a parameter
  // @ post-condition: parameter has been set as value for node
  // @ throws: none
  void setValue(ItemType t_value);

private:
  ItemType m_value;
  Node<ItemType>* m_next;
};
#include "Node.hpp"
#endif
