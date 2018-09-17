/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 09
FILE NAME: MAIN.CPP
FILE CONTENTS: ENSURES PROPER COMMAND LINE ARGUEMENTS AND THEN HANDS OVER CONTROL TO EXECUTIVE CLASS
*/

#include "Executive.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "ERROR: Requires input file." << std::endl;
    } else {
        Executive exec(argv[1]);
    }

    return(0);
}