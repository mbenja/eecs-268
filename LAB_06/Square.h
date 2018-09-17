/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 06
FILE NAME: SQUARE.H
FILE CONTENTS: HEADER FILE FOR SQUARE CLASS
*/

#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square {
public:
    // @ pre-condition: none
    // @ post-condition: m_value, m_fixed are initialized
    // @ throws: none
    Square();

    // @ pre-condition: expects string and bool as parameters
    // @ post-condition: m_value, m_fixed are assigned
    // @ throws: none
    Square(std::string t_value, bool t_is_fixed);

    // @ pre-condition: none
    // @ post-condition: 
    // @ throws: none
    ~Square();

    // @ pre-condition: expects string as parameter
    // @ post-condition: sets parameter as m_value
    // @ throws: none
    void setValue(std::string t_value);

    // @ pre-condition: none
    // @ post-condition: returns m_value
    // @ throws: none
    std::string getValue();

    // @ pre-condition: none
    // @ post-condition: returns m_fixed value
    // @ throws: none
    bool getIsFixed();

private:
    std::string m_value;
    bool m_fixed;
};
#endif