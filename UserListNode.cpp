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

void UserListNode::displayAllPasswords(){
	for(int i = 0; i < sizeOfList; i++){
		if((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted") && (listOfPasswords[i].getPassword() != "")
				&& (listOfPasswords[i].getPassword() != "Deleted")){
			cout << "Website: " << listOfPasswords[i].getIdentifier() << "  =>   Password: " << listOfPasswords[i].getPassword() << endl;
		}
	}
}

void UserListNode::displayPassword(string wantedIdentifier){
	bool passwordFound = false;
//		int i = 0;
		int index = hashFunction(wantedIdentifier, 0, sizeOfList);

		int counter = 0;
		if(numOfElements > 0){
			while ((counter < sizeOfList) && (passwordFound == false) && (listOfPasswords[index].getIdentifier() != "") && (listOfPasswords[index].getPassword() != "")){
				if ((listOfPasswords[index].getIdentifier() == wantedIdentifier)) {
					cout << "Website: " << listOfPasswords[index].getIdentifier() << "  =>   Password: " << listOfPasswords[index].getPassword() << endl;;
					passwordFound = true;
					return;
				}
				else {
					index = ((index + 1) % sizeOfList);
					counter++;
				}
			}
			if (!passwordFound) {
				cout << " Password for Website: " << wantedIdentifier << " Cannot be found." << endl;
			}
		}
		else{
			cout << "There is no password to find" << endl;
		}
}
