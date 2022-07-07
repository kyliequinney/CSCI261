#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include "Node.hpp"
using namespace std;

/**
 * @brief ask user what they want to do, returns int equivelent to their choice
 * 
 * @return int 
 */
int userPrintChoice(){
    cout << "What do you wish to do?" << endl;
    cout << "1) Print comments \n" << "2) Print vertices \n" << "3) Print faces \n" << "4) Quit" << endl;
    cout << "Choice: " << endl;
    int choice;
    cin >> choice;

    return choice;
}

/**
 * @brief returns amount of nodes in the list
 * 
 * @param pHead 
 * @return int 
 */
int linked_list_get_size(Node <string>* pHead) {
    // TODO #2
    Node <string> *pCurrent = new Node <string>;
    pCurrent = pHead;
    int size = 0;
    while (pCurrent != nullptr){
        pCurrent = pCurrent -> pNext;
        ++size;
    }
    return size;
}

/**
 * @brief returns value at given position in given linked list
 * 
 * @tparam T 
 * @param pHead 
 * @param POS 
 * @return string 
 */
template <typename T>
string linked_list_get_value_at_position (Node <T> * &pHead, const int POS) {
    // TODO #4
    Node <T> *pNode = new Node <T>;
    pNode = pHead;
    if (pNode == nullptr || POS < 0 || POS >= linked_list_get_size(pHead)){
            return T();
        }
    
    for (int i = 0; i < POS; i++){
        pNode = pNode -> pNext;
        
    }
    return pNode-> value;
}

/**
 * @brief my attempt at getting the value in vertices wanted from the face
 * 
 * @tparam T 
 * @param num 
 * @param pVertices 
 * @return string 
 */
template <typename T>
string getVertices (char num, Node <T> *&pVertices){
    int POS = num - 48;
    string vertices = linked_list_get_value_at_position(pVertices, POS);
    return vertices;
} 

/**
 * @brief prints the contents of the linked list
 * 
 * @tparam T 
 * @param type 
 * @param pHead 
 */
template <typename T>
//prints out extra lines rn
void printContents ( string type, int size, Node <T>* pHead ){
    Node <T> *pNode = new Node <T>;
    pNode = pHead;

    int count= 1;

    for(int i = 0; i < size; i++){
        cout << type << " #" << count << ": " << pNode -> value << endl;
        pNode = pNode -> pNext;
        count++;
    }
}

#endif