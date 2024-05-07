#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "UserListNode.h"
using namespace std;

UserListNode::UserListNode() {
	PIN = NULL;
	username = "";
	next = nullptr;
	previous = nullptr;
	sizeOfList = 20;
	numOfElements = 0;
	listOfPasswords = new Password[sizeOfList];
}

UserListNode::UserListNode(int newPIN, string newUsername) {
	PIN = newPIN;
	username = newUsername;
	next = nullptr;
	previous = nullptr;
	sizeOfList = 20;
	numOfElements = 0;
	listOfPasswords = new Password[sizeOfList];
}

int UserListNode::getPIN() {
	return PIN;
}

void UserListNode::setPIN(int newVal) {
	PIN = newVal;
}

string UserListNode::getUsername() {
	return username;
}

void UserListNode::setUsername(string newUsername) {
	username = newUsername;
}


UserListNode* UserListNode::getNext() {
	return next;
}

void UserListNode::setNext(UserListNode* nextUser) {
	next = nextUser;
}

UserListNode* UserListNode::getPrevious() {
	return previous;
}

void UserListNode::setPrevious(UserListNode* prevUser) {
	previous = prevUser;
}

void UserListNode::displayAllIdentifiers() {
	for (int i = 0; i < sizeOfList; i++) {
		if ((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted") && (listOfPasswords[i].getPassword() != "")
			&& (listOfPasswords[i].getPassword() != "Deleted")) {
			cout << "Website: " << listOfPasswords[i].getIdentifier() << endl;
		}
	}
}

void UserListNode::displayPassword(string wantedIdentifier) {
	bool passwordFound = false;
	int index = hashFunction(wantedIdentifier, 0, sizeOfList);

	int counter = 0;
	cout << endl;
	if (numOfElements > 0) {
		while ((counter < sizeOfList) && (passwordFound == false) && (listOfPasswords[index].getIdentifier() != "") && (listOfPasswords[index].getPassword() != "")) {
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
	else {
		cout << "There is no password to find" << endl;
	}
}


string UserListNode::initializePasswordFile() {

	string entry_line;
	ifstream ifile;
	string passwordFileName;
	string key;
	cout << "Enter the file you want to initialize the list of passwords with: " << endl;
	cin >> passwordFileName;

	ifile.open(passwordFileName);
	if (ifile.fail()) {
		cout << "File opening failed" << endl;
		exit(1);
	}

	cout << "Enter key: ";
	cin >> key;

	while (getline(ifile, entry_line)) {
		string info_password, info_identifier;
		stringstream substr(entry_line);

		getline(substr, info_password, ',');
		getline(substr, info_identifier);
		string adjusted_identifier;
		int levelSpaceLoc = info_identifier.find(' ');
		adjusted_identifier = info_identifier.substr(levelSpaceLoc + 1);
		addPassword(info_password, adjusted_identifier);
		//addPassword(decrypt_Pass(info_password, key), decrypt_Web(info_identifier, key));
	}

	ifile.close();
	return passwordFileName;
}

int UserListNode::hashFunction(string identifier, int indexVal, int arraySize) {
	int sum = 0;
	for (char c : identifier) {
		sum += int(c);
	}

	int newIndex = ((sum + indexVal) % arraySize);
	return newIndex;
}

void UserListNode::addPassword(string password, string identifier) {
	int loadFactor = ((numOfElements / sizeOfList) * 100);
	if (loadFactor < 30) {
		bool open = false;
		int index = hashFunction(identifier, 0, sizeOfList);;
		for (int i = 0; i < sizeOfList; i++) {
			if ((listOfPasswords[index].getIdentifier() == "Deleted") || (listOfPasswords[index].getIdentifier() == "")) {
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
	else {
		int newListSize = 2 * sizeOfList;
		Password* newListOfPasswords = new Password[newListSize];
		for (int i = 0; i < sizeOfList; i++) {
			if ((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted")) {

				int index = hashFunction(listOfPasswords[i].getIdentifier(), 0, newListSize);

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

void UserListNode::deletePassword(string password, string identifier) {
	bool passwordFound = false;
	int index = hashFunction(identifier, 0, sizeOfList);
	int counter = 0;

	if (numOfElements > 0) {
		while ((counter < sizeOfList) && (passwordFound == false) && (listOfPasswords[index].getIdentifier() != "") && (listOfPasswords[index].getPassword() != "")) {
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
	else {
		cout << "There are no passwords to delete" << endl;
	}
}

void UserListNode::deletePassList() {
	delete[] listOfPasswords;
}

//Decryption
string UserListNode::decrypt_Pass(string input, string key) {
	string hexToPlain = "";
	int keyItr = 0;
	stringstream res;

	for (int i = 0; i < input.length() - 1; i += 2)
	{
		string output = input.substr(i, 2);
		int decimal = strtol(output.c_str(), NULL, 16);
		hexToPlain += (char)decimal;
	}
	string decryptedTemp = "";
	for (int i = 0; i < hexToPlain.length(); i++) {
		int temp = hexToPlain[i] ^ key[keyItr];
		decryptedTemp += char(temp);
		keyItr++;
		if (keyItr >= key.length()) {
			keyItr = 0;
		}
	}
	cout << "Pass Input: " << input << endl;
	cout << "Decrypted Pass Value: " << decryptedTemp << endl;
	return decryptedTemp;
}

string UserListNode::decrypt_Web(string web, string key) {
	string hexToPlain = "";
	int keyItr = 0;
	stringstream res;

	for (int i = 0; i < web.length() - 1; i += 2)
	{
		string output = web.substr(i, 2);
		int decimal = strtol(output.c_str(), NULL, 16);
		hexToPlain += (char)decimal;
	}
	string decryptedTemp = "";
	for (int i = 0; i < hexToPlain.length(); i++) {
		int temp = hexToPlain[i] ^ key[keyItr];
		decryptedTemp += char(temp);
		keyItr++;
		if (keyItr >= key.length()) {
			keyItr = 0;
		}
	}
	cout << "Website Input: " << web << endl;
	cout << "Decrypted Website Value: " << decryptedTemp << endl;
	return decryptedTemp;
}

//Encryption
string UserListNode::encrypt_Pass(string pass, string key) {
	string strTemp = "";
	int keyItr = 0;
	stringstream res;

	for (int i = 0; i < pass.length(); i++)
	{
		int temp = pass[i] ^ key[keyItr];

		res << hex << setfill('0') << std::setw(2) << (int)temp;
		keyItr++;
		if (keyItr >= key.length()) {
			keyItr = 0; //once all key's letters are used, repeat key
		}
	}
	res >> strTemp;
	return strTemp;
}

string UserListNode::encrypt_Web(string input, string key) {
	string strTemp = "";
	int keyItr = 0;
	stringstream res;

	for (int i = 0; i < input.length(); i++)
	{
		int temp = input[i] ^ key[keyItr];

		res << hex << setfill('0') << std::setw(2) << (int)temp;
		keyItr++;
		if (keyItr >= key.length()) {
			keyItr = 0; //once all key's letters are used, repeat key
		}
	}
	res >> strTemp;
	return strTemp;
}

void UserListNode::encrypt_Passfile(string passFileName) {

	string key;
	cin.ignore();
	cout << "Enter key for PassFile: ";
	getline(cin, key);

	fstream ifile;
	ifile.open(passFileName);
	if (ifile.fail()) {
		cout << "File opening failed" << endl;
		exit(1);
	}

	for (int i = 0; i < sizeOfList; i++) {
		if ((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted") && (listOfPasswords[i].getPassword() != "") && (listOfPasswords[i].getPassword() != "Deleted")) {
			ifile << encrypt_Web(listOfPasswords[i].getIdentifier(), key) << "," << encrypt_Pass(listOfPasswords[i].getPassword(), key) << endl;
		}
	}

	cout << "Success" << endl;
	ifile.close();
}
