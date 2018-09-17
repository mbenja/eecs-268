/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: EXECUTIVE.H
LAST MODIFIED: 09/24/17
FILE CONTENTS: HEADER FILE FOR EXECUTIVE CLASS
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Collection.h"
#include "Roster.h"
#include <string>

class Executive {
public:
  Executive(std::string t_file_name);
  void run();
  void menu();
  void printAll();
  void printIndex(int t_index);
private:
  Collection<Roster> m_collection;
};
#endif
