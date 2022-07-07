#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief A single element of a linked list
 * 
 */
template <typename T>
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node <T> *pNext;
    /**
     * @brief pointer to previous element of the linked list
     * 
     */
    Node <T>*pPrevious;
};

#endif