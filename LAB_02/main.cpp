/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: MAIN.CPP
LAST MODIFIED: 09/24/17
FILE CONTENTS: MAIN.CPP FOR PROJECT, HANDS CONTROL OVER TO EXECUTIVE CLASS
*/

#include <iostream>
#include "Executive.h"
#include "Collection.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
  std::cout << "Incorrect number of parameters." << std::endl;
  } else {
    Executive exec(argv[1]);
    exec.run();
  }

  return(0);
}
