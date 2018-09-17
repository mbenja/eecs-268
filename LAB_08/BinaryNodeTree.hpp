//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// This file is a subset of Carrano's file for Lab 8

// PARTIALLY COMPLETE.

/** @file BinaryTree.cpp */

/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 08
FILE NAME: BINARYNODETREE.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR BINARYNODETREE.H
*/


#include "BinaryNode.h" 
#include <iostream>
#include <stdexcept>

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->getLeftChildPtr()); 
        destroyTree(subTreePtr->getRightChildPtr()); 
        delete subTreePtr;
    } 
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
    BinaryNode<ItemType>* newTreePtr = nullptr;
    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr) {
        // Copy node
        newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }
    // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorder(BinaryNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        ItemType theItem = treePtr->getItem(); 
        //visit(theItem);
        std::cout << theItem << " ";
        preorder(treePtr->getLeftChildPtr());
        preorder(treePtr->getRightChildPtr());
    }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorder(BinaryNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        inorder(treePtr->getLeftChildPtr()); 
        ItemType theItem = treePtr->getItem(); 
        //visit(theItem);
        std::cout << theItem << " ";
        inorder(treePtr->getRightChildPtr());
    }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorder(BinaryNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        postorder(treePtr->getLeftChildPtr());
        postorder(treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem(); 
        //visit(theItem);
        std::cout << theItem << " ";
    }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::visit(ItemType& t_item) const {
    std::cout << t_item;
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
   rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
   rootPtr = copyTree(treePtr.rootPtr);
}  // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
   destroyTree(rootPtr);
}  // end destructor

//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
    if (rootPtr == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(std::runtime_error) {
    return (rootPtr->getItem());
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   //preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   //inorder(visit, rootPtr);
}  // end inorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   //postorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::printTree(std::string t_order) const {
    if (t_order == "preorder") {
        preorder(rootPtr);
    } else if (t_order == "inorder") {
        inorder(rootPtr);
    } else if (t_order == "postorder") {
        postorder(rootPtr);
    }
}