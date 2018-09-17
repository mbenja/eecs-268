#include "Executive.h"
#include "Quarterback.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// @ pre-condition: new instance of class Executive is declared and string of file name is passed
// @ post-condition: an instance of Executive class has been made
Executive::Executive(std::string t_file_name) {
  std::ifstream inFile;
  m_quarterbacks = nullptr;
  int rank = 0;
  std::string s_rank = "";
  std::string first_name = "";
  std::string last_name = "";
  std::string team_initials = "";
  int adp = 0;
  std::string s_adp = "";
  int bye_week = 0;
  std::string s_bye_week = "";

  // trying to open file
  inFile.open(t_file_name);

  // getting size to be used for m_quarterbacks
  inFile >> m_size;

  // creating array of quarterback pointers of size m_size
  m_quarterbacks = new Quarterback*[m_size];

  // iterating through m_quarterbacks, reading in quarterback values from file
  // and creating new quarterback instances for each pointer with correct values
  for (int i = 0; i < m_size; i++) {
    std::getline(inFile, s_rank, ',');
    std::getline(inFile, first_name, ' ');
    std::getline(inFile, last_name, ' ');
    std::getline(inFile, team_initials, ',');
    std::getline(inFile, s_bye_week, ',');
    std::getline(inFile, s_adp);

    // converting strings to ints for rank, bye week, and adp
    // makes sure s_bye_week isn't empty before trying to do conversion
    rank = std::stoi(s_rank);
    if (s_bye_week != "") {
      bye_week = std::stoi(s_bye_week);
    }
    adp = std::stoi(s_adp);

    m_quarterbacks[i] = new Quarterback(rank, first_name, last_name,
      team_initials, bye_week, adp);
  }
};

// @ pre-condition:
// @ post-condition: heap allocated memory is deallocated to prevent memory leaks
Executive::~Executive() {
  for (int i = 0; i < m_size; i++) {
    delete m_quarterbacks[i];
  }
  delete [] m_quarterbacks;
}

// @ pre-condition: instance of Executive class exists, and m_quarterbacks is not empty or null
// @ post-condition: menu is printed and user interface begins
void Executive::run() {
  presentMenu();
};

// @ pre-condition:
// @ post-condition:
void Executive::presentMenu() {
  int choice = 0;

  std::cout << "1. Print entire list of quarterbacks" << std::endl;
  std::cout << "2. Print all quarterbacks on a particular team" << std::endl;
  std::cout << "3. Print all quarterbacks between two ranks" << std::endl;
  std::cout << "4. Print all drafted quarterbacks" << std::endl;
  std::cout << "5. Export drafted quarterbacks as txt file" << std::endl;
  std::cout << "6. Exit program" << std::endl;
  std::cout << "Choice: ";
  std::cin >> choice;
  std::cout << std::endl;

  // checking for cin fail or intput out of range of options, reacts appropriately
  if (std::cin.fail() || choice < 1 || choice > 6) {
    std::cout << "ERROR: Invalid input. Please input one of the options." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    presentMenu();
  } else if (choice == 1) {
    printAll();
  } else if (choice == 2) {
    printTeam();
  } else if (choice ==3) {
    printBetweenRanks();
  } else if (choice == 4) {
    printDrafted();
  } else if (choice == 5) {
    exportAll();
  } else if (choice == 6) {
    std::cout << "Goodbye!" << std::endl;
  }
};

// @ pre-condition: user has input "1" as choice in presentMenu method
// @ post-condition: attributes of each Quarterback in m_quarterbacks is printed, presentMenu() is called again
void Executive::printAll() {
  int colwidth = 10;
  
  // column headers
  std::cout << std::setw(12) << std::left << "RANK";
  std::cout << std::setw(25) << std::left << "NAME";
  std::cout << std::setw(10) << std::left << "TEAM";
  std::cout << std::setw(10) << std::left << "BYE";
  std::cout << std::setw(10) << std::left << "ADP" << std::endl;

  // determines how wide to make the column for m_rank
  for (int i = 0; i < m_size; i++) {
    if (i >= 9) {
      colwidth = 9;
    }

    // quarterback attributes being printed in correct format
    std::cout << m_quarterbacks[i]->getRank() << '.' << std::setw(colwidth) << ' ';
    std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getFirstName();
    std::cout << std::setw(15) << std::left << m_quarterbacks[i]->getLastName();
    std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getTeamInitials();
    std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getByeWeek();
    std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getAdp() << std::endl;
  }

  // presenting menu
  presentMenu();
}

// @ pre-condition: user has input "2" as choice in presentMenu method
// @ post-condition: attributes of every quarterback on a user specified team is printed, presentMenu() is called again
void Executive::printTeam() {
  std::string team_initials = "";
  bool found_team = false;

  std::cout << "Enter team initials: ";
  std::cin >> team_initials;
  std::cout << std::endl;

  // iterating through m_quarterbacks and checking team initials of each quarterback to see if team is in array
  for (int i = 0; i < m_size; i++) {
    if (m_quarterbacks[i]->getTeamInitials() == team_initials) {
      found_team = true;
      break;
    }
  }

  // checks for invalid input or team initials not found, reacts appropriately
  if (std::cin.fail() || found_team == false) {
    std::cout << "ERROR: Invalid team initials. Please input valid team initials." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    printTeam();
  } else {
    int colwidth = 10;
    
    // column headers
    std::cout << std::setw(12) << std::left << "RANK";
    std::cout << std::setw(25) << std::left << "NAME";
    std::cout << std::setw(10) << std::left << "TEAM";
    std::cout << std::setw(10) << std::left << "BYE";
    std::cout << std::setw(10) << std::left << "ADP" << std::endl;
  
    // determines how wide to make the column for m_rank
    for (int i = 0; i < m_size; i++) {
      if (i >= 9) {
        colwidth = 9;
      }
  
      // quarterback attributes of user specified team being printed in correct format
      if (m_quarterbacks[i]->getTeamInitials() == team_initials) {
        std::cout << m_quarterbacks[i]->getRank() << '.' << std::setw(colwidth) << ' ';
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getFirstName();
        std::cout << std::setw(15) << std::left << m_quarterbacks[i]->getLastName();
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getTeamInitials();
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getByeWeek();
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getAdp() << std::endl;
      }
    }
  }
  // calling menu
  presentMenu();
}

// @ pre-condition: user has input "3" as choice in presentMenu method
// @ post-conidition: all quarterbacks within a range will have been printed
void Executive::printBetweenRanks() {
  int col_width = 10;
  int lower_bound = 0;
  int upper_bound = 0;

  // getting lower_bound
  std::cout << "Enter lower rank: ";
  std::cin >> lower_bound;

  // checking for invalid input
  if (std::cin.fail() || lower_bound < 1 || lower_bound > (m_size - 1)) {
    std::cout << "ERROR: Invalid lower rank. Value must be greater than 0 and less than " << (m_size - 1) << std::endl;
    lower_bound = 0;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    printBetweenRanks();
  } else {
    // getting upper_bound
    std::cout << "Enter upper rank: ";
    std::cin >> upper_bound;

    // checking for invalid input
    if (std::cin.fail() || upper_bound < lower_bound) {
      std::cout << "ERROR: Invalid upper rank. Value must be less than lower rank." << std::endl;
      upper_bound = 0;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      printBetweenRanks();
    }

    // column headers
    std::cout << std::setw(12) << std::left << "RANK";
    std::cout << std::setw(25) << std::left << "NAME";
    std::cout << std::setw(10) << std::left << "TEAM";
    std::cout << std::setw(10) << std::left << "BYE";
    std::cout << std::setw(10) << std::left << "ADP" << std::endl;

    // determines how wide to make the column for m_rank
    for (int i = 0; i < m_size; i++) {
      if (i >= 9) {
        col_width = 9;
      }

      // quarterback attributes of user specified range being printed in correct format
      if (m_quarterbacks[i]->getRank() >= lower_bound && m_quarterbacks[i]->getRank() <= upper_bound) {
        std::cout << m_quarterbacks[i]->getRank() << '.' << std::setw(col_width) << ' ';
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getFirstName();
        std::cout << std::setw(15) << std::left << m_quarterbacks[i]->getLastName();
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getTeamInitials();
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getByeWeek();
        std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getAdp() << std::endl;
      }
    }
  }

  // calling menu
  presentMenu();
}

// @ pre-condition: user has input "4" as choice in presentMenu method
// @ post-coniditon: all drafted quarterbacks will have been printed, with new column of adp minus rank
void Executive::printDrafted() {
  int colwidth = 10;
  
  // column headers
  std::cout << std::setw(12) << std::left << "RANK";
  std::cout << std::setw(25) << std::left << "NAME";
  std::cout << std::setw(10) << std::left << "TEAM";
  std::cout << std::setw(10) << std::left << "BYE";
  std::cout << std::setw(10) << std::left << "ADP";
  std::cout << std::setw(10) << std::left << "RANK VS. ADP" << std::endl;

  // determines how wide to make the column for m_rank
  for (int i = 0; i < m_size; i++) {
    if (i >= 9) {
      colwidth = 9;
    }

    // quarterback attributes being printed in correct format
    if (m_quarterbacks[i]->getAdp() != -1) {
      std::cout << m_quarterbacks[i]->getRank() << '.' << std::setw(colwidth) << ' ';
      std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getFirstName();
      std::cout << std::setw(15) << std::left << m_quarterbacks[i]->getLastName();
      std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getTeamInitials();
      std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getByeWeek();
      std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getAdp();
      std::cout << std::setw(10) << std::left << m_quarterbacks[i]->getAdp() - m_quarterbacks[i]->getRank() << std::endl;
    }
  }

  // calling menu
  presentMenu();
}

// @ pre-condition: user has input "5" as choice in presentMenu method
// @ post-condition: entire m_quaterbacks array will be written to txt file with new column of adp minus rank
void Executive::exportAll() {
  std::string file_name = "";
  std::string file_contents = "";
  std::ofstream outFile;

  // getting file_name
  std::cout << "Enter file name: ";
  std::cin >> file_name;

  // checking for invalid file_name
  if (std::cin.fail()) {
    std::cout << "ERROR: Invalid file name." << std::endl;
    std::cin.fail();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    exportAll();
  }

  for (int i = 0; i < m_size; i++) {
    file_contents += std::to_string(m_quarterbacks[i]->getRank());
    file_contents += ',';
    file_contents += m_quarterbacks[i]->getFirstName();
    file_contents += ' ';
    file_contents += m_quarterbacks[i]->getLastName();
    file_contents += ',';
    file_contents += std::to_string(m_quarterbacks[i]->getByeWeek());
    file_contents += ',';
    file_contents += std::to_string(m_quarterbacks[i]->getAdp());
    if (i < (m_size -1)) {
      file_contents += '\n';
    }
  }

  // writing to file
  outFile.open(file_name);
  outFile << file_contents;
  outFile.close();

  std::cout << "Export finished" << std::endl;

  // calling menu
  presentMenu();
}

// @ pre-condition: user has selected 6 at menu
// @ post-condition: 
void Executive::endProgram() {
  std::cout << "Goodbye!" << std::endl;
}
