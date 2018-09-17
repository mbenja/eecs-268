/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: QUEUE.H
FILE CONTENTS: HEADER FILE FOR QUEUE CLASS
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"

#include <stdexcept>

template <typename ItemType>
class Queue : public QueueInterface<ItemType> {
public:
    // @ pre-condition: none
    // @ post-condition: an instance of queue class has been made
    // @ throw: none
    Queue();

    // @ pre-condition: none
    // @ post-condition: all memory allocated for the queue has been deallocated
    // @ throw: none
    ~Queue();

    // @ pre-condition: none
    // @ post-condition: returns true if queue is empty, false otherwise
    // @ throw: none
    bool isEmpty() const;

    // @ pre-condition: accepts ItemType as element to be added to queue
    // @ post-condition: an instance of card class has been made
    // @ throw: throws runtime_error if no memory available for new item
    void enqueue(const ItemType &t_new_entry) throw (std::runtime_error);

    // @ pre-condition: none
    // @ post-condition: the item at the front of the queue has been removed from the queue
    // @ throw: throws runtime_error if queue is empty
    void dequeue() throw (std::runtime_error);

    // @ pre-condition: none
    // @ post-condition: returns ItemType at front of queue and queue remains unchanged
    // @ throw: throws runtime_error if queue is empty
    ItemType peekFront() const throw (std::runtime_error);

    // @ pre-condition: none
    // @ post-condition: returns size of queue
    // @ throw: none
    int getSize() const;

    // @ pre-condition: none
    // @ post-condition: prints out contents of queue from back to front
    // @ throw: none
    void printQueue() const;
private:
    Node<ItemType>* m_front;
    Node<ItemType>* m_back;
    int m_size;
};
#include "Queue.hpp"
#endif