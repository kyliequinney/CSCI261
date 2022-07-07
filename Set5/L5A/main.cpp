/* CSCI 261: L5A - Double the fun
 *
 * Author: Kylie Quinney
 * Resources used : none
 *
 * Description: create a doubly linked list
 * 
 */
#include <iostream>
#include "DoublyNode.hpp"
#include "DoublyLinkedList.hpp"
using namespace std;

int main(){

    //test all functions for doubly linked list
    DoublyLinkedList <int> object;
    object.insert(0, 6);
    object.insert(0, 5);
    object.insert(5, 7);
    object.insert(-3, 1);
    object.insert(1, 2);
    object.insert(2, 9);
    object.insert(2, 3);
    
    cout << "print forward: " << endl;
    object.print();
    
    cout << "print backwards" << endl;
    object.printReverse();
    object.set(3, 4);

    cout << "print forward (2) :" << endl;
    object.print();

    object.remove(-2);
    cout << "remove head" << endl;
    object.print();
    object.remove(9);
    cout << "remove last" << endl;
    object.print();
    object.remove(2);
    cout << "remove 4?" << endl;
    object.print();

    cout << "get position 2" << endl;
    cout << object.get(2) << endl;

    cout << " size of list: " << endl;
    cout << object.size() << endl;

    cout << "final print" << endl;
    object.print();

    return 0;
}

