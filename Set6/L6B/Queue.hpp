#ifndef QUEUE_HPP
#define QUEUE_HPP

//uses singly linked list... does not keep track of pTail

#include "Node.hpp"
#include <iostream>
using namespace std;

template <typename T>
class Queue{
    public:
        Queue();
        void push(T); //add node to back of the list
        T pop(); //pop the head of the list
        T peak(); //return the head of the list
        bool isEmpty(); //returns if there are elements in the list
        int listSize(); //returns current size of list
        void printList(); //prints the contents of the list
        void printpHead(); //prints head of list
        ~Queue();

    private:
        Node <T>* pHead;
        Node <T>* pTail;
        unsigned int sizeList;
};

//constructor initializes pHead, pTail and sizeList
template <typename T>
Queue <T> :: Queue(){
    pHead = nullptr;
    pTail = nullptr;
    sizeList = 0;
}

//adds node to the end of the list
template <typename T>
void Queue <T>:: push(T VALUE){
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
    return;
}

//deletes Node at the end of the list
template <typename T>
T Queue <T> :: pop(){
    Node <T> *pCurrent = pHead;

    if (pHead == nullptr){
        return -1;
    }

    else {
        pHead = pHead -> pNext;
        
        T top;
        top = pCurrent -> value;
        sizeList = sizeList - 1;
        pCurrent = nullptr;
        delete pCurrent;
        return top;
        
    }
}

//returns the current size of the list
template <typename T>
int Queue <T>:: listSize(){
    return sizeList;
}

//prints the contents of the list
template <typename T>
void Queue <T> :: printList(){
    Node <T> *pCurrent = pHead;
    for(int i = 0; i < sizeList; i++){
        cout << pCurrent -> value << endl;
        pCurrent = pCurrent -> pNext;
    }
    return;
}

//returns the value at tail node
template <typename T>
T Queue <T> :: peak(){
    return pHead -> value;
}

//returns if there are elements in the list (true if empty, false if not)
template <typename T>
bool Queue <T> :: isEmpty(){
    if (listSize() != 0){
        return 0;
    }
    else {return 1;}
}

template <typename T>
void Queue <T> :: printpHead(){
    cout << pHead -> value << endl;
    return;
}

//destructor deletes all nodes when program is done
template <typename T>
Queue <T> :: ~Queue(){
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

#endif