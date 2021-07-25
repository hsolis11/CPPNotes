/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    Data *temp_data = new Data;
    cout << endl;

    cout << "Testing isEmpty() on an empty stack" << endl;
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is not empty" << endl;
    }
    cout << endl;

    cout << "Testing peek() on an empty stack" << endl;
    if(stack.peek(temp_data)){
        cout << "peek value on an empty string is " << temp_data << endl;
    } else {
        cout << "error: Underflow" << endl;
    }
    cout << endl;

    cout << "Testing pop() on an empty stack" << endl;
    if(stack.pop(temp_data)){
        cout << "pop value on an empty string is " << temp_data << endl;
    } else {
        cout << "error: Underflow" << endl;
    }
    cout << endl;

    
    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */
    cout << "[Testing push]" << endl << endl;
    cout << "Pushing negative numbers" << endl;
    for(int i = 0; i < number_test_cases; i++){
        int num = (rand() % 1000) - 2000;
        string test_string = "test string";
        if(stack.push(num, test_string)){
            cout << "pushed " << num << ": " << test_string << endl;
        } else {
            cout << "Error: Overflow or invalid data type, not able to push " << num << ": " << test_string << endl;
        }
    }
    if(stack.peek(temp_data)){
        cout << "Peek data " << temp_data->id << ": " << temp_data->information << endl;
    } else {
        cout << "Error: Not able to peek" << endl;
    }

    if(stack.isEmpty()){
        cout << "stack is empty" << endl << endl;
    } else {
        cout << "stack is not empty" << endl << endl;
    }
    cout << endl << endl;


    cout << "Pushing empty string" << endl;
    for(int i = 0; i < number_test_cases; i++){
        int num = rand() % 1000;
        string test_string = "";
        if(stack.push(num, test_string)){
            cout << "pushed " << num << ": " << test_string << endl;
        } else {
            cout << "Error: Overflow or invalid data type, not able to push " << num << ": " << test_string << endl;
        }
    }
    if(stack.peek(temp_data)){
        cout << "Peek data " << temp_data->id << ": " << temp_data->information << endl;
    } else {
        cout << "Error: Not able to peek" << endl;
    }

    if(stack.isEmpty()){
        cout << "stack is empty" << endl << endl;
    } else {
        cout << "stack is not empty" << endl << endl;
    }
    cout << endl << endl;


    cout << "Testing push of test cases" << endl << endl;
    for(int i = 0; i < number_test_cases; i++){

        if(stack.push(ids[i], data[i])){
            cout << "Pushed " << ids[i] << ": " << data[i] << endl;
        } else {
            cout << "Error: Overflow or invalid type, not able to push " << ids[i] << ": " << data[i] << endl;
        }

        if(stack.peek(temp_data)){
            cout << "Peek data " << temp_data->id << ": " << temp_data->information << endl;
        } else {
            cout << "Error: Not able to peek" << endl;
        }

        if(stack.isEmpty()){
            cout << "stack is empty" << endl << endl;
        } else {
            cout << "stack is not empty" << endl << endl;
        }

    }
    cout << endl;

    cout << "[Testing pop of test cases]" << endl << endl;
    for(int i = 0; i < number_test_cases; i++){

        if(stack.peek(temp_data)){
            cout << "Peek data " << temp_data->id << ": " << temp_data->information << endl;
        } else {
            cout << "Error: Underflow not able to peek" << endl;
        }

        if(stack.pop(temp_data)){
            cout << "Popped " << temp_data->id << ": " << temp_data->information << endl;
        } else {
            cout << "Error: Underflow not able to pop" << endl;
        }

        if(stack.isEmpty()){
            cout << "stack is empty" << endl << endl;
        } else {
            cout << "stack is not empty" << endl << endl;
        }
    }
    cout << endl;

    cout << "[Randomized testing on empty stack]" << endl << endl;
    while(stack.pop(temp_data)){
    }
    for(int i=0; i < 100; i++){
        int test = rand() % 2;
        int num = (rand() % 100) - 50;
        string empty_string = "";
        string test_string = "This is a test string";

        if(test == 0){
            if(num > 25){test_string = "";}
            if(stack.push(num, test_string)){
                cout << "pushed " << num << ": " << test_string << endl;
            } else {
                cout << "Error: Overflow or invalid data type, not able to push " << num << ": " << test_string << endl;
            }
            if(stack.peek(temp_data)){
                cout << "Peek data " << temp_data->id << ": " << temp_data->information << endl;
            } else {
                cout << "Error: Not able to peek" << endl;
            }

            if(stack.isEmpty()){
                cout << "stack is empty" << endl << endl;
            } else {
                cout << "stack is not empty" << endl << endl;
            }
        } else if (test == 1){
            if(stack.peek(temp_data)){
                cout << "Peek data " << temp_data->id << ": " << temp_data->information << endl;
            } else {
                cout << "Error: Underflow not able to peek" << endl;
            }

            if(stack.pop(temp_data)){
                cout << "Popped " << temp_data->id << ": " << temp_data->information << endl;
            } else {
                cout << "Error: Underflow not able to pop" << endl;
            }

            if(stack.isEmpty()){
                cout << "stack is empty" << endl << endl;
            } else {
                cout << "stack is not empty" << endl << endl;
            }
        }
    }

    delete temp_data;
    return 0;
}
