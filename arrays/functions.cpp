/**********************************************************************************
 * Name: Hector Solis
 * Coding 04
 * Purpose: Accept one-and-only-one parameter from the command line, which must
 * be a positive (above 0) integer, and will create two integer arrays of that
 * size, randomly fill them, display them, add them, and get thier sum and average.
 **********************************************************************************/

#include "functions.h"


int sum_array(int* input_array, const int array_size){

    int total_sum = 0;

    for(int i = 0; i < array_size; i++){
        total_sum += input_array[i];
    }

    return total_sum;
}

float avg_array(int* input_array, const int array_size){

    return (float) sum_array(input_array, array_size)/array_size;
}

void add_arrays(int* result, int* array1, int* array2, const int array_size){

    for(int i = 0; i < array_size; i++){

        result[i] = array1[i] + array2[i];
    }
}

void display_array(int* input_array, const int array_size){

    cout << "[";
    for(int i = 0; i < array_size; i++){

        if(i == (array_size -1)){
            cout << input_array[i] << "]" << endl;    
        } else {
            cout << input_array[i] << " ";
        }
    }

}

void fill_random(int* input_array, const int array_size){

    for(int i = 0; i < array_size; i++){
        input_array[i] = (rand() % (MAX - MIN)) + MIN;
    }

}

bool is_positive_integer(char* value){

    bool not_int = false;

    if(strlen(value) > 0){
        for(int i = 0; i < strlen(value); i++){
            if(!(value[i] >= 48 && value[i] <= 57)){
                not_int = true;
            }
        }
    }
    
    return !(not_int);
}