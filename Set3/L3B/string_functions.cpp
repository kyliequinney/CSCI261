/* CSCI 261: Lab 3B: Strings Test Suite
 *
 * Author: Kylie Quinney
 * Resources used: class slides, friend helped debugg remove_first_word
 *
 * Description: Implement functions so that all tests in test_suite.cpp are passed
 */
#include "string_functions.h"

int string_length(const string STR)  {
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = STR[IDX];
    // TODO 01: set result to the character of a string at a given index
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT + RIGHT;
    // TODO 02: set result to the concatenation of strings LEFT and RIGHT
    return result;
}

string string_insert(string STR, const string TO_INSERT, const int IDX) {
    string result = STR.insert(IDX, TO_INSERT);
    // TODO 03: set result to the result of inserting a string into another
    return result;
}

int string_find(const string STR, const char C)  {
    int result = STR.find(C);
    // TODO 04: set result to the index of the first occurrence of the character
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR.substr(IDX, LEN);
    // TODO 05: set result to be a substring starting at index of given length
    return result;
}

string string_replace(string STR, string TEXT_TO_REPLACE, string REPLACE_WITH) {
    string result;
    //if text to replace is found
    if (STR.find(TEXT_TO_REPLACE) != string::npos)
        result = STR.replace(STR.find(TEXT_TO_REPLACE), TEXT_TO_REPLACE.length(), REPLACE_WITH);
    else
        result = STR;
    // TODO 06: set result to be the string with the given text replaced
    return result;
}

string string_first_word(string STR)  {
    string result = STR.substr(0, STR.find(" "));
    // TODO 07: set result to the first word from the string
    return result;
}

string string_remove_first_word(const string STR)  {
    string result;
    int indexNum = STR.find(" ");
    //if a space is not found (one word)
    if (indexNum == -1) {
        return "";
    }
    //result is string without first space and what comes before it
    for ( int i = indexNum+1; i < STR.length(); i++){
        result = result + STR[i];
    }
    // TODO 08: set result to be the string with the first word removed*/
    return result;
}

string string_second_word(string STR)  {
    //call string_nth_word function
    string result = string_nth_word(STR, 2);
    // TODO 09: set result to be the second word from the string
    return result;
}

string string_third_word(const string STR)  {
    //call string_nth_word function
    string result = string_nth_word(STR, 3);
    // TODO 10: set result to be the third word from the string
    return result;
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    //call remove_first_word function the necessary number of times
    for (int i=0; i< N-1; i++){
        result= string_remove_first_word(result);
    }
    result= string_first_word(result);
    // TODO 11: set result to be the nth word from the string
    return result;
}

string string_substitute(string STR, char TARGET, char REPLACEMENT) {
    //count all  instances of the word that will be replaced
    int count = 0;
    for( int i = 0; i < STR.length(); i++){
        if (STR[i] == TARGET)
            ++count;
    }
    string rep;
    string result;
    result = count;
    rep.push_back(REPLACEMENT);
    //find and replace the word for as many times as counted previousely
    while (count > 0){
        STR.replace(STR.find(TARGET), 1, rep);
        result = STR;
        count--;
    }
    // TODO 12: set result to be the string with all instances of TARGET replaced*/
    return result;
}

string string_to_lower(string STR) {
    locale loc;
    string result;
    string str;
    for(int i = 0; i < STR.length(); i++){
        str = tolower(STR.at(i));
        result = result.append(str);
    }
    // TODO 13: convert all characters to lower case
    return result;
}

string string_to_upper(const string STR) {
    string str;
    string result;

    for(int i = 0; i < STR.length(); i++){
        str = toupper(STR.at(i));
        result = result.append(str);
    }
    // TODO 14: convert all characters to upper case
    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result;
    if (LHS == RHS){
        result = 0;
    }
    if (LHS  < RHS) {
        result = -1;
    }
    if (LHS > RHS) {
        result = 1;
    }
    // TODO 15: compare LHS and RHS
    return result;
}