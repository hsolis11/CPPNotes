#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::fstream;
using std::cout;
using std::endl;


void display_file(fstream&);
int count_non_space(string);
int count_spaces(string);
int count_words(string);
bool verify_char(char);

#endif /* FUNCTIONS_H */
