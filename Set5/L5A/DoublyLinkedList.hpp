#ifndef DOUBLY_LINKEDLIST_HPP
#define dOUBLY_LINKEDLIST_HPP

#include "DoublyNode.hpp"

//HOW DO I MAKE pPREVIOUS CONNECT TO THE PREVIOUS NODE

//create class shell and data members
//function prototypes for the class
template < typename T> 
class DoublyLinkedList {
    public:

    Node <T> *pHead;

    Node <T> *pTail;

    unsigned int sizeList; 

    DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList& OTHER);

    ~DoublyLinkedList();

    DoublyLinkedList& operator=(const DoublyLinkedList& OTHER);

    T get(const int POS);

    void set(const int POS, const T VAL);

    void insert(const int POS, const T VAL);

    void remove(const int POS);

    int size() const;

    void print() const;

    void printReverse() const;

    void DeepCopy(const DoublyLinkedList&);

    void pushBack (const T VALUE);

};

//constructor sets head and tail to null and size to 0
template <typename T>
DoublyLinkedList <T> :: DoublyLinkedList(){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;
}

//copy constructor that performs deep copy of the other list
template <typename T>
void DoublyLinkedList <T> :: DeepCopy(const DoublyLinkedList& object){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;

    Node <T> *pObj = object.pHead; //SAYS pOBJ IS UNDECLARED IN THIS SCOPE
    Node <T> *pNode = object.pHead;

    while ( pObj != nullptr){
        pushBack(pObj -> value);
        pObj = pObj -> pNext;
        pObj -> pPrevious = pNode;
        pNode = pNode -> pNext;
    }

}

//adds node to end of list
template <typename T>
void DoublyLinkedList <T> :: pushBack(const T VALUE) {
    Node <T> *pNode = new Node <T>;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;
    pNode -> pPrevious = nullptr;

    Node <T> *pCurrent = new Node <T>;

    pCurrent = pHead;


    if (pHead == nullptr){
        pHead = pNode;
        pTail = pHead;
    }

    else {
        while (pCurrent-> pNext != nullptr){
            pCurrent = pCurrent -> pNext;
        }
        pCurrent -> pNext = pNode;
        pNode -> pPrevious = pCurrent;
        pTail = pNode;
    }
    ++ sizeList;
}

//Destructor that deallocates the entire list, sets the head & tail pointers to be null, sets the size to be zero
template <typename T>
DoublyLinkedList <T> :: ~DoublyLinkedList(){
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

//Copy Assignment Operator that deallocates the existent list (if any) then performs a deep copy of the other list
template <typename T>
DoublyLinkedList <T> & DoublyLinkedList <T> :: operator = (const DoublyLinkedList& OTHER) {
    if (this == (&OTHER)){
        return OTHER;
    }
    
    this -> ~LinkedList();
    DeepCopy(OTHER);
    return (*this);
}

//if POS exists, returns the value at that position. Otherwise, returns the templated constructor
template <typename T>
T DoublyLinkedList <T> :: get(const int POS){
    Node <T> *pNode = new Node <T>;
    pNode = pHead;
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
        if (pNode == nullptr){
            return T(); //HOW DO YOU RETURN TEMPLATED CONSTRUCTOR
        }
    }
    return pNode-> value;
}

// sets value at goven pos. does nothing if out of range.
template <typename T>
void DoublyLinkedList <T> :: set(const int POS, const T VAL) {
    Node <T> *pNode = new Node <T>;
    pNode = pHead;
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
        if (pNode == nullptr){
            break;
        }
    }
    pNode-> value = VAL;
}

//inserts a node before the given POS. If POS is negative, inserts at the beginning of the list. If POS is greater than the current size, inserts at the end of the list. Updates head, tail, and size as appropriate
template <typename T>
void DoublyLinkedList <T> :: insert(const int POS, const T VAL){
    Node <T> *pNode = new Node <T>;
    pNode -> value = VAL;
    pNode -> pNext = nullptr;
    pNode -> pPrevious = nullptr;

    Node <T> *pCurrent = new Node <T>;

    if (POS <= 0){
        pNode -> pNext = pHead;
        if(pHead != nullptr){
            pHead -> pPrevious = pNode;
        }
        pHead = pNode;
        sizeList++;
    }
    
    else {
        pCurrent = pHead;
        if (POS > sizeList) {
            while (pCurrent -> pNext != nullptr){
                pCurrent = pCurrent -> pNext;
            }
            pCurrent -> pNext = pNode;
            pNode -> pPrevious = pCurrent;
            pTail = pNode;
            sizeList++;
        }

        else{
            for (int i = 0; i < POS; i++){
                pCurrent = pCurrent -> pNext;
            }
            pNode -> pNext = pCurrent;
            pCurrent = pCurrent -> pPrevious;
            pNode -> pPrevious = pCurrent;
            pCurrent -> pNext = pNode;
            pCurrent = pCurrent -> pNext;
            pCurrent = pCurrent -> pNext;
            pCurrent -> pPrevious = pNode;
            sizeList++;
        }
    }
}

//removes a node at POS. If POS is negative, removes the head node. If POS is greater than the current size, removes the tail node. Updates head, tail, and size as appropriate
template <typename T>
void DoublyLinkedList <T> :: remove (const int POS){
    Node <T> *pCurrent = new Node <T>;
    pCurrent = pHead;
    Node <T> *pTemp = new Node <T>;
    pTemp = pHead;

    if (POS <= 0){
        pCurrent = pCurrent -> pNext;
        delete pHead;
        pHead = pCurrent;
        sizeList --;
    }

    else {
        if (POS > sizeList) {
            while (pCurrent -> pNext != nullptr){
                pCurrent = pCurrent -> pNext;
            }
            pTail = pCurrent -> pPrevious;
            pTail -> pNext = nullptr;
            sizeList--;
            }
        else{
            for (int i = 0; i < POS; i++){
                pCurrent = pCurrent -> pNext;
            }
            pTemp = pCurrent;
            pCurrent = pCurrent -> pNext;
            pTemp = pTemp -> pPrevious;
            pTemp -> pNext = pCurrent;
            pCurrent -> pPrevious = pTemp;
            
            sizeList --;
        }
    }
}

//returns the current size of the list
template <typename T>
int DoublyLinkedList <T> :: size() const{
    return sizeList;
}

//prints to the standard out the contents of the list using a forward traversal
template <typename T>
void DoublyLinkedList <T> :: print() const{

    Node <T> *pNode = new Node <T>;
    pNode = pHead;

    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }
}

//prints to the standard out the contents of the list using a backwards traversal
template <typename T>
void DoublyLinkedList <T> :: printReverse() const{

    Node <T> *pNode = new Node <T>;
    pNode = pTail;
    while (pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pPrevious;
    }
}

#endif