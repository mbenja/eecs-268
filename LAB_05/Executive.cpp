/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/10/2017
LAB: 05
FILE NAME: EXECUTIVE.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR EXECUTIVE CLASS
*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "Executive.h"
#include "Node.h"

Executive::Executive(std::string t_file_name) {
    std::ifstream inFile;
    std::string command = "";
    std::string player_name = "";
    std::string status_type = "";
    bool dealt = false;
    bool closed = false;


    inFile.open(t_file_name);

    while (inFile.peek() != EOF || closed == false) {
        inFile >> command;

        if (command == "WAIT") {
            inFile >> player_name;

            m_waiting_list.enqueue(player_name);
        } else if (command == "STATUS") {
            inFile >> status_type;

            if (status_type == "WAIT_LIST") {
                m_waiting_list.printQueue();
            }  else if (status_type == "TABLE") {
                m_table.printLinkedList();
            }
        } else if (command == "SEATING") {
            // peek front and dequeue appropriate number of players
            int stop_num = m_table.getLength();
            for (int i = 0; i < (4 - stop_num); i++) {
                try {
                    std::string to_add = m_waiting_list.peekFront();
                    m_table.insert(m_table.getLength(), to_add);
                    m_waiting_list.dequeue();
                } catch (std::runtime_error &err) {
                    std::cout << err.what() << std::endl;
                }
            }
        } else if (command == "DEAL") {
            if (m_table.getLength() != 4) {
                std::cout << "DEAL ERROR: Table is not full, cards will not be dealt." << std::endl;
            } else {
                // emptying deck if necessary before beginning shuffle
                if (!(m_deck.isEmpty())) {
                    while (!(m_deck.isEmpty())) {
                        try {
                            m_deck.pop();
                        } catch (std::runtime_error &err) {
                            std::cout << err.what() << std::endl;
                        }
                    }
                }

                if (m_deck.isEmpty()) {
                    std::string t_suit = "";
                    std::string t_value = "";
                    for (int i = 0; i < 52; i++) {
                        int i_suit = (rand() % 4) + 1;
                        int i_value = (rand() % 13) + 1;

                        if (i_suit == 1) {
                            t_suit = "HEARTS";
                        } else if (i_suit == 2) {
                            t_suit = "CLUBS";
                        } else if (i_suit == 3) {
                            t_suit = "SPADES";
                        } else if (i_suit == 4) {
                            t_suit = "DIAMONDS";
                        }

                        t_value = std::to_string(i_value);

                        m_deck.push(t_suit, t_value);
                    }
                }

                // dealing cards
                for (int i = 0; i < m_table.getLength(); i++) {
                    std::string t_suit = m_deck.peekSuit();
                    std::string t_value = m_deck.peekValue();
                    try {
                        m_deck.pop();
                    } catch (std::runtime_error &err) {
                        std::cout << err.what() << std::endl;
                    }

                    m_table.dealCards(t_suit, t_value, i);
                }
                
                dealt = true;
            }
        } else if (command == "SHOWDOWN") {
            if (dealt) {
                int to_remove = m_table.showdown();
                try {
                    m_table.remove(to_remove);
                    dealt = false;
                } catch (std::runtime_error &err) {
                    std::cout << err.what() << std::endl;
                }
            } else {
                std::cout << "SHOWDOWN ERROR: Card must be dealt before attempting showdown." << std::endl;
            }
        } else if (command == "CLOSE") {
            m_waiting_list.printQueue();
            m_table.printLinkedList();
            closed = true;
        }
    }

    inFile.close();
}

Executive::~Executive() {
    
}