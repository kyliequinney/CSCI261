/* CSCI 261: Lab 4A: Array vs Linked List
 *
 * Author: Kylie Quinney
 * Resources used: class slides, TA Help Hours (Vincent and Asher)
 *
 * Description: utilize a dynamically sorted array and dynamically allocated linked list
 */

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *pNext;
};

void reverse(Node **pHead ){
    Node *pPrevious = nullptr;
    Node *pCurrent = (*pHead);
    Node *pForward = nullptr;

    while (pCurrent != nullptr){
        pForward = pCurrent -> pNext;
        pCurrent -> pNext = pPrevious;
        pPrevious = pCurrent;
        pCurrent = pForward;
    }

    (*pHead) = pPrevious;
}
int main() {

    //create an array of 3 elements
    int arr[3];
    int *parr;
    parr = arr;

    //prompt user for contents of array
    for (int i = 0; i <3; i++){
        cout << "Please enter a value: " << endl;
        cin >> arr[i];
    }

    //print contents of array in order
    cout<< "The contents of array at " << parr << " are: " << endl;
    for (int i = 0; i < 3; i++){
        cout << arr[i] << endl;
    }

    //print contents of array backwards
    cout << "The contents of array at " << parr << " in reverse order are: " << endl;
    size_t n = sizeof(arr)/sizeof(arr[0]);

    for (int i = n-1 ; i >= 0; i--){
        cout << arr[i] << endl;
    }

    //create pointers
    Node *pHead = new Node;
    Node *pNodeTwo = new Node;
    Node *pTailNode = new Node;

    //link nodes
    pHead -> pNext = pNodeTwo;
    pNodeTwo -> pNext = pTailNode;

    //create second pointer pointing at pHead value
    Node *pLoop = pHead;

    //assign user input to proper locations
    for (int i = 0; i <3; i++){
        cout << "Please enter a value: " << endl;
        cin >> pLoop -> value;
        pLoop = pLoop -> pNext;
    }

    //reset pLoop to point at same place as pHead
    pLoop = pHead;

    //print contents of linked-list in order
    cout << "The contents of the linked list are: " << endl;
    for (int i = 0; i <3; i++){
        cout << pLoop -> value << endl;
        pLoop = pLoop -> pNext;
    }

    /*Node *pPrevious = nullptr;
    Node *pCurrent = pHead;
    Node *pForward = nullptr;

    while (pCurrent != nullptr){
        pForward = pCurrent -> pNext;
        pCurrent -> pNext = pPrevious;
        pPrevious = pCurrent;
        pCurrent = pForward;
    }

    pHead = pPrevious;

    pLoop = pHead;

    cout << "The contents of the linked list in reverse order are: " << endl;
    for (int i = 0; i <3; i++){
        cout << pLoop -> value << endl;
        pLoop = pLoop -> pNext;
    }*/

    //print linked list in reverse order
    cout << "The linked list values in reverse order are: " << endl;
    cout<< pTailNode -> value << endl;
    cout << pNodeTwo -> value << endl;
    cout << pHead -> value << endl;


    return 0;
}
