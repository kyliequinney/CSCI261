/* CSCI261 Lab 4C - A Linked List Class Part I: The Class Shell
 *
 * Author: Kylie Quinney
 *
 * Description: Create class for LinkedList in order to use an object-oriented approach 
 *
 * Copyright 2022 Dr. Jeffrey Paone
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

//create class shell and data members
//function prototypes for the class
class LinkedList {
    
public:

    Node *pHead;

    Node *pTail;

    unsigned int size;

    Node* makeNodeForValue(int VALUE);

private:

    void pushFront(int VALUE);

    void pushBack (int VALUE);

    int popFront();


};


#endif