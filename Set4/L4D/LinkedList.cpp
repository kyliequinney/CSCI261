/* CSCI261 Lab 4D
 *
 * Author: Kylie Quinney
 *
 * Description: Begin refactoring LinkedList class. Define the functions in LinkedList.h
 */
#include <iostream>
#include "LinkedList.h"
using namespace std;

//Sets the head & tail pointers to be null. Sets the size to be zero.
LinkedList :: LinkedList(){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;
}

//Deletes all nodes in the list. Updates the head & tail pointers and size as appropriate.
LinkedList :: ~LinkedList(){
    Node *pCurrent = new Node;
    Node *pNext2 = new Node;
    pCurrent = pHead;
    while (pCurrent != nullptr) {
        pNext2 = pCurrent -> pNext;
        delete pCurrent;
        pCurrent = pNext2;
    }

    pHead = nullptr;
    pTail = nullptr;
    sizeList = 0;
}

//Returns a node pointer to a newly made node whose value is set to the parameter passed in and the next pointer is set to be null.
Node* LinkedList :: makeNodeForValue(int VALUE){
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;

    return pNode;
}

//Adds a node to the head of the list with the provided parameter value. 
//Updates the head & tail pointers and size as appropriate.
void LinkedList :: pushFront(int VALUE) {
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = pHead;
    pHead = pNode;
    ++ sizeList;
}

//Adds a node to the tail of the list with the provided parameter value. 
//Updates the head & tail pointers and size as appropriate.
void LinkedList :: pushBack(int VALUE) {
    Node *pNode = new Node;
    pTail -> pNext = pNode;
    pTail = pNode;
    ++ sizeList;
}

//Deletes the node at the head of the list and returns its value. Updates the head & tail pointers and size as appropriate. 
//If list is empty, returns -1 by default.
int LinkedList :: popFront() {
    if (pHead == nullptr){
        return -1;
    }

    Node *pNode = new Node;
    pNode = pHead;
    pHead = pHead -> pNext;

    -- sizeList;

    return pNode -> value;
}

//Returns the current value of the head node. 
//If list is empty, returns -1 by default.
int LinkedList :: front() {
    if (pHead == nullptr){
        return -1;
    }

    return pHead -> value;
}

//Returns the current value of the back node. 
//If list is empty, returns -1 by default
int LinkedList :: back() {
    if (pHead == nullptr){
        return -1;
    }

    return pTail -> value;
}

//Returns the current size.
unsigned int LinkedList :: size() {
    return sizeList;
}