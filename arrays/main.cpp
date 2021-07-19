/**********************************************************************************
 * Name: Hector Solis
 * Coding 04
 * Purpose: Accept one-and-only-one parameter from the command line, which must
 * be a positive (above 0) integer, and will create two integer arrays of that
 * size, randomly fill them, display them, add them, and get thier sum and average.
 **********************************************************************************/

#include "main.h"

int main(int argc, char** argv) {
    
    srand(time(NULL));

    string usage_msg = "usage: a.out n (where n is a number above 0)";

    if(argc == 2){

        if(is_positive_integer(argv[1])) {

            int SIZE = atoi(argv[1]);

            int *numbers1, 
                *numbers2, 
                *answer;

            numbers1 = new int[SIZE];
            numbers2 = new int[SIZE];
            answer = new int[SIZE];

            fill_random(numbers1, SIZE);
            fill_random(numbers2, SIZE);

            cout << "the two arrays created are:" << endl;
            display_array(numbers1, SIZE);
            display_array(numbers2, SIZE);

            cout << endl;

            cout << "adding the arrays together:" << endl;
            add_arrays(answer, numbers1, numbers2, SIZE);
            display_array(answer, SIZE);

            cout << endl;

            cout << "The sum and avg of the arrays:" << endl;

            cout << "array 1 sum: " << sum_array(numbers1, SIZE) << endl;
            cout << "array 1 average: " << avg_array(numbers1, SIZE) << endl;

            cout << endl;

            cout << "array 2 sum: " << sum_array(numbers2, SIZE) << endl;
            cout << "array 2 average: " << avg_array(numbers2, SIZE) << endl;

            delete[] numbers1;
            delete[] numbers2;
            delete[] answer;

        } else {
            cout << usage_msg << endl;
        }

    } else {
        cout << usage_msg << endl;
    }


    return 0;
}
