/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: MAIN.CPP
FILE CONTENTS: MAIN.CPP CHECKS TO MAKE SURE IT RECEIVES FILE NAME, THEN HANDS FILE AND CONTROL OVER TO EXECUTIVE CLASS
*/

#include "Executive.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "ERROR: Requires input file." << std::endl;
    } else {
        Executive exec(argv[1]);
    }

    return(0);
}