#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H

#include <string>
#include <locale>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
/**
 * @brief set file input name as user input
 * 
 * @return string 
 */
string prompt_user_for_filename();

/**
 * @brief check if file opened successfully
 * 
 * @return int 
 */
int open_file(ifstream&, string);

/**
 * @brief read in lines of file and add each word to vector
 * 
 * @return vector <string> 
 */
vector <string> read_words_from_file( ifstream& );

/**
 * @brief remove all chars given in string
 * 
 */
void remove_punctuation(vector<string>& , string);

/**
 * @brief capitalize each letter in each word
 * 
 */
void capitalize_words(vector <string>&);

/**
 * @brief create vector of only words that occur once
 * 
 * @return vector <string> 
 */
vector <string> filter_unique_words(vector <string>);

/**
 * @brief count the occurance of each letter
 * 
 * @param letterCounts 
 */
void count_letters(unsigned int letterCounts[], vector<string>);

/**
 * @brief print occurance of each letter along with the letter it corresponds to
 * 
 * @param letters 
 */
void print_letter_counts(unsigned int letters[]);

/**
 * @brief print letter that occurs the least and the most along with the percentage that they occur
 * 
 * @param letters 
 */
void print_max_min_letter(unsigned int letters[]);

/**
 * @brief count how many words are in the vec
 * 
 * @return int 
 */
int count_words();

#endif