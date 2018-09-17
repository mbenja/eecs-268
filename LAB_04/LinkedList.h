/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: LINKEDLIST.H
FILE CONTENTS: HEADER FILE FOR LINKEDLIST CLASS
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"
#include "Process.h"

template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
public:
  // @ pre-condition: none
  // @ post-condition: a linked list instance has been created
  // @ throws: none
  LinkedList();

  // @ pre-condition: none
  // @ post-condition: all memory has been deallocated
  // @ throws: none
  ~LinkedList();

  // @ pre-condition: none
  // @ post-condition: returns bool regarding whether or not linked list is empty
  // @ throws: none
  bool isEmpty() const;

  // @ pre-condition: none
  // @ post-condition: returns int that is length of linked list
  // @ throws: none
  int getLength() const;

  // @ pre-condition: an int is passed in for position, and an ItemType is passed in as new entry
  // @ post-condition: the entry has been added to the list at the given position
  // @ throws: rune_time error if position is outside bounds
  void insert(int t_new_position, const ItemType& t_new_entry) throw(std::runtime_error);

  // @ pre-condition: an int is passed in for position
  // @ post-condition: returns ItemType of the entry at given position
  // @ throws: runtime_error if position is outside bounds
  ItemType getEntry(int t_position) throw(std::runtime_error);

  // @ pre-condition: an int is passed in for position
  // @ post-condition: entry at position is removed from linked list
  // @ throws: runtime_error if position is outside bounds
  void remove(int t_position) throw(std::runtime_error);

  // @ pre-condition: none
  // @ post-condition: linked list is emptied
  // @ throws: none
  void clear();

  // @ pre-condition: an int is passed in for position, and an ItemType is passed in as entry
  // @ post-condition: the entry has been placed at the given position
  // @ throws: runtime_error if position is outside bounds
  void setEntry(int t_position, const ItemType& t_new_entry) throw(std::runtime_error);

  // @ pre-condition: ItemType is passed as new entry
  // @ post-condition: new entry is placed at the front of the linked list
  // @ throws: none
  void addFront(ItemType t_new_entry);

  // @ pre-condition: an int is passed in as position, as well as a process pointer
  // @ post-condition: a linked list instance has been created
  // @ throws: runtime_error if position is outside bounds
  void traverseList(int t_position, Process* t_ptr) throw(std::runtime_error);

private:
  Process* m_front;
  int m_size;
};
#include "LinkedList.hpp"
#endif
