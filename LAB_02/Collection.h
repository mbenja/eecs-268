/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
NAME OF FILE: COLLECTION.H
LAST MODIFIED: 09/24/17
FILE CONTENTS: HEADER FILE FOR COLLECTION CLASS
*/

#ifndef COLLECTION_H
#define COLLECTION_H

#include "ItemNotFoundException.h"

template <typename T>
class Collection {
public:
  Collection<T>(int t_expected_num_items);
  Collection<T>(const Collection<T>& original);
  Collection<T>();
  //~Collection<T>();
  void appendItem(T t_item);
  T getItem(int t_item) const throw(ItemNotFoundException);
  int getNumItems() const;

private:
  T* m_items;
  int m_num_items; // number of items stored in m_items
  int m_size; // currently allocated size of m_items array
};
#include "Collection.hpp"
#endif
