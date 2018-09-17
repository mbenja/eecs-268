/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: ROSTER.CPP
LAST MODIFIED: 09/24/17
FILE CONTENTS: IMPLEMENTATION FILE FOR ROSTER CLASS
*/

#include "Roster.h"
#include <iostream>
#include <string>

// @ pre-condition: valid course name, number of students, and array of student ids has been passed into constructor
// @ post-condition: a new instance of roster has been created and member variables assigned
Roster::Roster(std::string t_course_name, int t_num_students, int* t_student_ids) {
  m_course_name = t_course_name;
  m_num_students = t_num_students;
  m_student_id = new int[m_num_students];

  for (int i = 0; i < m_num_students; i++) {
    m_student_id[i] = t_student_ids[i];
  }
}

// @ pre-condition: copy constructor
// @ post-condition: copy of roster object has been created
Roster::Roster(const Roster& original) {
  m_course_name = original.m_course_name;
  m_num_students = original.m_num_students;
  m_student_id = new int[m_num_students];

  for (int i = 0; i < m_num_students; i++) {
    m_student_id[i] = original.m_student_id[i];
  }
}

// @ pre-condition: none
// @ post-condition: a new instance of roster class has been created, member variables assigned 
Roster::Roster() {
  m_course_name = "";
  m_num_students = 0;
  m_student_id = nullptr;
}
/*
// @ pre-condition:
// @ post-condition:
Roster::~Roster() {
  if (m_student_id != nullptr) {
    delete [] m_student_id;
  }
}
*/
// @ pre-condition: request to print roster has been made
// @ post-condition: roster information is printed in an organized manner
void Roster::print() const {
  std::cout << "COURSE NAME: " << m_course_name << std::endl;
  std::cout << "NUMBER OF STUDENTS: " << m_num_students << std::endl;
  std::cout << "STUDENT IDS: ";

  for (int i = 0; i < m_num_students; i++) {
    std::cout << m_student_id[i] << '\t';
  }

  std::cout << std::endl << std::endl;
}
