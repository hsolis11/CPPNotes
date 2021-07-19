/**************************************
 * Name: Hector Solis
 * Coding 07
 * Purpose: Program will create a "list" like object 
 * that behaves similarly to the List object in Python.
 **************************************/

#include "main.h"

int main(int argc, char** argv) {
    /***********************************
     * DO NOT MODIFY THIS FILE OTHER THAN
     * TO ADD YOUR COMMENT HEADER AND
     * UNCOMMENT THINGS AS YOU COMPLETE
     * THE FUNCTIONALITY OF YOUR LIST OBJECT
     ***********************************/

    /* This will create a "list" of size LISTSIZE
     * and initialize it to all zeros */
    cout << "create and initialize mylist" << endl;
    MyList mylist(LISTSIZE);
    mylist.printArray();
    cout << endl;

    /* This will set the list to all 50 */
    cout << "set mylist to all 50" << endl;
    mylist.setArray(50);
    mylist.printArray();
    cout << endl;

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers -2 to 4" << endl;
    mylist.setRandom(-2,4);
    mylist.printArray();
    cout << endl;

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers 4 to 4" << endl;
    mylist.setRandom(4,4);
    mylist.printArray();
    cout << endl;

    /* This will succeed and set the array to the
     * random 1-100 values */
    cout << "attempt to set to random numbers 1 to 100" << endl;
    mylist.setRandom(1,100);
    mylist.printArray();
    cout << endl;

    /* This will succeed and set the array to the
     * random 500-1000 values */
    cout << "attempt to set to random numbers 500 to 1000" << endl;
    mylist.setRandom(1000,500);
    mylist.printArray();
    cout << endl;

    /* These next two sets will succeed and set the 1st and last
     * elements to 1000 and 2000 respectively */
    if(mylist.setElement(1000, 0)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(2000, LISTSIZE-1)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    /* These next two sets will fail and leave the array unmodified */
    if(mylist.setElement(9999, -1)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(9999, LISTSIZE)){
       cout << "Element Set" << endl;
    } else {
       cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    cout << "Testing new and/or modified code..." << endl;
    cout << endl;

    /* print out the array using getElement() */
    cout << "printing the array element by element using: int getElement(int);" << endl;
    cout << "(going one too far to test out of range)" << endl;
    try{
       for(int i=0; i<LISTSIZE+1; i++){
       cout << mylist.getElement(i) << endl;
       }
    } catch(int e){
       cout << "error, out of range" << endl;
    }
    cout << endl;
    

    /* this will fail and return 0 */
    cout << "attempting to get element 4000 using: int getElement(int);" << endl;
    try{
       int element = mylist.getElement(4000);
       cout << element << endl;
    } catch(int e){
       cout << "error, out of range" << endl;
    }
    cout << endl;


    cout << "printing the array element by element using: bool getElement(int, int*);" << endl;
    cout << "(going one too far to test out of range)" << endl;
    int element;
    for(int i=0; i<LISTSIZE+1; i++){
       if(mylist.getElement(i, &element)){
          cout << mylist.getElement(i) << endl;
       } else {
          cout << "error, out of range" << endl;
       }
    }
    cout << endl;


    cout << "attempting to get element 4000 using: bool getElement(int, int*);" << endl;
    // get element 4000 and display "error, out of range"
    if(mylist.getElement(4000, &element)){
       // will print if no error
       cout << element << endl;
    } else {
       // will print if error
       cout << "error, out of range" << endl;
    }

    cout << endl;

    /* this will fail */
    cout << "resizing array to LISTSIZE" << endl;
    // resize array to LISTSIZE
    if(mylist.resizeArray(LISTSIZE)){
       cout << "resized..." << endl;
       mylist.printArray();
    } else {
       cout << "failed to resize" << endl;
    }
    cout << endl;
    
    /* resize to LISTSIZE+5 */
    cout << "resizeing array to LISTSIZE+5" << endl;
    if(mylist.resizeArray(LISTSIZE+5)){
       cout << "resized..." << endl;
       mylist.printArray();
    } else {
       cout << "failed to resize" << endl;
    }
    cout << endl;

    /* atemptint to resize to -5 */
    cout << "resizing array to LISTSIZE-5" << endl;
    if(mylist.resizeArray(LISTSIZE-5)){
       cout << "resized..." << endl;
       mylist.printArray();
    } else {
       cout << "failed to resize" << endl;
    }
    cout << endl;

    /* this will fail */
    cout << "resizing array to 0" << endl;
    if(mylist.resizeArray(0)){
       cout << "resized..." << endl;
       mylist.printArray();
    } else {
       cout << "failed to resize" << endl;
    }

    cout << endl;

    cout << "------ Begin sort testing --------" << endl;
    

    cout << endl;
    cout << "reset array to 10 with values of 0: sorts the array" << endl;
    mylist.resizeArray(LISTSIZE);
    mylist.setArray(0);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


   /* test if sorted flag sets to false with random numbers */
   cout << "set array to random integers: unsorts the array " << endl;
    mylist.setRandom(1, 100);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    /* test if sorted flag changes when sorted */
    cout << "sort array in ascending order" << endl;
    mylist.sort();
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    /* test if setElement will stay sort array */
    cout << "[Testing if setElement can stay sorted]" << endl;
    cout << "setElement 9 equal to 100: array stays sorted" << endl;
    mylist.setElement(100, LISTSIZE - 1);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


   cout << "setElement 0 equal to 0: array stays sorted" << endl;
    mylist.setElement(0, 0);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    cout << "setElement 4 equal to a value between element 3 and 5: array stays sorted" << endl;
    int index3 = mylist.getElement(3);
    int index4 = mylist.getElement(5);
    int middleValue = index3 + ((index4 - index3)/2);
    mylist.setElement(4, middleValue);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    cout << "[Testing if setElement unsorts properly]" << endl;
   cout << "setElement 9 equal to 1: unsorts the array" << endl;
    mylist.setElement(1, LISTSIZE - 1);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    cout << "sorting array" << endl;
    mylist.sort();
    mylist.printArray();
    cout << endl;

    cout << "setElement 4 equal to element 5 + 1: unsorts the array" << endl;
    index4 = mylist.getElement(5);
    middleValue = index4 + 1;
    mylist.setElement(middleValue, 4);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    cout << "sorting array" << endl;
    mylist.sort();
    mylist.printArray();
    cout << endl;

    cout << "setElement 0 equal to 100: unsorts the array" << endl;
    mylist.setElement(100, 0);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;

    
    /* test if element is sorted after resizing down */
    cout << "resize array down to 7: stays unsorted" << endl;
    mylist.resizeArray(7);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    cout << "sort array in ascending order" << endl;
    mylist.sort();
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    cout << "resize array down to 5: stays sorted" << endl;
    mylist.resizeArray(5);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    /* test if element is sorted after resizing down */
    cout << "resize array to LISTSIZE: unsorts the array" << endl;
    mylist.resizeArray(LISTSIZE);
    if(mylist.getSorted()){
       cout << "sorted array" << endl;
    } else{
       cout << "unsorted array" << endl;
    }
    mylist.printArray();
    cout << endl;


    return 0;
}