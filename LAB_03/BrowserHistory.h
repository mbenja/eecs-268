/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: BROWSERHISTORY.H
@ DATE: 09/26/17
@ BRIEF: HEADER FILE FOR BROWSER HISTORY CLASS, NOTES ON METHODS ARE IN INTERFACE FILE
*/

#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include "BrowserHistoryInterface.h"
#include "ListInterface.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class BrowserHistory : public BrowserHistoryInterface {
public:
  BrowserHistory();
  ~BrowserHistory();
  void navigateTo(std::string t_url);
  void forward();
  void back();
  std::string current() const;
  void copyCurrentHistory(LinkedList<std::string>& t_destination);

private:
  ListInterface<std::string>* m_history;
  int m_current = 0;
};
#endif
