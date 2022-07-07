#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

//create class shell and data members
//function prototypes for the class
template < typename T> 
class LinkedList {
    
public:

    Node <T>* pHead;

    Node <T>* pTail;

    unsigned int sizeList;

    //Node makeNodeForValue(const T VALUE);

    T front() const;

    T back() const;

    unsigned int size() const;

    //create constructor
    LinkedList();

    void DeepCopy(const LinkedList&);

    //copy constructor
    LinkedList(const LinkedList& object);

    LinkedList& operator = (LinkedList& object);

    T at(const int POS);

    //create destructor
    ~LinkedList();

    

//private:

    void pushFront(const T VALUE);

    void pushBack (const T VALUE);

    int popFront();


};

/* CSCI261 Lab 4E
 *
 * Author: Kylie Quinney
 *
 * Description: Continue refactoring LinkedList class
 */
#include <iostream>
#include "LinkedList.hpp"
using namespace std;

//Sets the head & tail pointers to be null. Sets the size to be zero.
template <typename T>
LinkedList <T> :: LinkedList(){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;
}


//Deletes all nodes in the list. Updates the head & tail pointers and size as appropriate.
template <typename T>
LinkedList <T> :: ~LinkedList(){
    Node <T> *pCurrent= pHead;
    Node <T> *pNext2 = pHead;

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
/*template <typename T>
Node LinkedList <T> :: makeNodeForValue(const T VALUE) {
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;

    return pNode;
}*/

//Adds a node to the head of the list with the provided parameter value. 
//Updates the head & tail pointers and size as appropriate.
template <typename T>
void LinkedList <T> :: pushFront(const T VALUE) {
    Node <T> *pNode = new Node <T>;
    pNode -> value = VALUE;
    pNode -> pNext = pHead;
    pHead = pNode;
    ++ sizeList;
}

//Adds a node to the tail of the list with the provided parameter value. 
//Updates the head & tail pointers and size as appropriate.
template <typename T>
void LinkedList <T> :: pushBack(const T VALUE) {
    Node <T> *pNode = new Node <T>;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;
    Node <T> *pCurrent = new Node <T>;
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
template <typename T>
int LinkedList <T>:: popFront() {
    if (pHead == nullptr){
        return T();
    }

    Node <T> *pNode = new Node <T>;
    pNode = pHead;
    pHead = pHead -> pNext;

    -- sizeList;

    return pNode -> value;
}

//Returns the current value of the head node. 
//If list is empty, returns -1 by default.
template <typename T>
T LinkedList <T> :: front() const {
    if (pHead == nullptr){
        return T();
    }

    return pHead -> value;
}

//Returns the current value of the back node. 
//If list is empty, returns -1 by default
template <typename T>
T LinkedList <T>:: back() const{
    if (pHead == nullptr){
        return T();
    }

    return pTail -> value;
}

//Returns the current size.
template <typename T>
unsigned int LinkedList <T>:: size() const{
    return sizeList;
}

//Perform a deep copy of the passed object. The newly constructed list will have the same size and ordered values as the passed list.
template <typename T>
LinkedList <T> :: LinkedList (const LinkedList& object) {
    DeepCopy(object);
}

//Deallocate the current list. Perform a deep copy of the passed object. The new list will have the same size and ordered values as the passed list.
template <typename T>
LinkedList <T> & LinkedList <T> :: operator = (LinkedList& object) {
    if (this == (&object)){
        return object;
    }
    
    this -> ~LinkedList();
    DeepCopy(object);
    return (*this);
}

template <typename T>
void LinkedList <T> :: DeepCopy(const LinkedList& object){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;

    Node <T> *pObj = object.pHead;

    while ( pObj != nullptr){
        pushBack(pObj -> value);
        pObj = pObj -> pNext;
    }

}

// The value at the provided position. -1 if out of range.
template <typename T>
T LinkedList <T> :: at(const int POS) {
    Node <T> *pNode = new Node <T>;
    pNode = pHead;
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
        if (pNode == nullptr){
            return T();
        }
    }
    return pNode-> value;
}


#endif