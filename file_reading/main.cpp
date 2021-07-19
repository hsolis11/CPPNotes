/*************************************
 * Name: Hector Solis
 * Coding 03
 * Purpose: Read a file and out put each line with statistics
 ************************************/

#include "main.h"

int main(int argc, char** argv) {

    fstream inputFile;

    if(argc == 2){
        inputFile.open(argv[1]);

        // testing if file opened successfully
        if(inputFile){
            display_file(inputFile);
            inputFile.close();
        }
        else {
            cout << "invalid filename: badfile" << endl;
        }
    } else {
        cout << "usage: a.out filename" << endl;
    }

    return 0;
}