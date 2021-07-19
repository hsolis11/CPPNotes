/*********************
* Name: Hector Solis
* Coding 02
* Purpose: My command line analyzer
**********************/

#include "main.h"

int main(int argc, char** argv) {
    cout << "My Command line analyzer..." << endl;
    cout << "The number of command line parameters are: " << argc << endl;
    cout << "The length of the name of the program is: " << string_length(argv[0]) << endl; //I'm not sure where the five is from
    
    if(argc > 1){
        for (int count = 1; count < argc; count++){
            //for loop through each argument passed as a parameter and keep count.
            cout << "The length of the parameter " << count << " is " << string_length(argv[count]) << endl;
            
        }//end for loop
        
    }//end if

    return 0;
}//end main