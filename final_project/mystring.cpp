/**************************************
 * Name: Hector Solis
 * Final Project
 * Purpose: String class similar to what you find
 * in Python or C++
 **************************************/

#include "mystring.h"

MyString::MyString(){

    arraylength = 0;
    array = new char[1];
    array[0] = '\0';
}

MyString::MyString(const char* chardata){
    
    int counter = 0;
    bool endofstring = false;

    while(!endofstring){
        
        if(chardata[counter] == '\0'){
            endofstring = true;
        }
        counter++;
    }

    arraylength = counter;
    array = new char[arraylength];
    
    for(int i=0; i<arraylength; i++){
        array[i] = chardata[i];
    }
}

MyString::~MyString(){
    delete[] array;
}


char * MyString::upper(bool internal){
    
   char *upperCase = new char[arraylength];

   for(int i=0; i < arraylength; i++) {
       if((int) array[i] > 96 && (int) array[i] < 123 ){
           upperCase[i] = (char) ((int) array[i] - 32);
       } else {
           upperCase[i] = array[i];
       }
   }

   if(internal){
       delete[] array;
       array = upperCase;
   }
    
    return upperCase;
}


char * MyString::lower(bool internal){
    
    char *lowerCase = new char[arraylength];

   for(int i=0; i < arraylength; i++) {
       if((int) array[i] > 64 && (int) array[i] < 91 ){
           lowerCase[i] = (char) ((int) array[i] + 32);
       } else {
           lowerCase[i] = array[i];
       }
   }

   if(internal){
       delete[] array;
       array = lowerCase;
   }
    
    return lowerCase;
}


char * MyString::reverse(bool internal){
    
   char *reverse = new char[arraylength];
   int temp = 0;

   for(int i=length(); i > -1; i--) {
       reverse[temp] = array[i];
       temp++;
   }

   if(internal){
       delete[] array;
       array = reverse;
   }
    
    return reverse;
}


void MyString::clear(){
    
    arraylength = 0;
    array = new char[1];
    array[0] = '\0';
}


void MyString::set(const char* chardata){
    
    int counter = 0;
    bool endofstring = false;

    while(!endofstring){
        
        if(chardata[counter] == '\0'){
            endofstring = true;
        }
        counter++;
    }

    arraylength = counter;
    array = new char[arraylength];
    
    for(int i=0; i<arraylength; i++){
        array[i] = chardata[i];
    }

}


int MyString::length(){
    
    int length = 0;

    if(arraylength > 0){
        length = arraylength-1;
    }

    return length;
}


char * MyString::substring(int num1, int num2, bool internal){
    
    int start, end, sub_length;

    bool isnegative = num1 < 0 || num2 < 0;
    bool outofrange = num1 > arraylength || num2 > arraylength;

    if(isnegative || outofrange){
        throw 0;
    }


    if(num1 < num2){
        start = num1;
        end = num2;
        sub_length = (end + 1) - start; 
    } else if (num1 > num2){
        start = num2;
        end = num1;
        sub_length = (end + 1) - start;
    } else {
        start = num1;
        end = num2;
        sub_length = 1;
    }


    char *substring = new char[sub_length];
    int temp = 0;

    for(int i=start; i <= end; i++) {
       substring[temp] = array[i];
       temp++;
    }

    if(internal){
       delete[] array;
       array = substring;
       arraylength = sub_length+1;
    }
    
    return substring;

}


void MyString::cat(const char* chardata){
    
    int counter = 0;
    bool endofstring = false;

    while(!endofstring){
        
        if(chardata[counter] == '\0'){
            endofstring = true;
        }
        counter++;
    }
    int temp = arraylength;

    arraylength = arraylength + counter - 1;
    char *new_array = new char[arraylength];
    
    for(int i=0; i<arraylength; i++){

        if(i < temp){
            new_array[i] = array[i];
        } else {
            new_array[i] = chardata[i-temp];
        } 
    }
    delete[] array;
    array = new_array;
}


int MyString::count(char x){
    
    int counter = 0;

    for(int i=0; i < arraylength; i++) { 
        if(array[i] == x){
            counter++;
        }
    }
    return counter;
}

void MyString::printmystring(){
    
    for(int i = 0; i < arraylength; i++) {
        cout << array[i];
    }
    cout << endl;
}