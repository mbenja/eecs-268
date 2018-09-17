/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: ITEMNOTFOUNDEXCEPTION.H
LAST MODIFIED: 09/24/17
FILE CONTENTS: HEADER FILE FOR ITEMNOTFOUND CLASS
*/

#ifndef ITEMNOTFOUNDEXCEPTION_H
#define ITEMNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

class ItemNotFoundException: public std::runtime_error {
public:
    ItemNotFoundException(std::string err): std::runtime_error(err){};
private:
    std::string m_err;
};
#endif