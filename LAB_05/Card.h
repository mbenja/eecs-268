/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: CARD.H
FILE CONTENTS: HEADER FILE FOR CARD CLASS
*/

#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
public:
    // @ pre-condition: none
    // @ post-condition: an instance of card class has been made
    // @ throw: none
    Card();

    // @ pre-condition: none
    // @ post-condition: an instance of card class has been made
    // @ throw: none
    Card(std::string t_suit, std::string t_value);

    // @ pre-condition: instance of card class exists
    // @ post-condition: memory for instance of card has been deallocated
    // @ throw: none
    ~Card();

    // @ pre-condition: none
    // @ post-condition: returns string of suit for card
    // @ throw: none
    std::string getSuit() const;

    // @ pre-condition: none
    // @ post-condition: returns string of value for card
    // @ throw: none
    std::string getValue() const;

    // @ pre-condition: expects string as parameter for suit of card
    // @ post-condition: sets parameter as suit of card
    // @ throw: none
    void setSuit(std::string t_suit);

    // @ pre-condition: expects string as parameter for value of card
    // @ post-condition: sets parameter as value of card
    // @ throw: none
    void setValue(std::string t_value);

    // @ pre-condition: none
    // @ post-condition: returns suit and value of card
    // @ throw: none
    std::string getCard() const;

private:
    std::string m_suit;
    std::string m_value;
};
#endif