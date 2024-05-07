#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <fstream>
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

void UserListNode::displayAllIdentifiers(){
	for(int i = 0; i < sizeOfList; i++){
		if((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted") && (listOfPasswords[i].getPassword() != "")
				&& (listOfPasswords[i].getPassword() != "Deleted")){
			cout << "Website: " << listOfPasswords[i].getIdentifier() << endl;
		}
	}
}

void UserListNode::displayPassword(string wantedIdentifier){
	bool passwordFound = false;
		int index = hashFunction(wantedIdentifier, 0, sizeOfList);

		int counter = 0;
		cout << endl;
		if(numOfElements > 0){
			while ((counter < sizeOfList) && (passwordFound == false) && (listOfPasswords[index].getIdentifier() != "") && (listOfPasswords[index].getPassword() != "")){
				if ((listOfPasswords[index].getIdentifier() == wantedIdentifier)) {
					cout << "Website: " << listOfPasswords[index].getIdentifier() << "  =>   Password: " << listOfPasswords[index].getPassword() << endl;
					passwordFound = true;
					return;
				}
				else {
					index = ((index + 1) % sizeOfList);
					counter++;
				}
			}
			if (!passwordFound) {
				cout << "Password for Website: " << wantedIdentifier << " Cannot be found." << endl;
			}
		}
		else{
			cout << "There is no password to find" << endl;
		}
}


void UserListNode::initializePasswordFile(){

	string entry_line;
    ifstream ifile;
    string passwordFileName;
	cout << endl;
    cout << "Enter the file you want to initialize the list of passwords with: " << endl;
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


int UserListNode::hashFunction(string identifier, int indexVal, int arraySize){
	int sum = 0;
	for (char c : identifier) {
		sum += int(c);
	}

	int newIndex = ((sum + indexVal) % arraySize);
	return newIndex;
}


void UserListNode::addPassword(string password, string identifier){
    int loadFactor = ((numOfElements/sizeOfList) * 100);
    if(loadFactor < 30){
    	bool open = false;
    	int index = hashFunction(identifier, 0, sizeOfList);;
		for(int i = 0; i < sizeOfList; i++){
			if((listOfPasswords[index].getIdentifier() == "Deleted")||(listOfPasswords[index].getIdentifier() == "")){
                listOfPasswords[index] = Password(password, identifier);
                numOfElements++;
                open = true;
                break;
			}
			index = ((index + 1) % sizeOfList);

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
			if ((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted")){

				int index = hashFunction(listOfPasswords[i].getIdentifier(), i, newListSize);

				while (newListOfPasswords[index].getIdentifier() != "") {
					index = ((index + 1) % newListSize);
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
//	int i = 0;

	int index = hashFunction(identifier, 0, sizeOfList);

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



//Encryption
string UserListNode::encrypt_Pass(string pass){
    int pass_val = 0;
    string temp = "";
    for (int i = 0; i < pass.length(); i++){
        pass_val = int(pass[i]);
        temp += char((int(pass[i] + 110) % 95) + 33);
    }
    cout << "String value: " << pass << endl;
    cout << "Hashed password value: " << temp << endl;
    return temp;
}

string UserListNode::encrypt_Web(string web){
    string temp = "";
    for (int i = 0; i < web.length(); i++){
        temp += char((int(web[i] + 110) % 95) + 33);
    }
    cout << "String value: " << web << endl;
    cout << "Hashed website value: " << temp << endl;
    return temp;
}


void UserListNode::encrypt_Passfile(Password* passHead, string passFileName){

    fstream ifile;
    ifile.open(passFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1);
    }

    for(int i = 0; i < sizeOfList; i++){
        if((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted")
        && (listOfPasswords[i].getPassword() != "") && (listOfPasswords[i].getPassword() != "Deleted")){
        ifile << encrypt_Web(listOfPasswords[i].getIdentifier()) << "," << encrypt_Pass(listOfPasswords[i].getPassword()) << endl;
    }

    ifile.close();
}
