#include <iostream>
#include "UserListNode.h"
using namespace std;

UserListNode::UserListNode(){
    PIN = NULL;
    username = "";
    next = nullptr;
    previous = nullptr;
    sizeOfList = 20;
    numOfElements = 0;
    listOfPasswords = new Password[sizeOfList];
}

UserListNode::UserListNode(int newPIN, string newUsername){
    PIN = newPIN;
    username = newUsername;
    next = nullptr;
    previous = nullptr;
    sizeOfList = 20;
    numOfElements = 0;
    listOfPasswords = new Password[sizeOfList];
}

int UserListNode::getPIN(){
    return PIN;
}

void UserListNode::setPIN(int newVal){
	PIN = newVal;
}

string UserListNode::getUsername(){
    return username;
}

void UserListNode::setUsername(string newUsername){
	username = newUsername;
}


UserListNode* UserListNode::getNext(){
	return next;
}

void UserListNode::setNext(UserListNode* nextUser){
	next = nextUser;
}

UserListNode* UserListNode::getPrevious(){
	return previous;
}

void UserListNode::setPrevious(UserListNode* prevUser){
	previous = prevUser;
}


void UserListNode::displayPasswords(){
	for(int i = 0; i < sizeOfList; i++){
		if((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted") && (listOfPasswords[i].getPassword() != "")
				&& (listOfPasswords[i].getPassword() != "Deleted")){
			cout << "Website: " << listOfPasswords[i].getIdentifier() << "  =>   Password: " << listOfPasswords[i].getPassword() << endl;
		}
	}
}
