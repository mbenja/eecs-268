/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 08
FILE NAME: EXECUTIVE.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR EXECUTIVE.H
*/

#include "Executive.h"
#include "BinaryNodeTree.h"
#include "LinkedStack.h"

#include <string>
#include <fstream>
#include <stdexcept>

Executive::Executive(std::string t_file_name) {
    std::fstream inFile;
    std::string t_input;
    BinaryNodeTree<std::string>* t = nullptr;
    BinaryNodeTree<std::string>* t1 = nullptr;
    BinaryNodeTree<std::string>* t2 = nullptr;

    inFile.open(t_file_name);

    while (inFile.peek() != EOF) {
        inFile >> t_input;
        if (inFile.peek() == EOF) {
            break;
        }

        // if operand, push onto stack
        if (!isOperator(t_input)) {
            t = new BinaryNodeTree<std::string>(t_input);
            m_stack.push(t);
        } else {
            // is operator

            //t = new BinaryNodeTree<std::string>(t_input);

            // try to pop top two nodes
            try {
                t1 = m_stack.peek(); // store top 
                m_stack.pop(); // remove top
            } catch (std::runtime_error &err) {
                std::cout << err.what() << std::endl;
                std::cout << "ERROR: NOT ENOUGH OPERANDS" << std::endl;
            }

            try {
                t2 = m_stack.peek(); // store top 
                m_stack.pop(); // remove top
            } catch (std::runtime_error &err) {
                std::cout << err.what() << std::endl;
                std::cout << "ERROR: NOT ENOUGH OPERANDS" << std::endl;
            }

            // make them children
            t = new BinaryNodeTree<std::string>(t_input, t2, t1);
            // add new tree to stack
            m_stack.push(t);
        }
    }

    // now only one tree is in stack
    t = m_stack.peek();
    m_stack.pop();

    // checking to see if there are excess items on the stack
    try {
        t1 = m_stack.peek();
        std::cout << "ERROR: EXCESS ITEMS ON THE STACK AFTER RUNNING THROUGH INPUT." << std::endl;
    } catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
    }

    // traverse tree
    std::cout << "Postorder traversal - should echo input:" << std::endl << '\t';
    t->printTree("postorder");
    std::cout << std::endl << std::endl;

    std::cout << "Inorder traversal - should show equivalent infix sans parentheses:" << std::endl << '\t';
    t->printTree("inorder");
    std::cout << std::endl << std::endl;

    std::cout << "Preorder traversal - should shoq equivalent prefix:" << std::endl << '\t';
    t->printTree("preorder");
    std::cout << std::endl;
}

Executive::~Executive() {

}

bool Executive::isOperator(std::string t_char) {
    if (t_char == "+" || t_char == "-" || t_char == "*" || t_char == "/" || t_char == "=") {
        return true;
    } else {
        return false;
    }
}