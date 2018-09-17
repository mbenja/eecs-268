/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: BROWSERHISTORY.CPP
@ DATE: 09/26/17
@ BRIEF: IMPLEMENTATION FILE FOR BROWSER HISTORY CLASS
*/

#include "BrowserHistory.h"
#include "LinkedList.h"

BrowserHistory::BrowserHistory() {
  m_history = new LinkedList<std::string>();
  m_current = 0;
}

BrowserHistory::~BrowserHistory() {

}

void BrowserHistory::navigateTo(std::string t_url) {
    m_history->insert(m_history->getLength(), t_url);
    m_current = m_history->getLength();

    for (int i = 0; i < m_history->getLength(); i++) {
        std::cout << m_history->getEntry(i) << std::endl;
    }
}

void BrowserHistory::forward() {
  if (m_current != m_history->getLength()) {
    m_current++;
  }
}

void BrowserHistory::back() {
  if (m_current != 1) {
    m_current--;
  }
}

std::string BrowserHistory::current() const {
  return m_history->getEntry(m_current);
}

void BrowserHistory::copyCurrentHistory(LinkedList<std::string>& t_destination) {
  for (int i = 0; i < m_history->getLength(); i++) {
    t_destination.insert(i, m_history->getEntry(i));
  }
}
