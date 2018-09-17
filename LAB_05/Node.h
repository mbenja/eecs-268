/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: NODE.H
FILE CONTENTS: HEADER FILE FOR NODE CLASS
*/

#ifndef NODE_H
#define NODE_H

#include "Card.h"

template <typename ItemType>
class Node {
public:
    // @ pre-condition: accepts ItemType as parameter
    // @ post-condition: an instance of node class has been made
    // @ throw: none
    Node(ItemType t_value);

    Node(ItemType t_card_suit, ItemType t_card_value);

    // @ pre-condition: none
    // @ post-condition: an instance of node class has been made
    // @ throw: none
    Node();

    // @ pre-condition: none
    // @ post-condition: all memory allocated for node has been deallocated
    // @ throw: none
    ~Node();

    // @ pre-condition: none
    // @ post-condition: returns Node ItemType pointer of next node
    // @ throw: none
    Node<ItemType>* getNext() const;

    // @ pre-condition: none
    // @ post-condition: returns ItemType stored in node
    // @ throw: none
    ItemType getValue() const;

    // @ pre-condition: accepts node ItemType pointer as parameter
    // @ post-condition: sets parameter as next node
    // @ throw: none
    void setNext(Node<ItemType>* t_next);

    // @ pre-condition: accepts ItemType as parameter
    // @ post-condition: sets parameter as value for node
    // @ throw: none
    void setValue(ItemType t_value);

    // @ pre-condition: none
    // @ post-condition: gets suit and value of card
    // @ throw: none
    std::string getCard() const;

    std::string getCardSuit() const;

    std::string getCardValue() const;

    void setCardSuit(std::string t_suit);

    void setCardValue(std::string t_value);

private:
    ItemType m_value;
    Node<ItemType>* m_next;
    Card* m_card;
};
#include "Node.hpp"
#endif
