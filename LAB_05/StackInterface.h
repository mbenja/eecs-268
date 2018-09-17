/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: STACKINTERFACE.H
FILE CONTENTS: HEADER FILE FOR STACK INTERFACE
*/

#ifndef STACK_INTERFACE
#define STACK_INTERFACE

#include <stdexcept>

template<class ItemType>
class StackInterface
{
public:
   /** Virtual destructor allows concrete implementations to clean up
       heap memory when the Stack is discarded. */

   virtual ~StackInterface() {}

   /** Sees whether this stack is empty.
    @return True if the stack is empty, or false if not. */

   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to the top of this stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added as a new entry.
    @throw PrecondViolatedExcep if no memory available for the new item */

   virtual void push(const ItemType& t_suit, const ItemType& t_value) throw (std::runtime_error) = 0;
   
	/** Removes the top of this stack.
	@pre The stack is not empty.
    @post If the operation was successful, the top of the stack has been removed.
    @throw PrecondViolatedExcep if the stack is empty when called */

   virtual void pop() throw (std::runtime_error) = 0;
   
   /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and the stack is unchanged.
    @return The top of the stack.
    @throw PrecondViolatedExcep if the stack is empty when called */

   virtual ItemType peek() const throw (std::runtime_error) = 0;

};
#endif