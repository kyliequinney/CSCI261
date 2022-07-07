/* CSCI261 Lab 4B
 *
 * Author: Kylie Quinney
 *
 * This program executes some tests that illustrate the properties
 * and behaviors of linked lists.
 *
 * Copyright 2022 Dr. Jeffrey Paone
 */

#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {
    // TODO #1
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;
    return pNode;
}

int linked_list_get_size(Node* pHead) {
    // TODO #2
    Node *pCurrent = new Node;
    pCurrent = pHead;
    int size = 0;
    while (pCurrent != nullptr){
        pCurrent = pCurrent -> pNext;
        ++size;
    }
    return size;
}

Node* linked_list_add_value_to_front (Node* pHead, const int VALUE) {
    // TODO #3
    Node *pNode = new Node;
    pNode -> value = VALUE;
    pNode -> pNext = pHead;
    pHead = pNode;
    return pHead;
}

int linked_list_get_value_at_position (Node* pHead, const int POS) {
    // TODO #4
    Node *pNode = new Node;
    pNode = pHead;
    if (pNode == nullptr || POS < 0 || POS >= linked_list_get_size(pHead)){
            return -1;
        }
    
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
        
    }
    return pNode-> value;
}

int linked_list_min (Node* pHead) {
    // TODO #5
    if (pHead == nullptr){
        return -1;
    }

    Node *pNode = new Node;
    Node *pMin = new Node;
    pNode = pHead -> pNext;
    pMin = pHead;

    while (pNode != nullptr){
        if (pNode -> value < pMin -> value){
            pMin = pNode;
        }
        pNode = pNode -> pNext;
    }
    return pMin -> value;
}

int linked_list_max (Node* pHead) {
    // TODO #6
    if (pHead == nullptr){
        return -1;
    }

    Node *pNode = new Node;
    Node *pMax = new Node;
    pNode = pHead -> pNext;
    pMax = pHead;

    while (pNode != nullptr){
        if (pNode -> value > pMax -> value){
            pMax = pNode;
        }
        pNode = pNode -> pNext;
    }
    return pMax -> value;
}

int linked_list_find(Node* pHead, const int TARGET) {
    // TODO #7

    Node *pNode = new Node;
    pNode = pHead;
    if (pHead = nullptr){
        return -1;
    }

    int index = 0;
    while (pNode != nullptr){
        if (pNode -> value == TARGET){
            return index;
        }
        pNode = pNode -> pNext;
        ++index;
    }
    return -1;
}

Node* linked_list_remove_node_from_front(Node* pHead) {
    // TODO #8
    if (pHead == nullptr){
        return pHead;
    }
    pHead = pHead -> pNext;
    return pHead;
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    // TODO #9
    Node *pNode = new Node;
    pNode = pHead;
    if (pNode == nullptr || POS < 0 || POS >= linked_list_get_size(pHead)){
            return pHead;
        }
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
    }
    pNode -> value = VALUE;
    return pHead;
}