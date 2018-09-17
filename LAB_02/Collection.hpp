/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: COLLECTION.HPP
LAST MODIFIED: 09/24/17
FILE CONTENTS: IMPLEMENTATION FILE FOR COLLECTION CLASS
*/

#include <iostream>
#include <stdexcept>

#include "ItemNotFoundException.h"

// @ pre-condition: t_expected_num_items is an int
// @ post-condition: m_items is dynamically allocated to specified size instance variables are initialized properly
template <typename T>
Collection<T>::Collection(int t_expected_num_items) {
  m_size = t_expected_num_items;
  m_items = new T[m_size];
  m_num_items = 0;
}

// @ pre-condition: copy constructor
// @ post-condition: copy of collection instance has been created, member variables assigned
template <typename T>
Collection<T>::Collection(const Collection<T>& original) {
  m_size = original.m_size;
  m_items = new T[m_size];
  m_num_items = 0;
}

// @ pre-condition: none
// @ post-condition: instance of collection has been created, member variables assigned
template <typename T>
Collection<T>::Collection() {
  m_size = 0;
  m_items = nullptr;
  m_num_items = 0;
}
/*
// @ pre-condition:
// @ post-condition:
template <typename T>
Collection<T>::~Collection() {
  delete [] m_items;
}
*/
// @ pre-condition: item has been passed to method
// @ post-condition: item is appended to the collection, collection is resized as necessary
template <typename T>
void Collection<T>::appendItem(T t_item) {
  // checking to see if need to double size of m_items
  if (m_size == m_num_items) {
    m_size = (m_size * 2);
    T* temp = new T[m_size];
    m_num_items = 0;

    // iterating through m_items and adding elements to temp
    for (int i = 0; i < (m_size / 2); i++) {
      temp[i] = m_items[i];
      m_num_items++;
    }

    // adding new element to temp
    temp[m_num_items] = t_item;
    m_num_items++;
    // deleting m_items
    delete [] m_items;
    // pointing m_items to temp
    m_items = temp;
  } else {
    // no need to double size of m_items, so add item to m_items and increase m_num_items by 1
    m_items[m_num_items] = t_item;
    m_num_items++;
  }
}

// @ pre-condition: none
// @ post-condition: number of items in collection is returned
template <typename T>
int Collection<T>::getNumItems() const {
  return m_num_items;
}

// @ pre-condition: index of item in collection is passed to method
// @ post-condition: item in collection at specified index is returned, throws exception if index is not within range 
template <typename T>
T Collection<T>::getItem(int t_item) const throw(ItemNotFoundException) {
  if (t_item > m_num_items) {
    throw ItemNotFoundException("ERROR: Item not found");
  } else {
    return m_items[t_item];
  }
  return m_items[t_item];
}
