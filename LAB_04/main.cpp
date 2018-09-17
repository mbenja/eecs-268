/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: MAIN.CPP
FILE CONTENTS: MAIN.CPP FILE CREATES EXECUTIVE INSTANCE AND HANDS OVER CONTROL OF PROGRAM
*/

#include <iostream>
#include "Executive.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Invalid number of parameters." << std::endl;
      } else {
        //std::cout << "CREATING EXEC" << std::endl;
        Executive exec(argv[1]);
      }

    return (0);
};