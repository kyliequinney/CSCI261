#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

int print_file_options(string& userChoice);
int print_operation_options(int& editChoice);
int read_header_information(ifstream input, string line, string& dimensions, string& maxVal, string& fileType);

#endif
