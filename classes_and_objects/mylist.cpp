/**************************************
 * Name: Hector Solis
 * Coding 07
 * Purpose: Program will create a "list" like object 
 * that behaves similarly to the List object in Python.
 **************************************/

#include "mylist.h"

// constructor
MyList::MyList(int size) {
    srand(time(NULL));  // call only once!

    length = (size < 1)? DEFAULT_SIZE: size;
    array = new int[length];

    setArray(0);
    sorted = true;
}

// destructor
MyList::~MyList() {

    delete[] array;
}

void MyList::printArray(){
    
    cout << "[";
    for(int i = 0; i < length; i++) {

        if(i == (length - 1)){
            cout << array[i] << "]" << endl;
        } else {
            cout << array[i] << " ";
        }
    }
}

void MyList::setArray(int set_value){
    
    for(int i = 0; i < length; i++) {
        array[i] = set_value;
    }

    sorted = true;
}

void MyList::setRandom(int value1, int value2){

    // differentiate min and max
    int min = (value1 < value2)? value1: value2;
    int max = (value1 < value2)? value2: value1;

    bool isNegative = min < 0 || max < 0;
    bool isSame = (max - min) == 0;

    if (isNegative || isSame){
        min = RMIN;
        max = RMAX;
    }

    for(int i = 0; i < length; i++) {
        array[i] = (rand() % (max+1 - min)) + min;
    }

    sorted = false;
}

bool MyList::setElement(int value, int index){

    bool updated = false;

    if((index < length) && (index > -1)){
        array[index] = value;
        updated = true;
    }

    if(updated){

        if(index == 0){
            if(!(value <= array[1])){
                sorted = false;
            }
        } else if (index == length -1){
            if(!(array[index - 1] <= value)){
                sorted = false;
            }
        } else if (!(array[index - 1] < value && value < array[ index + 1])) {
            sorted = false;
        }
    }

    return updated;
}

int MyList::getElement(int index){

    int value;

    if (index < length){
        value = array[index];
    } else {
        throw 0;
    }

    return value;
}


bool MyList::getElement(int index, int *iptr){

    bool retrieved = false;

    if (index < length){
        *iptr = array[index];
        retrieved = true;
    }

    return retrieved;
}

bool MyList::resizeArray(int newSize){
    bool resized = false;
    
    if ((newSize >= 1) && (newSize != length)){

        int *newArray = new int[newSize];
        
        if (newSize > length){

            for(int i=0; i<newSize; i++){
                
                if (i < length){
                    newArray[i] = array[i];
                    
                } else {
                    newArray[i] = 0;
                    
                }
            }
            sorted = false;
        }
        
        if (newSize < length){
            for(int i=0; i<newSize; i++){
                newArray[i] = array[i];
            }
        }

        length = newSize;
        delete[] array;
        array = newArray;
        resized = true;

    }

    return resized;
}


int MyList::getLength(){
    
    return length;
}


bool MyList::getSorted(){
    
    return sorted;
}


void MyList::sort(){

    if(!sorted){
        bool swapped = true;

        for(int maxElement = getLength() -1; maxElement > 0 && swapped; maxElement--){
            swapped = false;
            for(int i = 0; i < maxElement; i++){
                if(array[i] > array[i+1]){
                    swap(&array[i], &array[i+1]);
                    swapped = true;
                }
            }
        }
        sorted = true;
    }
}


void MyList::swap(int *n1, int *n2){
    
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}