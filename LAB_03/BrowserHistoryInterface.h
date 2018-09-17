/*
@ AUTHOR: BENJAMIN STREIT 2853772
@ FILE: BROWSERHISTORYINTERFACE.H
@ DATE: 09/26/17
@ BRIEF: HEADER FILE FOR BROWSERHISTORY INTERFACE
*/

#ifndef BROWSER_HISTORY_INTERFACE_H
#define BROWSER_HISTORY_INTERFACE_H

#include <string>
#include "LinkedList.h"

class BrowserHistoryInterface {
public:
    /**
  * @post All memory allocated by the implementing class should be freed. 
  *       This, as with all virtual destrucors, is an empty definition since we
  *       have no knowledge of specific implementation details.
  */
    virtual void navigateTo(std::string t_url) = 0;
    /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
    virtual ~BrowserHistoryInterface(){};
    /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
    virtual void forward() = 0;
    /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL 
  */
    virtual void back() = 0;
    /**
  * @return the current URL 
  */
    virtual std::string current() const = 0;
    /**
  * @pre The list being passed in is empty
  * @post The current browser history is copied into the given list  
  * @param destination, an empty list of strings
  */
    virtual void copyCurrentHistory(LinkedList<std::string>& t_destination) = 0;
};
#endif
