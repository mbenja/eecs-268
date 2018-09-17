/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: STACK.H
FILE CONTENTS: HEADER FILE FOR STACK CLASS
*/

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"

template <typename ItemType>
class Stack : public StackInterface<ItemType> {
public:
  Stack();
  ~Stack();

  /** Sees whether this stack is empty.
   @return True if the stack is empty, or false if not. */

  bool isEmpty() const;

  /** Adds a new entry to the top of this stack.
   @post If the operation was successful, newEntry is at the top of the stack.
   @param newEntry The object to be added as a new entry.
   @throw std::runtime_error if no memory available for the new item */

  void push(const ItemType& t_new_entry) throw (std::runtime_error);

 /** Removes the top of this stack.
 @pre The stack is not empty.
   @post If the operation was successful, the top of the stack has been removed.
   @throw std::runtime_error if the stack is empty when called */

  void pop() throw (std::runtime_error);

  /** Returns the top of this stack.
   @pre The stack is not empty.
   @post The top of the stack has been returned, and the stack is unchanged.
   @return The top of the stack.
   @throw std::runtime_error if the stack is empty when called */

  std::string peek() const throw (std::runtime_error);

private:
  //Node<ItemType>* m_top;
  std::string* m_items;
  int m_size;
  int m_top;
};
#include "Stack.hpp"
#endif
