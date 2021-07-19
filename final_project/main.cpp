/**************************************
 * Name: Hector Solis
 * Final Project
 * Purpose: String class similar to what you find
 * in Python or C++
 **************************************/

#include "main.h"

int main(int argc, char** argv){

    MyString mystring("H3ll0 World!");
    cout << "initial string" << endl;
    mystring.printmystring();
    cout << "array length = " << mystring.length() << endl;
    cout << endl;
    cout << endl;

    // Test the upper function
    cout << "[Test .upper method]" << endl;
    cout << "set string to upper(not affect internally)" << endl;
    char *test = mystring.upper();

    for(int i = 0; i < mystring.length()+1; i++){
        cout << test[i];
    }
    cout << endl;
    cout << "internal string is uneffected" << endl;
    mystring.printmystring();

    cout << "set string to upper internally" << endl;
    mystring.upper(true);
    mystring.printmystring();
    cout << endl;
    cout << endl;

    // Test the lower function
    cout << "[Test .lower method]" << endl;
    cout << "set string to lower(not affect internally)" << endl;
    test = mystring.lower();
    for(int i = 0; i < mystring.length()+1; i++){
        cout << test[i];
    }
    cout << endl;
    cout << "internal string remains unaffected" << endl;
    mystring.printmystring();

    cout << "set string to lower internally" << endl;
    mystring.lower(true);
    mystring.printmystring();
    cout << endl;
    cout << endl;


    // Test reverse method
    cout << "[Test .reverse method]" << endl;
    cout << "set string to reverse(not affect internally)" << endl;
    test = mystring.reverse();
    for(int i = 0; i < mystring.length()+1; i++){
        cout << test[i];
    }
    cout << endl;
    cout << "internal string remains unaffected" << endl;
    mystring.printmystring();
    cout << "set string to reverse internally" << endl;
    mystring.reverse(true);
    mystring.printmystring();
    cout << endl;
    cout << endl;


    // Test clear method
    cout << "[Test .clear method]" << endl;
    cout << "clear mystring array" << endl;
    mystring.clear();
    mystring.printmystring();
    cout << "array length = " << mystring.length() << endl;
    cout << endl;
    cout << endl;


    // Test set method
    cout << "[Test .set method]" << endl;
    cout << "set string to a new value" << endl;
    mystring.set("I am back!");
    mystring.printmystring();
    cout << "array length = " << mystring.length() << endl;
    cout << endl;
    cout << endl;


    // Test substring method
    cout << "[Test .substring method]" << endl;
    cout << "attempt to substring negative values" << endl;
    try{
        test = mystring.substring(-9, mystring.length());
        for(int i = 0; i < mystring.length()+1; i++){
            cout << test[i];
        }
        cout << endl;
    } catch(int e){
        cout << "error, out of range" << endl;
    }
    cout << "attempt to substring bigger than array length" << endl;
    try{
        test = mystring.substring(0, mystring.length()+5);
        for(int i = 0; i < mystring.length()+1; i++){
            cout << test[i];
        }
        cout << endl;
    } catch(int e){
        cout << "error, out of range" << endl;
    }
    cout << "substring values 5 and 5 return 'b'" << endl;
    test = mystring.substring(5, 5);
    for(int i = 0; i < mystring.length()+1; i++){
        cout << test[i];
    }
    cout << endl;
    cout << "substring values 5 and 9 return 'back!'" << endl;
    test = mystring.substring(5, 9);
    for(int i = 0; i < mystring.length()+1; i++){
        cout << test[i];
    }
    cout << endl;
    cout << "internal string remains unaffected" << endl;
    mystring.printmystring();
    cout << "substring values 4 and 0 return 'I am '" << endl;
    test = mystring.substring(4, 0);
    for(int i = 0; i < mystring.length()+1; i++){
        cout << test[i];
    }
    cout << endl;
    cout << "internal string remains unaffected" << endl;
    mystring.printmystring();
    cout << "substring passed true changes internally" << endl;
    mystring.substring(5, 9, true);
    mystring.printmystring();
    cout << "array length = " << mystring.length() << endl;
    cout << endl;
    cout << endl;


    // Test cat method
    cout << "[Test .cat method]" << endl;
    cout << "adding 'Hello World!' string using cat" << endl;
    mystring.cat("Hello World!");
    mystring.printmystring();
    cout << "array length = " << mystring.length() << endl;
    cout << endl;
    cout << endl;


    // Test count method
    cout << "[Test .count method]" << endl;
    mystring.printmystring();
    cout << "get count of char 'l' in ";
    mystring.printmystring();
    cout << "Total count = " << mystring.count('l') << endl;
    cout << "get count of char 'z' not listed in ";
    mystring.printmystring();
    cout << "Total count = " << mystring.count('z') << endl;
    cout << endl;
    cout << endl;


    // Test empty string handling
    cout << "[testing with an empty mystring]" << endl;
    cout << endl;

    MyString mystring2;

    cout << mystring2.length() << endl;
    cout << "run upper() on empty array" << endl;
    mystring2.upper();
    mystring2.upper(true);
    cout << "run lower() on empty array" << endl;
    mystring2.lower();
    mystring2.lower(true);
    cout << "run reverse() on empty array" << endl;
    mystring2.reverse();
    mystring2.reverse(true);
    cout << "run clear() on empty array" << endl;
    mystring2.clear();
    cout << "set empty array to 'hello world!'" << endl;
    mystring2.set("hello world!");
    mystring2.printmystring();
    cout << "array length = ";
    cout << mystring2.length() << endl;
    cout << "concatenate 'hello again!' using .cat" << endl;
    mystring2.cat("hello again!");
    mystring2.printmystring();
    cout << "array length = ";
    cout << mystring2.length() << endl;
    
    return 0;
}