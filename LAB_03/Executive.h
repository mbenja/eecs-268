/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: EXECUTIVE.H
@ DATE: 09/26/17
@ BRIEF: HEADER FILE FOR EXECUTIVE CLASS
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "BrowserHistory.h"
#include <string>

class Executive {
public:
  Executive(std::string t_file_name);
  ~Executive();
private:
  BrowserHistory* m_browser;
};
#endif
