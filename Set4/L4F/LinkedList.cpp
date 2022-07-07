/* CSCI261 Lab 4E
 *
 * Author: Kylie Quinney
 *
 * Description: Continue refactoring LinkedList class
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
    Node *pCurrent = pHead;
    Node *pNext2 = pHead;

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
Node* LinkedList :: makeNodeForValue(const int VALUE){
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;

    return pNode;
}

//Adds a node to the head of the list with the provided parameter value. 
//Updates the head & tail pointers and size as appropriate.
void LinkedList :: pushFront(const int VALUE) {
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = pHead;
    pHead = pNode;
    ++ sizeList;
}

//Adds a node to the tail of the list with the provided parameter value. 
//Updates the head & tail pointers and size as appropriate.
void LinkedList :: pushBack(const int VALUE) {
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;
    Node *pCurrent = new Node;
    pCurrent = pHead;


    if (pHead == nullptr){
        pHead = pNode;
    }

    else {
        while (pCurrent-> pNext != nullptr){
            pCurrent = pCurrent -> pNext;
        }
        pCurrent -> pNext = pNode;
        pTail = pNode;
    }
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

//Perform a deep copy of the passed object. The newly constructed list will have the same size and ordered values as the passed list.
LinkedList :: LinkedList (const LinkedList& object) {
    DeepCopy(object);
}

//Deallocate the current list. Perform a deep copy of the passed object. The new list will have the same size and ordered values as the passed list.
LinkedList& LinkedList :: operator = (LinkedList& object) {
    if (this == (&object)){
        return object;
    }
    
    this -> ~LinkedList();
    DeepCopy(object);
    return (*this);
}

void LinkedList :: DeepCopy(const LinkedList& object){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;

    Node *pObj = object.pHead;

    while ( pObj != nullptr){
        pushBack(pObj -> value);
        pObj = pObj -> pNext;
    }

}

// The value at the provided position. -1 if out of range.
int LinkedList :: at(const int POS) {
    Node *pNode = new Node;
    pNode = pHead;
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
        if (pNode == nullptr){
            return -1;
        }
    }
    return pNode-> value;
}