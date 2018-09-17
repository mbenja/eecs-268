/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: CARD.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR CARD CLASS
*/

#include "Card.h"

#include <string>

Card::Card() {
    m_suit = "NO CARD";
    m_value = "NO CARD";
}

Card::Card(std::string t_suit, std::string t_value) {
    m_suit = t_suit;
    m_value = t_value;
}

Card::~Card() {

}

std::string Card::getSuit() const {
    return m_suit;
}

std::string Card::getValue() const {
    return m_value;
}

void Card::setSuit(std::string t_suit) {
    m_suit = t_suit;
}

void Card::setValue(std::string t_value) {
    m_value = t_value;
}

std::string Card::getCard() const {
    std::string card_info = m_suit + "," + m_value;
    return card_info;
}