#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <fstream>
#include "UserList.h"
#include "UserListNode.h"
using namespace std;



void UserList::initializeUserFile(){
	string entry_line;
    ifstream ifile;
    string userFileName;
    cout << "Enter the file you want to initialize the list of users with: ";
    cin >> userFileName;

    ifile.open(userFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1);
    }

    while(getline(ifile, entry_line)){
    		string info_PIN, info_username;
    		stringstream substr(entry_line);

    		getline(substr, info_PIN, ',');
    		int converted_id = stoi(info_PIN);

    		getline(substr, info_username);


    		string adjusted_level;

    		int levelSpaceLoc = info_username.find(' ');
    		adjusted_level = info_username.substr(levelSpaceLoc + 1);
    		createNewUser(converted_id, adjusted_level);
    	}

    ifile.close();
}

void UserList::createNewUser(int PIN, string username){
	UserListNode *newUser;
	UserListNode *userPtr;

	newUser = new UserListNode(PIN, username);
	if(head == nullptr || PIN < head->getPIN()){
		newUser->setNext(head);
		if (head != nullptr) {
			head->setPrevious(newUser);
		}
		head = newUser;
	}
	else {
		userPtr = head;
		while (userPtr->getNext() != nullptr && userPtr->getNext()->getPIN() < PIN) {
			userPtr = userPtr->getNext();
		}

		newUser->setNext(userPtr->getNext());
		if (userPtr->getNext() != nullptr) {
			userPtr->getNext()->setPrevious(newUser);
		}
		userPtr->setNext(newUser);
		newUser->setPrevious(userPtr);
	}

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


void UserListNode::initializePasswordFile(){

	string entry_line;
    ifstream ifile;
    string passwordFileName;
    cout << "Enter the file you want to initialize the list of passwords with: ";
    cin >> passwordFileName;

    ifile.open(passwordFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1);
    }
	while(getline(ifile, entry_line)){
		string info_password, info_identifier;
		stringstream substr(entry_line);

		getline(substr, info_password, ',');

		getline(substr, info_identifier);


		string adjusted_identifier;

		int levelSpaceLoc = info_identifier.find(' ');
		adjusted_identifier = info_identifier.substr(levelSpaceLoc + 1);
		addPassword(info_password, adjusted_identifier);

	}
    ifile.close();
}


int UserListNode::hashFunction(string password, int loopIdx, int arraySize){
	int sum = 0;
	for (char c : password) {
		sum += int(c);
	}

	int passwordIndex = ((sum + loopIdx) % arraySize);
	return passwordIndex;
}


void UserListNode::addPassword(string password, string identifier){
    int loadFactor = ((numOfElements/sizeOfList) * 100);
    if(loadFactor < 30){
    	bool open = false;
		for(int i = 0; i < sizeOfList; i++){
			int index = hashFunction(password, i, sizeOfList);
			if((listOfPasswords[index].getIdentifier() == "Deleted")||(listOfPasswords[index].getIdentifier() == "")){
                listOfPasswords[index] = Password(password, identifier);
                numOfElements++;
                open = true;
                break;
			}
		}
		if (!open) {
			cout << "Error: Hash table is full but load factor is less than 30%." << endl;
			return;
		}
    }
    else{
    	int newListSize = 2 * sizeOfList;
    	Password* newListOfPasswords = new Password[newListSize];
    	for (int i = 0; i < sizeOfList; i++) {
    		int index = 0;
			if ((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted")){
				index = hashFunction(listOfPasswords[i].getPassword(), i, newListSize);
				while (newListOfPasswords[index].getIdentifier() != "") {
					index = (index + 1) % newListSize;
				}
				newListOfPasswords[index] = listOfPasswords[i];
			}
		}
    	delete[] listOfPasswords;
    	listOfPasswords = newListOfPasswords;
    	sizeOfList = newListSize;
    	addPassword(password, identifier);
    }
}

void UserListNode::deletePassword(string password, string identifier){
	bool passwordFound = false;
	int i = 0;
	int index = hashFunction(password, i, sizeOfList);
	int counter = 0;
	if(numOfElements > 0){
		while ((counter < sizeOfList) && (passwordFound == false) && (listOfPasswords[index].getIdentifier() != "") && (listOfPasswords[index].getPassword() != "")){
			if ((listOfPasswords[index].getPassword() == password) && (listOfPasswords[index].getIdentifier() == identifier)) {
				listOfPasswords[index].setIdentifier("Deleted");
				listOfPasswords[index].setPassword("Deleted");
				passwordFound = true;
			}
			else {
				index = ((index + 1) % sizeOfList);
				counter++;
			}
		}
		if (!passwordFound) {
			cout << "Website: " << identifier << "  =>  Password '" << password << "' not found." << endl;
		}
	}
	else{
		cout << "There are no passwords to delete" << endl;
	}
}
