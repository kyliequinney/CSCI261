#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

//create class shell and data members
//function prototypes for the class
class LinkedList {
    
public:

    Node *pHead;

    Node *pTail;

    unsigned int sizeList;

    Node* makeNodeForValue(int VALUE);

    int front();

    int back();

    unsigned int size();

    //create constructor
    LinkedList();

    void DeepCopy(const LinkedList&);

    //copy constructor
    LinkedList(const LinkedList& object);

    LinkedList& operator = (LinkedList& object);

    int at(int POS);

    //create destructor
    ~LinkedList();

    

//private:

    void pushFront(int VALUE);

    void pushBack (int VALUE);

    int popFront();


};


#endif