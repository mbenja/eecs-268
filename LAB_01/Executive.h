#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include "Quarterback.h"

class Executive {
private:
  Quarterback** m_quarterbacks;
  int m_size;

public:
  Executive(std::string t_file_name);
  ~Executive();
  void run();
  void presentMenu();
  void printAll();
  void printTeam();
  void printBetweenRanks();
  void printDrafted();
  void exportAll();
  void endProgram();
};
#endif
