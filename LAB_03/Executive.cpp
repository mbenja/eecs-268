/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: EXECUTIVE.CPP
@ DATE: 09/26/17
@ BRIEF: IMPLEMENTATION FILE FOR EXECUTIVE CLASS
*/

#include "Executive.h"
#include "LinkedList.h"
#include <string>
#include <fstream>

// @ pre-condition:
// @ post-condition:
Executive::Executive(std::string t_file_name) {
  std::ifstream inFile;
  std::string command = "";
  std::string url = "";

  m_browser = new BrowserHistory();

  inFile.open(t_file_name);

  while(inFile.peek() != EOF) {
    inFile >> command;

    if (command == "NAVIGATE") {
      inFile >> url;
      m_browser->navigateTo(url);
    } else if (command == "HISTORY") {
      LinkedList<std::string> temp;
      m_browser->copyCurrentHistory(temp);

      std::cout << "OLDEST" << std::endl;
      std::cout << "============" << std::endl;

      for (int i = 0; i < temp.getLength(); i++) {
        std::cout << temp.getEntry(i);

        if (m_browser->current() == temp.getEntry(i)) {
          std::cout << "\t<== current";
        }

        std::cout << std::endl;
      }

      std::cout << "============" << std::endl;
      std::cout << "NEWEST" << std::endl;

    } else if (command == "BACK") {
      m_browser->back();
    } else if (command == "FORWARD") {
      m_browser->forward();
    }
  }
}

Executive::~Executive() {

}
