#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

string prompt_user_for_filename() {
    //set file input name as user input
    cout << "Please enter a file name: " << endl;
    string fileIn;
    cin >> fileIn;
    return fileIn;
}

int open_file(ifstream &input, string fileName){
    //check if file opened successfully
    input.open(fileName, ios :: in);
    if(input.fail()){
        return 0;
    }
    else 
        return 1;
}
vector <string> read_words_from_file(ifstream &fileIn){
    //read in lines of file and add each word to vector
    vector <string> words;
    string temp;
    string line;
    while(getline(fileIn, line)){
        istringstream iss(line);
        while(iss >> temp){
            words.push_back(temp.c_str());
        }
    }
    return words;
}
void remove_punctuation(vector<string> &vec, string punc){
    //use nested loops to access each char and remove it if it is on the punc string
    for (int p=0; p <= punc.length(); p++){
        for(int i = 0; i < vec.size(); i++){
            for (int j = 0; j < vec[i].length(); j++){
                if (vec[i][j] == punc[p]){
                    vec[i].erase(j,1);
                }
            }
        }
    }
}

void capitalize_words(vector <string> &vec){
    //nested loops to access each char and capitalize it
    for ( int i= 0; i< vec.size(); i++){
        string s = vec[i];
        for (string &s : vec){

            for (char &c : s) {
                c = toupper(c);
            }
        }
    }
}

int count_words (vector<string> vec, string word){
    //iterate through vec to count each word in the vec
    int count = 0;
    for (int i =0; i < vec.size(); i++){
        if(word == vec.at(i)){
            count++;
        }
    }

    return count;
}
vector <string> filter_unique_words(vector <string> vec){
    //use count_words function to see how many occurances of each word there are and append to uniqueVec if it only occurs once
    vector <string> uniqueWords;
    for(int i = 0; i < vec.size(); i++){
        if(count_words(vec, vec.at(i)) == 1){
            uniqueWords.push_back(vec.at(i));
        }
    }
    return uniqueWords;
}
void count_letters(unsigned int letterCounts[], vector <string> vec){
    //nested loop to access each char of each word
    //calculate which index the char would belong to and add 1 to that index
    for(int i = 0; i < vec.size(); i++){
        for(int j=0; j < vec.at(i).size(); j++){
            char letter = vec[i][j];
            int idx = letter - 'A';
            letterCounts[idx]++;
        }
    }
}

//need columns aligned to the right
void print_letter_counts(unsigned int letters[]){
    //print occurance of each letter next to the letter itself
    for(int i = 0; i < 26; i++){
        int currentLetter = i + 'A';
        char charCurrentLetter = currentLetter;
        cout<< charCurrentLetter << ' ' << letters[i] << endl;
    }
}
void print_max_min_letter(unsigned int letters[]){
    //find the max and min letter (by occurance) and print along with the percentage that it shows up
    int max = letters[0];
    char maxChar;
    //find max by comparing each letter and if new letter is bigger, change letter to equal it
    for(int i = 1; i < 26; i++){
        if (max < letters[i]){
            max = letters[i];
            maxChar = i + 'A';
        }
    }
    
    char minChar;
    //same concept as max but use when new letter is smaller
    int min = letters[0];
    for(int i = 0; i < 26; i++){
        if (min > letters[i]){
            min = letters[i];
            minChar = i + 'A';
        }
    }
    int totalLetters;
    //iterate through count of all letters and add to new variable to find total
    for(int i =0; i<26; i++){
        totalLetters += letters[i];
    }
    double conversion = 100.0/ totalLetters;

    //need to be properly aligned and need to show all letters when there is a tie
    cout << "Least Frequent Letter: " << minChar << " " << min << " (" << fixed << setprecision(3) <<(conversion)*min << "%)" << endl;
    cout << " Most Frequent Letter: " << maxChar << " " << max << " (" << fixed << setprecision(3) <<(conversion)*max << "%)" << endl;
}