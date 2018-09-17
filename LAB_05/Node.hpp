/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: NODE.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR NODE CLASS
*/

template <typename ItemType>
Node<ItemType>::Node(ItemType t_value) {
  m_value = t_value;
  m_next = nullptr;
  m_card = new Card();
};

template <typename ItemType>
Node<ItemType>::Node(ItemType t_card_suit, ItemType t_card_value) {
  m_next = nullptr;
  m_card = new Card();
  m_card->setSuit(t_card_suit);
  m_card->setValue(t_card_value);
}

template <typename ItemType>
Node<ItemType>::Node() {
  m_next = nullptr;
}

template <typename ItemType>
Node<ItemType>::~Node() {
  delete m_card;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
  return m_next;
}

template <typename ItemType>
ItemType Node<ItemType>::getValue() const {
  return m_value;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* t_next) {
  m_next = t_next;
}

template <typename ItemType>
void Node<ItemType>::setValue(ItemType t_value) {
  m_value = t_value;
}

template <typename ItemType>
std::string Node<ItemType>::getCard() const {
  std::string t_suit = m_card->getSuit();
  std::string t_value = m_card->getValue();
  std::string card_info = "CARD SUIT: " + t_suit + "\tCARD VALUE: " + t_value;
  return card_info;
}

template <typename ItemType>
std::string Node<ItemType>::getCardSuit() const {
  return m_card->getSuit();
}

template <typename ItemType>
std::string Node<ItemType>::getCardValue() const {
  return m_card->getValue();
}

template <typename ItemType>
void Node<ItemType>::setCardSuit(std::string t_suit) {
  m_card->setSuit(t_suit);
}

template <typename ItemType>
void Node<ItemType>::setCardValue(std::string t_value) {
  m_card->setValue(t_value);
}
