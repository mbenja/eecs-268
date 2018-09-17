/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: EXECUTIVE.CPP
LAST MODIFIED: 09/24/17
FILE CONTENTS: IMPLEMENTATION FILE FOR EXECUTIVE CLASS
*/

#include "Executive.h"
#include "Collection.h"
#include "Roster.h"

#include <iostream>
#include <fstream>
#include <string>

// @ pre-condition: file name is passed into constructor
// @ post-condition: new executive instance is created and file is read
Executive::Executive(std::string t_file_name) {
  std::ifstream inFile;
  int expected_num = 0;
  std::string current_course_name = "";
  int current_num_students = 0;
  int* current_student_ids = nullptr;

  // opening file, getting expected number of items in m_collection
  inFile.open(t_file_name);
  inFile >> expected_num;

  // creating collection with specified size
  m_collection = Collection<Roster>(expected_num);

  // looping while there is still data to read
  while (inFile >> current_course_name) {
    inFile >> current_num_students;
    // creating array of appropriate size for student ids
    current_student_ids = new int[current_num_students];

    for (int i = 0; i < current_num_students; i++) {
      inFile >> current_student_ids[i];
    }
    // creating roster object with read in data
    Roster current_roster = Roster(current_course_name, current_num_students, current_student_ids);
    //current_roster.print();
    // appending roster object to m_collection
    m_collection.appendItem(current_roster);

    // deleting every "new"
    delete [] current_student_ids;
  }
}

// @ pre-condition: executive instance exists
// @ post-condition: menu is presented
void Executive::run() {
  menu();
}

// @ pre-condition: none 
// @ post-condition: menu options are printed and appropriate methods are called based on user input
void Executive::menu() {
  std::string input = "";
  int index = 0;

  std::cout << "(1) Print All" << std::endl;
  std::cout << "(2) Print X" << std::endl;
  std::cout << "(3) Quit" << std::endl;
  std::cin >> input;

  if (input == "1") {
    printAll();
  } else if (input == "2") {
    std::cout << "Input index: ";
    std::cin >> index;
    printIndex(index);
  }
}

// @ pre-condition: user has selected to print all
// @ post-condition: all items in the collection are printed
void Executive::printAll() {
  for (int i = 0; i < m_collection.getNumItems(); i++) {
    m_collection.getItem(i).print();
  }
  menu();
}

// @ pre-condition: user has selected to print an index, and index is within range of array
// @ post-condition: specific index of collection is printed
void Executive::printIndex(int t_index) {
  m_collection.getItem(t_index).print();
  menu();
}
