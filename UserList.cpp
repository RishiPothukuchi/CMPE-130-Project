#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "UserList.h"
using namespace std;

UserList::UserList(){
    head = nullptr;
    tail = nullptr;
    PassArray = nullptr;
}

void UserList::createNewUser(string username, int PIN) {
    UserListNode* newNode = new UserListNode();

    newNode->setUsername(username);
    newNode->setPIN(PIN);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->setPrevious(tail);
        tail->setNext(newNode);
        tail = newNode;
    }

    cout << "Success" << endl;
}

void UserList::deleteUser(string username){
    UserListNode* current = head;

    while(current->getUsername() != username){
        current = current->getNext();
    }

    current->getPrevious()->setNext(current->getNext());
    current->getNext()->setPrevious(current->getPrevious());

    delete current;
}