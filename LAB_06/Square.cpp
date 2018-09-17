/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 06
FILE NAME: SQUARE.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR SQUARE CLASS
*/

#include "Square.h"

#include <string>

Square::Square() {
    m_value = "";
    m_fixed = true;
}

Square::Square(std::string t_value, bool t_is_fixed) {
    m_value = t_value;
    m_fixed = t_is_fixed;
}

Square::~Square() {

}

void Square::setValue(std::string t_value) {
    m_value = t_value;
}

std::string Square::getValue() {
    return m_value;
}

bool Square::getIsFixed() {
    return m_fixed;
}