/* CSCI 261: Lab 3D: Array Ops
 *
 * Author: Brett Eckel, Jaxson Fryer, Logan Douglass, Kylie Quinney
 *
 * This program executes some tests that illustrate the common operatios on arrays.
 *
 * Copyright 2022 Dr. Jeffrey Paone
 */
#include "array_functions.h"
#include <iostream>
 
using namespace std;
/**
 * @brief Allocates an integer array of a target size on the free store.
 * Upon function return, pArray will point to starting address and the
 * contents of pArray will all be initalized to zero.
 *
 * @param pArray pointer to integer array
 * @param INIT_SIZE initial array size as an integer
 *
 * @note Runtime of function O(?)
 */
void array_allocate(int* &pArray, int INIT_SIZE){
    pArray = new int[INIT_SIZE];
}
 
/**
 * @brief Returns the value of the element at a target position.  If the
 * position it not within the array size, returns zero.
 *
 * @param pARRAY pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to retrieve value from
 * @return int element value at given position (or zero if out of range)
 *
 * @note Runtime of function O(?)
 */
int array_get_element_at(int* pARRAY, int SIZE, int POS){
    if(POS > SIZE-1 || POS < 0){
        return 0;
    }
    else{
        return pARRAY[POS];
    }
}
 
/**
 * @brief Sets the value of the element at a target position.  If the
 * position is out of range, does nothing.
 *
 * @param pArray pointer to integer array
 * @param SIZE size of the array as an integer
 * @param POS position to set value at
 * @param VALUE value to place at target position
 *
 * @note Runtime of function O(?)
 */
void array_set_element_at(int* pArray, int SIZE, int POS, int VALUE){
    if(POS < SIZE-1){
        pArray[POS] = VALUE;
    }
}
 
/**
 * @brief Deallocates an integer array, returning its memory back to
 * the free store.  Upon function return, pArray will be set to be a
 * null pointer and the array size will be set to zero.
 *
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 *
 * @note Runtime of function O(?)
 */
void array_deallocate(int* &pArray, int &size){
    delete[] pArray;
    size = 0;
    pArray = nullptr;
}
 
/**
 * @brief Inserts a value at a target position.  If the position is
 * out of range, inserts at the front/back as appropriate.  Upon
 * function return, the array will be increased in size by one.  The
 * array size will be updated to the new size.
 *
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to insert value at
 * @param VALUE value to insert at target position
 *
 * @note Runtime of function O(?)
 */
void array_insert_at_position(int* &pArray, int &size, int POS, int VALUE){
    int* pArrayTwo = new int[size+1];
    if(POS < 0){
        pArrayTwo[0] = VALUE;
    }
    else if(POS >= size){
        pArrayTwo[size] = VALUE;
    }
    else{
        pArrayTwo[POS] = VALUE;
    }
 
    for(int i = 0; i < size; i++){
        if(i >= POS){
            pArrayTwo[i + 1] = pArray[i];
        }
        else{
            pArrayTwo[i] = pArray[i];
        }
    }
 
    delete[] pArray;
    pArray = pArrayTwo;
    size++;
}
 
/**
 * @brief Returns the minimum value within the array.  If array size is
 * zero or the array is uninitialized, returns zero.
 *
 * @param pARRAY pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int minimum value within the array
 *
 * @note Runtime of function O(?)
 */
int array_min(int* pARRAY, int SIZE){
    if(SIZE <= 0 || pARRAY == nullptr){
        return 0;
    }
    int min = pARRAY[0];
    for(int i = 0; i< SIZE; i++){
        if(min > pARRAY[i]){
            min = pARRAY[i];
        }
    }
    return min;
}
 
/**
 * @brief Returns the maximum value within the array.  If array size is
 * zero or the array is uninitialized, returns zero.
 *
 * @param pARRAY pointer to the integer array
 * @param SIZE size of the array as an integer
 * @return int maximum value within the array
 *
 * @note Runtime of function O(?)
 */
int array_max(int* pARRAY, int SIZE){
    if(SIZE <= 0 || pARRAY == nullptr){
        return 0;
    }
    int max = pARRAY[0];
    for(int i = 0; i< SIZE; i++){
        if(max < pARRAY[i]){
            max = pARRAY[i];
        }
    }
    return max;
}
 
/**
 * @brief Returns the first position within an array a target value
 * is located at.  If the target value is not present within the
 * array, returns -1.
 *
 * @param pARRAY pointer to the integer array (the haystack)
 * @param SIZE size of the array as an integer
 * @param TARGET target integer value to search for in the array (the needle)
 * @return int position within the array target value is located (or -1 if not present)
 *
 * @note Runtime of function O(?)
 */
int array_find(int* pARRAY, int SIZE, int TARGET){
    int index = -1;
    for(int i = 0; i< SIZE; i++){
        if(TARGET == pARRAY[i]){
            index = i;
            return index;
        }
    }
    return index;
}
 
/**
 * @brief Removes a value at a target position.  If the position is
 * out of range, removes from the front/back as appropriate.  Upon
 * function return, the array will be decreased in size by one.  The
 * array size will be updated to the new size.
 *
 * @param pArray pointer to integer array
 * @param size size of the array as an integer
 * @param POS position to remove value from
 *
 * @note Runtime of function O(?)
 */
void array_remove_from_position(int* &pArray, int &size, int POS){
    if (size <= 0) return;
 
    int* pArrayTwo = new int[size-1];
    if(POS < 0){
        POS = 0;
    }
    else if(POS >= size){
        POS = size-1;
    }
    for(int i = 0; i < size - 1; i++){
        if(i >= POS){
            pArrayTwo[i] = pArray[i + 1];
        }
        else{
            pArrayTwo[i] = pArray[i];
        }
    }
 
    delete[] pArray;
    pArray = pArrayTwo;
    size--;
 
}
