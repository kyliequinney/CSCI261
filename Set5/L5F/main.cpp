/* CSCI 261: L5F - A Needle in the Haystack
 *
 * Author: Kylie Quinney
 * Resources used : c++ reference website for how to work with vectors
 *
 * Description: Use a binary search algorithm to find a value in a sorted list
 * 
 */

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main() {

    //seed random num generator
    srand(time(0));

    //prompt user for length of list
    cout << "Please enter a positive integer: " << endl;
    int lengthList;
    cin >> lengthList;

    //create vector and populate with random numbers
    vector <int> myList (lengthList);
    for(int i = 0; i < lengthList;i++){
        myList[i]= rand();
    }

    //print the unsorted list
    cout << "unsorted list: " << endl;

    for(int i = 0; i < lengthList; i++){
        cout << myList[i] << " " ;
    }

    cout << "" << endl;

    //sort list with selection sort
    for (int i = 0; i < lengthList; i++){
        int k = i;
        for(int j = i+1; j < lengthList; j++){
            if (myList[j] < myList [k]){
                k=j;
            }
        }
        swap(myList[i], myList[k]);
    }

    //print sorted list
    cout << "sorted list: " << endl;
    for(int i = 0; i < lengthList; i++){
        cout << myList[i] << " " ;
    }

    //prompt user for amount of values to search for then create list of that length
    cout << "" << endl;
    cout << "How many values do you wish to search for? " << endl;
    int searches;
    cin >> searches;

    //prompt user for what values they want to search the list for
    vector <int> findVal(searches);
    for (int i = 0; i < searches; i++){
        cout << "what number do you wish to search for?" << endl;
        int temp;
        cin >> temp;
        findVal[i] = temp;
    }

    //use binary search to return the index of the value if it is present in the list or print -1 if it is not
    
    for (int i = 0; i < searches; i++){
        int x = findVal[i];
        int low = 0;
        int high = lengthList;
        int mid = 0;
        while(mid != x){
            mid = (low + high)/2;
            if(low == high){
                cout << x << " is not in the list" << endl;
                mid=x;
            }
            if (x == myList[mid]){
                cout << x << " is located at index " << mid << endl;
                mid=x;
                }
            //if x is on the right side
            else if (x > myList[mid]){ 
                low = mid + 1;
                }
            //if x is on the left side
            else{                       
                high = mid - 1;
                }
        }
    }

    return 0;
}