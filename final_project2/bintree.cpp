/*****************************************
 * Name: Hector Solis
 * Coding 07
 * Purpose: Create a Binary Search Tree object
 * that will work with a struct Data and a 
 * struct Node
 *****************************************/

#include "bintree.h"


BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){
    return !root;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* temp){
    root? temp->id = root->data.id: temp->id = -1;
    root? temp->information = root->data.information: temp->information = "";

    return temp->id != -1;
}

void BinTree::displayTree(){
    cout << "DISPLAY TREE\n";
    cout << "==============================================\n";
    
    cout << "Tree is "; 
    isEmpty()? cout << "EMPTY\n": cout << "NOT empty\n";
    
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << count << endl;
    cout << "\n\n";

    cout << "Pre-Order Traversa\n";
    displayPreOrder();
    cout << endl;

    cout << "In-Order Traversal\n";
    displayInOrder();
    cout << endl;

    cout << "Post-Order Traversal\n";
    displayPostOrder();
    cout << "==============================================\n\n";
}

void BinTree::clear(){
    clear(root);
    root = NULL;
}

bool BinTree::addNode(int id, const string* info){
    bool success = false;
    
    if(id > -1 && *info != ""){
        Vertex *newvertex = new Vertex;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
        success = addNode(newNode, &root);
    }
    
    return success;
}

bool BinTree::removeNode(int id){
    int tempCount = count;
    root = removeNode(id, root);
    return tempCount > count;
}

bool BinTree::getNode(Data* temp, int id){
    return getNode(temp, id, root);
}

bool BinTree::contains(int id){
    return (id > -1)? contains(id, root): false;
}

int BinTree::getHeight(){
    return getHeight(root);
}

void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}

/*****************
 * Private Methods
 * **************/
void BinTree::clear(DataNode* currentRoot){
    if(currentRoot){
        clear(currentRoot->left);
        clear(currentRoot->right);
        currentRoot->left = NULL;
        currentRoot->right = NULL;
        delete currentRoot;
    }
    count = 0;
}

bool BinTree::addNode(DataNode* newNode, DataNode** currentRoot){
    bool added = false;

    if(!(*currentRoot)){
        *currentRoot = newNode;
        added = true;
        count++;
    } else {
        if((*currentRoot)->data.id > newNode->data.id){
            added = addNode(newNode, &(*currentRoot)->left);
        }
        if((*currentRoot)->data.id < newNode->data.id) {
            added = addNode(newNode, &(*currentRoot)->right);
        }
    }

    return added;
}

DataNode* BinTree::removeNode(int id, DataNode* currentRoot){

    if(currentRoot){
        if(id < currentRoot->data.id){
                currentRoot->left = removeNode(id, currentRoot->left);
        } else if (id > currentRoot->data.id){
                currentRoot->right = removeNode(id, currentRoot->right);
        } else if (id == currentRoot->data.id) {
            DataNode *temp = NULL;

            if(!currentRoot->left){
                temp = currentRoot->right;
                delete currentRoot;
                currentRoot = temp;
                count--;
            } else if (!currentRoot->right){
                temp = currentRoot->left;
                delete currentRoot;
                currentRoot = temp;
                count--;
            } else {
                temp = minValueNode(currentRoot->right);
                currentRoot->data.id = temp->data.id;
                currentRoot->data.information = temp->data.information;
                currentRoot->right = removeNode(temp->data.id, currentRoot->right);
                count--;
            }
        }
    }

    return currentRoot;
}

bool BinTree::getNode(Data* data, int id, DataNode* currentNode){
    bool success = false;

    if(currentNode){
        if(currentNode->data.id == id){
            data->id = currentNode->data.id;
            data->information = currentNode->data.information;
            success = true;
        } else {
            if(id < currentNode->data.id){
                success = contains(id, currentNode->left);
            } else {
                success = contains(id, currentNode->right);
            }
        }
    }

    return success;
}

bool BinTree::contains(int id, DataNode* currentRoot){
    bool success = false;

    if(currentRoot){
        if(currentRoot->data.id == id){
            success = true;
        } else {
            if(id < currentRoot->data.id){
                success = contains(id, currentRoot->left);
            } else {
                success = contains(id, currentRoot->right);
            }
        }
    }

    return success;
}

int BinTree::getHeight(DataNode* currentRoot){
    int left_height = 0;
    int right_height = 0;
    int value = 0;

    if(currentRoot){
        left_height = getHeight(currentRoot->left);
        right_height = getHeight(currentRoot->right);
        value = left_height >= right_height? left_height + 1: right_height + 1;
    }

    return value;
}

void BinTree::displayPreOrder(DataNode* currentRoot){
    if(currentRoot){
        cout << currentRoot->data.id << " " << currentRoot->data.information << endl;
        if(currentRoot->left){
            displayPreOrder(currentRoot->left);
        }
        if(currentRoot->right){
            displayPreOrder(currentRoot->right);
        }
    }

}

void BinTree::displayPostOrder(DataNode* currentRoot){
    if(currentRoot){
        if(currentRoot->left){
            displayPostOrder(currentRoot->left);
        }
        if(currentRoot->right){
            displayPostOrder(currentRoot->right);
        }
        cout << currentRoot->data.id << " " << currentRoot->data.information << endl;
    }
}

void BinTree::displayInOrder(DataNode* currentRoot){
    if(currentRoot){
        if(currentRoot->left){
            displayInOrder(currentRoot->left);
        }
        cout << currentRoot->data.id << " " << currentRoot->data.information << endl;
        if(currentRoot->right){
            displayInOrder(currentRoot->right);
        }
    }
}

DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}