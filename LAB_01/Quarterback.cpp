#include "Quarterback.h"
#include <iostream>

// @ pre-condition:
// @ post-condition: instance of Quarterback class is created, values set to "" or 0
Quarterback::Quarterback() {
  m_rank = 0;
  m_first_name = "";
  m_last_name = "";
  m_team_initials = "";
  m_bye_week = 0;
  m_adp = 0;
}

// @ pre-condition:
// @ post-condition: instance of Quarterback class is created, values set to "" or 0
Quarterback::Quarterback(int t_rank, std::string t_first_name, std::string t_last_name,
std::string t_team_initials, int t_bye_week, int t_adp) {
  m_rank = t_rank;
  m_first_name = t_first_name;
  m_last_name = t_last_name;
  m_team_initials = t_team_initials;
  m_bye_week = t_bye_week;
  m_adp = t_adp;
};

// @ pre-condition:
// @ post-condition:
void Quarterback::setRank(int t_rank) {
  m_rank = t_rank;
};

// @ pre-condition:
// @ post-condition:
void Quarterback::setFirstName(std::string t_first_name) {
  m_first_name = t_first_name;
}

// @ pre-condition:
// @ post-condition:
void Quarterback::setLastName(std::string t_last_name) {
  m_last_name = t_last_name;
}

// @ pre-condition:
// @ post-condition:
void Quarterback::setTeamInitials(std::string t_team_initials) {
  m_team_initials = t_team_initials;
}

// @ pre-condition:
// @ post-condition:
void Quarterback::setAdp(int t_adp) {
  m_adp = t_adp;
}

// @ pre-condition:
// @ post-condition:
void Quarterback::setByeWeek(int t_bye_week) {
  m_bye_week = t_bye_week;
}

// @ pre-condition:
// @ post-condition:
int Quarterback::getRank() const {
  return m_rank;
}

// @ pre-condition:
// @ post-condition:
std::string Quarterback::getFirstName() const {
  return m_first_name;
}

// @ pre-condition:
// @ post-condition:
std::string Quarterback::getLastName() const {
  return m_last_name;
}

// @ pre-condition:
// @ post-condition:
std::string Quarterback::getTeamInitials() const {
  return m_team_initials;
}

// @ pre-condition:
// @ post-condition:
int Quarterback::getAdp() const {
  return m_adp;
}

// @ pre-condition:
// @ post-condition:
int Quarterback::getByeWeek() const {
  return m_bye_week;
}
