#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "UserList.h"
using namespace std;

UserList::UserList(){
    head = nullptr;
    tail = nullptr;
}

void UserList::initializeWithFile(){
    ifstream ifile;
    string userFileName;
    cout << "Enter the file you want to initialize the list of users with: ";
    cin >> userFileName;

    ifile.open(userFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1); 
    }

    ifile.close();
}

void UserList::createNewUser(string username, int PIN){
    UserListNode* newNode;
    newNode->setUsername(username);
    newNode->setPIN(PIN);

    newNode->setPrev(tail);
    tail->setNext(newNode);
    tail = newNode;
    delete tail;
}


void UserList::deleteUser(string username){
    UserListNode* current = head;

    while(current->getUsername() != username){
        current = current->getNext();
    }

    current->getPrev()->setNext(current->getNext());
    current->getNext()->setPrev(current->getPrev());

    delete current;
}