/* CSCI261 Lab 4F
 *
 * Author: Kylie Quinney
 *
 * Description: Finish modifying and building out class
 */
#include "LinkedList.hpp"
#include "Node.hpp"
#include <iostream>
using namespace std;

int main(){
    //create linkedlist object
    LinkedList<int> object;

    //print initial size
    cout << "initial size of object1: " << object.size() << endl;

    //add values to the list
    object.pushFront(1);
    object.pushBack(2);
    object.pushFront(3);
    object.pushBack(4);
    object.pushFront(5);
    object.pushBack(6);

    //print new size
    cout << "updated size of object1: " << object.size() << endl;

    //print contents of the list
    Node <int> *pNode = new Node <int>;
    pNode = object.pHead;

    cout << "contents of object1: " << endl;
    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }

    //make second linked list
    LinkedList <int> object2;

    //print out object2 initial size
    cout<< "initial size of object2: " << object2.size() << endl;

    //assign object2 to object
    object2 = object;
    cout << "updated size of object1: " << object.size() << endl;
    cout << "updated size of object2: " << object2.size() << endl;

    //add values to object
    object.pushFront(7);
    object.pushBack(8);

    //print both object's size and contents
    cout <<"size of object 1: " << object.size() << endl;
    cout << "contents of object1: " << endl; 

    pNode = object.pHead;

    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }

    cout << "size of object2: " << object2.size() << endl;

    pNode = object2.pHead;

    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }

    //create third linked list using copy constructor and first linked list as arguments
    LinkedList <int> object3 = object;

    //print out size of all three objects
    cout << "object1 size: " << object.size() << endl;
    cout << "object2.size: " << object2.size() << endl;
    cout << "object3 size: " << object3.size() << endl; 

    //add values to the first list
    object.pushFront(9);
    object.pushBack(10);

    //print all three sizes
    cout << "object1 size: " << object.size() << endl;
    cout << "object2.size: " << object2.size() << endl;
    cout << "object3 size: " << object3.size() << endl;

    //print contents of all three lists
    cout << "object1 contents: " << endl;

    pNode = object.pHead;

    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }

    cout << "object2 contents" << endl;

    pNode = object2.pHead;

    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }

    cout << "object3 contents" << endl;

    pNode = object3.pHead;

    while(pNode != nullptr){
        cout << pNode -> value << endl;
        pNode = pNode -> pNext;
    }

    //delete all three lists
    //doesn't the destructor do this on it's own???

    LinkedList <string> stringList;
    stringList.pushFront("is");
    stringList.pushBack("working");
    stringList.pushFront("This");
    stringList.pushBack("now.");

    Node <string> * pStringNode = new Node <string>;
    pStringNode = stringList.pHead;
    cout<< "stringList contents: " << endl;
    pStringNode = stringList.pHead;
    while(pStringNode != nullptr){
        cout << pStringNode -> value << endl;
        pStringNode = pStringNode -> pNext;
    }


    return 0;
}