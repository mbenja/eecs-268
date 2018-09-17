#include <iostream>
#include "Executive.h"

int main(int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "Incorrect number of parameters!" << std::endl;
	} else {
		// creating Executive object
		Executive exec(argv[1]);
		exec.run();
	}

	return(0);
};
