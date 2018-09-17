/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 11/14/2017
LAB: 09
FILE NAME: BINARYSEARCHTREE.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR BINARYSEARCHTREE.H
*/

#include "BinaryNode.h"

#include <stdexcept>

//------------------------------------------------------------
// CONSTRUCTORS & DECONSTRUCTORS
//------------------------------------------------------------

// generic constructor, just sets rootPtr to nullptr
template <typename Key, typename ItemType>
BinarySearchTree<typename Key, typename ItemType>::BinarySearchTree() {
    rootPtr = nullptr;
}

// creates a new tree with root item set as parameter passed in 
template <typename Key, typename ItemType>
BinarySearchTree<typename Key, typename ItemType>::BinarySearchTree(const ItemType& rootItem) {
    rootPtr = rootItem;
}

// copy constructor, uses copyTree helper method 
template <typename Key, typename ItemType>
BinarySearchTree<typename Key, typename ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) {
    rootPtr = copyTree(tree.rootPtr);
}

// destructor that uses the destroyTree helper method
template <typename Key, typename ItemType>
BinarySearchTree<typename Key, typename ItemType>::~BinarySearchTree() {
    destroyTree(rootPtr);
}

//------------------------------------------------------------
// PUBLIC METHODS
//------------------------------------------------------------

// returns bool regarding whether or not the BST is empty
template <typename Key, typename ItemType>
bool BinarySearchTree<typename Key, typename ItemType>::isEmpty() const {
    if (rootPtr == null) {
        return true;
    } else {
        return false;
    }
}

// returns int height of BST, uses getHeightHelper helper method
template <typename Key, typename ItemType>
int BinarySearchTree<typename Key, typename ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

// returns int number of nodes in BST, uses getNumberofNodesHelper helper method
template <typename Key, typename ItemType>
int BinarySearchTree<typename Key, typename ItemType>::getNumberOfNodes() const {
    return getNumberofNodesHelper(rootPtr);
}

// returns ItemType of data stored in rootPtr, throws runtime_error if rootPtr is nullptr
template <typename Key, typename ItemType>
ItemType BinarySearchTree<typename Key, typename ItemType>::getRootData() const throw (std::runtime_error) {
    return rootPtr->getItem();
}

// sets ItemType of data to be stored data in rootPtr
template <typename Key, typename ItemType>
void BinarySearchTree<typename Key, typename ItemType>::setRootData(const ItemType& newData) const throw(std::runtime_error) {
    rootPtr->setItem(newData);
}

// inserts entry into BST, uses inorderInsertion helper method
template <typename Key, typename ItemType>
bool BinarySearchTree<typename Key, typename ItemType>::add(const ItemType& newEntry) {
    BinaryNode<ItemType>* node_ptr = new BinaryNode<ItemType>*(newEntry);
    rootPtr = inorderInsertion(rootPtr, node_ptr);
}

// removes node from BST, uses removeValue helper method, throws runtime_error if node does not exist
template <typename Key, typename ItemType>
void BinarySearchTree<typename Key, typename ItemType>::remove(const KeyType & anEntry) {
    bool was_successful = true;

    rootPtr = removeValue(rootPtr, anEntry, was_successful);

    if (!was_successful) {
        throw std::runtime_error("ERROR. remove(const Keytype & anEntry) : KEY NOT FOUND");
    }
}

// returns ItemType of requested node, uses findNode helper method, throws runtime_error if node does not exist
template <typename Key, typename ItemType>
ItemType BinarySearchTree<typename Key, typename ItemType>::getEntry(const KeyType& anEntry) const throw(std::runtime_error) {
    BinaryNode<ItemType>* found_ptr = findNode(rootPtr, anEntry);

    if (found_ptr == nullptr) {
        throw std::runtime_error("ERROR. getEntry(const KeyType& anEntry) : KEY NOT FOUND");
    } else {
        return (found_ptr->getItem());
    }
}

// returns bool regarding whether or not BST contains a requested key, uses findNode helper method
template <typename Key, typename ItemType>
bool BinarySearchTree<typename Key, typename ItemType>::contains(const KeyType& anEntry) const {
    if (findNode(rootPtr, anEntry) != nullptr) {
        return true;
    } else {
        return false;
    }
}

// completely destroys tree, uses destroyTree helper method
template <typename Key, typename ItemType>
void BinarySearchTree<typename Key, typename ItemType>::clear() {
    destroyTree(rootPtr);
}

//------------------------------------------------------------
// PUBLIC TRAVERSALS
//------------------------------------------------------------

// traverses in preorder, uses preorderHelper helper method
template <typename Key, typename ItemType>
void BinarySearchTree<typename Key, typename ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorderHelper(visit, rootPtr);
}

// traverses in inorder, uses inorderHelper helper method
template <typename Key, typename ItemType>
void BinarySearchTree<typename Key, typename ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorderHelper(visit, rootPtr);
}

// traverses in postorder, uses postorderHelper helper method
template <typename Key, typename ItemType>
void BinarySearchTree<typename Key, typename ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorderHelper(visit, rootPtr);
}

//------------------------------------------------------------
// PROTECTED UTILITY METHODS - RECURSIVE HELPER METHODS FOR THE PUBLIC METHODS
//------------------------------------------------------------

template <typename Key, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<typename Key, typename ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode) {
    // tree is empty or there is no child for prev node
    if (subTreePtr == nullptr) {
        return newNode;
    }
    // new node greater than current node, go right
    else if (newNode->getItem() > subTreePtr->getItem()) {
        BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    // new node less than current node, go left
    else {
        BinaryNode<ItemType>* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
    }

    return subTreePtr;
}

template <typename Key, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<typename Key,typename ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    // if tree is empty return false
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    // current node is the target
    else if (subTreePtr->getItem() == target) {
        // remove the node, return the tree without the node
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    // current node is greater than target, go left
    else if (subTreePtr->getItem() > target) {
        BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
    // current node is less than target, go right
    else {
        BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}

template <typename Key, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<typename Key, typename ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
    // node is leaf, delete node, retrun null
    if (nodePtr->isLeaf() == true) {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    // node has one child
    else if ((nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() != nullptr) || (nodePtr->getRightChildPtr() == nullptr ** nodePtr->getLeftChildPtr() != nullptr)) {
        BinaryNode<ItemType>* nodeConnectPtr;
        // get child
        if (nodePtr->getLeftChildPtr() != nullptr) {
            nodeConnectPtr = nodePtr->getLeftChildPtr();
        } else {
            nodeConnectPtr = nodePtr->getRightChildPtr();
        }
        // delete the node
        delete nodePtr;
        nodePtr = nullptr;
        // return the child to the parent
        return nodeConnectPtr;
    }
    // node has two children
    else {
        ItemType inorderSuccessor;
        // find the successor node, return it, delete original
        BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor);
        nodePtr->setRightChildPtr(tempPtr);
        // change the node item to the inorderSucessor item
        nodePtr->setItem(inorderSuccessor);
    }
}

template <typename Key, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<typename Key, typename ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor) {
    // inorderSuccessor found
    if (subTreePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    }
    // not found, recurse
    else {
        subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
        return subTreePtr;
    }
}

template <typename Key, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<typename Key, typename ItemType>::findNode(BinaryNode<ItemType>* treePtr, const KeyType& target) const {
    // tree is empty
    if (treePtr == null) {
        return nullptr;
    }
    // found node
    else if (treePtr->getItem() == target) {
        return treePtr;
    }
    // current node greater than target, go left
    else if (treePtr->getItem() > target) {
        return findNode(treePtr->getLeftChildPtr(), target);
    }
    // current node less than target, go right
    else {
        return findNode(treePtr->getRightChildPtr(), target);
    }
}
