/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/31/2017
LAB: 07
FILE NAME: MAIN.CPP
FILE CONTENTS: READS IN COMMAND LINE DATA AND HANDS CONTROL OVER TO EXECUTIVE CLASS
*/

#include "Executive.h"

#include <iostream>

int main(int argc, char* argv[]) {
    bool use_assert = false;

    if (argc < 6) {
        std::cout << "ERROR: Requires input values." << std::endl;
    } else {
        if (argc > 6) {
            use_assert = true;
        }
        Executive exec(argv[1], argv[2], argv[3], argv[4], argv[5], use_assert);
    }

    return(0);
}