/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: ROSTER.H
LAST MODIFIED: 09/24/17
FILE CONTENTS: HEADER FILE FOR ROSTER CLASS
*/

#ifndef ROSTER_H
#define ROSTER_H

#include <string>

class Roster {
public:
  Roster(std::string t_course_name, int t_num_students, int* t_student_ids);
  Roster(const Roster& original);
  Roster();
  //~Roster();
  void print() const;

private:
  std::string m_course_name;
  int m_num_students;
  int* m_student_id;
};
#endif
