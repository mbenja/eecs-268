//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified (JRM): throw exceptions instead of return bool success codes

/** Listing 7-4.
    @file LinkedStack.cpp */

#include <stdexcept>

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(NULL)
{
}  // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	// Point to nodes in original chain
	Node<ItemType>* origChainPtr = aStack.topPtr;  

	if (origChainPtr == NULL)
		topPtr = NULL;  // Original stack is empty
	else
	{
		// Copy first node
		topPtr = new Node<ItemType>();
		topPtr->setItem(origChainPtr->getItem());

		// Initialize last node in new chain
		Node<ItemType>* newChainPtr = topPtr;     

		// Advance original-chain pointer past first node
		origChainPtr = origChainPtr->getNext();
	   
		// Copy remaining nodes
		while (origChainPtr != NULL)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();

			// Create a new node containing the next item 
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr); 

			// Advance pointer to new last node      
			newChainPtr = newChainPtr->getNext();   
		}  // end while

		newChainPtr->setNext(NULL);           // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	// Pop until stack is empty
	while (!isEmpty())
		pop();
}  // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == NULL;
}  // end isEmpty

template<class ItemType>
void LinkedStack<ItemType>::push(const ItemType& newItem)
	throw (std::runtime_error) // But it really won't...
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);				
	topPtr = newNodePtr;
}  // end push

template<class ItemType>
void LinkedStack<ItemType>::pop() throw (std::runtime_error)
{
	if (isEmpty())
		throw std::runtime_error("Stack empty on pop");

	// Stack is not empty; delete top
	Node<ItemType>* nodeToDeletePtr = topPtr;
	topPtr = topPtr->getNext();

	// Return deleted node to system
	nodeToDeletePtr->setNext(NULL);
	delete nodeToDeletePtr;
	nodeToDeletePtr = NULL;	
}  // end pop

template<class ItemType>	
ItemType LinkedStack<ItemType>::peek() const throw (std::runtime_error)
{
	if (isEmpty())
		throw std::runtime_error("Stack empty on peek");
   
	// Stack is not empty; return top
	return topPtr->getItem();
}  // end getTop
// End of implementation file.
