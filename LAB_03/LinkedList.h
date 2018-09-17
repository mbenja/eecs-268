/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: LINKEDLIST.H
@ DATE: 09/26/17
@ BRIEF: HEADER FILE FOR LINKEDLIST CLASS, NOTES ON METHODS ARE IN INTERFACE FILE
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"

template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
public:
  LinkedList();
  ~LinkedList();
  bool isEmpty() const;
  int getLength() const;
  void insert(int t_new_position, const ItemType& t_new_entry) throw(std::runtime_error);
  ItemType getEntry(int t_position) throw(std::runtime_error);
  void remove(int t_position) throw(std::runtime_error);
  void clear();
  void setEntry(int t_position, const ItemType& t_new_entry) throw(std::runtime_error);

private:
  Node<ItemType>* m_front;
  int m_size;
};
#include "LinkedList.hpp"
#endif
