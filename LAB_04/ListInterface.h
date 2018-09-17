/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/3/2017
LAB: 04
FILE NAME: LISTINTERFACE.H
FILE CONTENTS: HEADER FILE FOR LIST INTERFACE
*/

#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

#include <stdexcept>

template <typename ItemType>
class ListInterface {
public:
  /** Virtual destructor allows concrete implementations to clean up
       heap memory when the List is discarded. */
  virtual ~ListInterface() {}
  /** Sees whether this list is empty.
    @return True if the list is empty; otherwise returns false. */
  virtual bool isEmpty() const = 0;
  /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
  virtual int getLength() const = 0;
  /** Inserts an entry into this list at a given position.
    @pre  None.
    @post  If 1 <= position <= getLength() + 1 and the insertion is
       successful, newEntry is at the given position in the list, and
       other entries are renumbered accordingly.
    @param newPosition  The list position at which to insert newEntry.
    @param newEntry  The entry to insert into the list.
    @throw  PrecondViolatedExcep if insertion cannot be performed. */
  virtual void insert(int t_new_position, const ItemType& t_new_entry) throw(std::runtime_error) = 0;
    /** Gets the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The desired entry has been returned.
    @param position  The list position of the desired entry.
    @throw  PrecondViolatedExcep if no such entry exists. */
  virtual ItemType getEntry(int t_position) throw(std::runtime_error) = 0;
    /** Removes the entry at a given position from this list.
    @pre  None.
    @post  If 1 <= position <= getLength() and the removal is successful,
       the entry at the given position in the list is removed, and other
       items are renumbered accordingly.
    @param position  The list position of the entry to remove.
    @throw  PrecondViolatedExcep if removal cannot be performed. */
  virtual void remove(int t_position) throw(std::runtime_error) = 0;
  /** Removes all entries from this list.
    @post  List contains no entries and the count of items is 0. */
  virtual void clear() = 0;
  /** Replaces the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The entry at the given position is newEntry.
    @param position  The list position of the entry to replace.
    @param newEntry  The replacement entry.
    @throw  PrecondViolatedExcep if no such entry exists. */
  //virtual void setEntry(int t_position, const ItemType& t_new_entry) throw(std::runtime_error) = 0;
};
#endif
