
#include "functions.h"


void display_file(fstream &input_file){

    string line_of_text;
    int line_count = 0;

    while(getline(input_file, line_of_text)){

        if(line_of_text == "\0"){
            cout << line_count << ": " << "[ blank Line ]" << endl;
        }
        else {
            cout << line_count << ": " << line_of_text;
            cout << " [" << count_non_space(line_of_text) << " letters, ";
            cout << count_spaces(line_of_text) << " spaces, ";
            cout << count_words(line_of_text) << " words]";
            cout << endl;
        }

        line_count++;
    }
    
}


int count_non_space(string line_of_text){
    
    int char_count = 0;

    for(int i = 0; i < line_of_text.length(); i++){
        if (verify_char(line_of_text[i])){
            char_count++;
        }
    }

    return char_count;
}


int count_spaces(string line_of_text){
    
    int space_count = 0;

    for(int i = 0; i < line_of_text.length(); i++){
        if (line_of_text[i] == ' '){
            space_count++;
        }
    }

    return space_count;
}


int count_words(string line_of_text){

    int word_count = 0;
    string text;
    bool on_word = false;
    bool on_space = false;

    for(int i = 0; i < line_of_text.length(); i++){

        if (verify_char(line_of_text[i]) && on_word == false){
            word_count++;
            on_word = true;
            on_space = false;
        }

        if(line_of_text[i] == ' ' && on_space == false){
            on_word = false;
            on_space = true;
        }
    }

    return word_count;
}


bool verify_char(char char_value){

    bool upper_case = char_value >= 65 && char_value <= 90;
    bool lower_case = char_value >= 97 && char_value <= 122;
    bool is_char;

    if (upper_case){
        is_char = true;
    }
    else if (lower_case){
        is_char = true;
    }
    else {
        is_char = false;
    }

    return is_char;
}