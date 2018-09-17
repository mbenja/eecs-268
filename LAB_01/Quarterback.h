#ifndef QUARTERBACK_H
#define QUARTERBACK_H

#include <iostream>
#include <string>

class Quarterback {
private:
  int m_rank;
  std::string m_first_name;
  std::string m_last_name;
  std::string m_team_initials;
  int m_adp;
  int m_bye_week;

public:
  Quarterback();
  Quarterback(int t_rank, std::string t_first_name, std::string t_last_name,
  std::string t_team_initials, int t_bye_week, int t_adp);

  int getRank() const;
  void setRank(int t_rank);
  void setFirstName(std::string t_first_name);
  void setLastName(std::string t_last_name);
  void setTeamInitials(std::string t_team_initials);
  void setAdp(int t_adp);
  void setByeWeek(int t_bye_week);
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getTeamInitials() const;
  int getAdp() const;
  int getByeWeek() const;
};
#endif
