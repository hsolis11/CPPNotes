#include "functions.h"

int string_length(const char *str){
    //str value will be passed as an array and will be able to be looped
    //one element at a time.

    //initialize the counter at zero.
    int counter = 0;


    while(str[counter] != '\0'){
        //while loop through each character until you encounter '\0'
        counter += 1;
    }//end while loop

    return counter;
}//end string_length