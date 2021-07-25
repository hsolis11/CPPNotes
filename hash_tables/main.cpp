/*****************************************
 * Name: Hector Solis
 * Coding 06
 * Purpose: Create a Hash Table class/object 
 * with the standard struct using an int and
 * a string for 'data'
 *****************************************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable hashtable;
    
    // show it is empty by calling getCount and printTable
    cout << endl;
    cout << "***********************************" << endl;
    cout << "* Showing empty hash table object *" << endl;
    cout << "***********************************" << endl;
    cout << endl;
    cout << "Verify hashtable is empty" << endl;
    cout << "hashtable count = " << hashtable.getCount() << endl;
    cout << "print hashtable " << endl;
    hashtable.printTable();
    
    cout << endl;
    // try and put ALL the test data into the table and show what happens
    cout << endl;
    cout << "***************************************" << endl;
    cout << "* Adding ALL test data into hashtable *" << endl;
    cout << "***************************************" << endl;
    cout << endl;
    
    for (int i = 0; i < testdatasize; i++){
        cout << "adding " << ids[i] << " : " << strs[i];
        if(hashtable.insertEntry(ids[i], &strs[i])){
            cout << " SUCCESS" << endl;
            cout << "\tnew count = " << hashtable.getCount() << endl;
            cout << "\tget data " << hashtable.getData(ids[i]) << endl;
        } else {
            cout << " FAILED" << endl;
            cout << "\tcount = " << hashtable.getCount() << " (should not change)" << endl;
            cout << "\tget data " << hashtable.getData(ids[i]) << endl;
        }
        
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << "**********************" << endl;
    cout << "* Printing hashtable *" << endl;
    cout << "**********************" << endl;
    cout << endl;
    hashtable.printTable();
    cout << endl;

    cout << endl;
    cout << "*****************************************" << endl;
    cout << "* Removing ALL test data from hashtable *" << endl;
    cout << "*****************************************" << endl;
    cout << endl;

    for (int i = 0; i < testdatasize; i++){
        cout << "removing Entry " << ids[i] << ": "<< hashtable.getData(ids[i]);
        if(hashtable.removeEntry(ids[i])){
            cout << " SUCCESS" << endl;
            cout << "\tnew count = " << hashtable.getCount() << endl;
            cout << "\tget data " << hashtable.getData(ids[i]) << endl;
        } else {
            cout << " FAILED" << endl;
            cout << "\tcount = " << hashtable.getCount() << endl;
            cout << "\tget data " << hashtable.getData(ids[i]) << endl;
        }
        
        cout << endl;
    }

    cout << endl;
    cout << "**********************" << endl;
    cout << "* Printing hashtable *" << endl;
    cout << "**********************" << endl;
    cout << endl;
    hashtable.printTable();

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    cout << endl;
    cout << "*******************************" << endl;
    cout << "* Starting randomized testing *" << endl;
    cout << "*******************************" << endl;
    cout << endl;

    for(int i = 0; i < 1000; i++){
        int method = rand() % 3 + 1;
        int rand_int = (rand() % 500) - 250;
        string test_string = "test string";

        if(method == 1){
            if(rand_int < 0 && rand_int > 75){
                test_string = "";
            }
            if(hashtable.insertEntry(rand_int, &test_string)){
                cout << "inserted "<< rand_int << ": " << hashtable.getData(rand_int);
            } else {
                cout << "failed to add " << rand_int << ": " << test_string;
            }
        }
        if(method == 2){
            cout << "get data for " << rand_int << ": " << hashtable.getData(rand_int);
        }

        if(method == 3){
            cout << "removing " << rand_int;
            if(hashtable.removeEntry(rand_int)){
                cout << ": SUCCESS";
            } else {
                cout << ": FAILED";
            }
        }
        cout << ":  count = " << hashtable.getCount() << endl;
    }

    cout << endl;
    cout << "**********************************" << endl;
    cout << "* Final randomized printed Table *" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    hashtable.printTable();
    
    return 0;
}
