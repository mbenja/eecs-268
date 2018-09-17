/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: MAIN.CPP
@ DATE: 09/26/17
@ BRIEF: HANDS CONTROL OVER TO EXECUTIVE CLASS
*/

#include <iostream>
#include "LinkedList.h"
#include "Executive.h"
#include <string>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Invalid number of parameters." << std::endl;
  } else {
    Executive exec(argv[1]);
  }

  /*
  LinkedList<std::string> myLinkedList;

  std::cout << "Testing isEmpty method..." << std::endl;
  if(myLinkedList.isEmpty()) {
    std::cout << "\tLIST IS EMPTY" << std::endl;
  }

  std::cout << "Testing getLength method..." << std::endl;
  std::cout << "\tLENGTH OF LIST IS: " << myLinkedList.getLength() << std::endl;

  std::cout << "Testing insert method..." << std::endl;
  for (int i = 0; i < 5; i++) {
    try {
      std::string input = "";
      int position = 0;
      std::cout << "Enter string for node: ";
      std::cin >> input;
      std::cout << "Enter position for node: ";
      std::cin >> position;
      myLinkedList.insert(position, input);
    } catch (std::runtime_error& err) {
      std::cout << err.what() << std::endl;
    }
  }

  std::cout << "Testing remove method..." << std::endl;
  try {
    int position = 0;
    std::cout << "Enter position to remove: ";
    std::cin >> position;
    myLinkedList.remove(position);
  } catch (std::runtime_error& err) {
    std::cout << err.what() << std::endl;
  }

  std::cout << "Testing set entry method..." << std::endl;
  try {
    int position = 0;
    std::string input = "";
    std::cout << "Enter string for entry: ";
    std::cin >> input;
    std::cout << "Enter position for entry: ";
    std::cin >> position;
    myLinkedList.setEntry(position, input);
  } catch (std::runtime_error& err) {
    std::cout << err.what() << std::endl;
  }

  std::cout << "Testing clear method..." << std::endl;
  myLinkedList.clear();
  */

  return(0);
};
