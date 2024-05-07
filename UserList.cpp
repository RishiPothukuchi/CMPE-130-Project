#include <iostream>
//#include <algorithm>
#include <sstream>
#include <cctype>
#include <fstream>
#include "UserList.h"
using namespace std;

UserList::UserList(){
    head = nullptr;
    tail = nullptr;
    PassArray = nullptr;
}


void UserList::login(){
	initializeUserFile();
    bool validChoice = false;
    while (validChoice == false){
        string userStringChoice;
    	cout << endl;
        cout << "Are you a new or already existing user: " << endl;
        cout << "- New" << endl;
        cout << "- Existing" << endl;
        cout << "Choice: ";
        cin >> userStringChoice;

        if(userStringChoice == "New"){
            validChoice = false;
            while(validChoice == false){
            	cout << endl;
				int newPIN;
				string newUsername;
				cout << "Please Provide a PIN: ";
				cin >> newPIN;
				cout << "Please Provide a Username: ";
				cin >> newUsername;
				if(checkUser(newUsername, newPIN) == false){
					createNewUser(newPIN, newUsername);
					validChoice = true;
				}
				else{
					cout << endl;
					cout << "This Username or Password Already Exists, Please Try Another One." << endl;
				}
            }

        }
        else if(userStringChoice == "Existing"){
            validChoice = true;            
            loginExistingUser();
        }
        else{
            cout << "Invalid Response, Please Try Again" << endl;
        }
    }
}


void UserList::selectUser(string username, int pin){
	UserListNode *current = head;
	while((current->getUsername() != username) && (current->getPIN() != pin)){
		current = current->getNext();
	}

	current->initializePasswordFile();
	bool done = true;
	while(done == true){
	int userChoice;
	cout << endl;
	cout << "1. Add password: " << endl;
	cout << "2. Delete password: " << endl;
	cout << "3. View All Websites That You Have Passwords For: " << endl;
	cout << "4. View Specific Password: " << endl;
	cout << "5. Log Out: " << endl;
	cout << "Pick an option: ";
	cin >> userChoice;
	cout << endl;

		switch(userChoice){
			case 1:{
				string userAddWebsite, userAddPassword;
				cout << "Enter the name of the website and the password." << endl;
				cout << "Website Name: ";
				cin >> userAddWebsite;
				cout << endl;
				cout << "Password: ";
				cin >> userAddPassword;

				current->addPassword(userAddPassword, userAddWebsite);
				break;
			}
			case 2:{
					string userDeleteWebsite, userDeletePassword;
					cout << "Enter the name of the website and the password." << endl;
					cout << "Website Name: ";
					cin >> userDeleteWebsite;
					cout << endl;
					cout << "Password: ";
					cin >> userDeletePassword;

					current->deletePassword(userDeletePassword, userDeleteWebsite);
					break;
					}
			case 3:{
					current->displayAllIdentifiers();
					break;
				}
			case 4:{
					string userDisplayWebsite;
					cout << "Enter the name of the website you want to see the password of." << endl;
					cout << "Website Name: ";
					cin >> userDisplayWebsite;

					current->displayPassword(userDisplayWebsite);
					break;
			}
			case 5:{
					done = false;
					break;
			}
		}
	}
}


void UserList::loginExistingUser(){
    string username;
    int pin;
	cout << endl;
    cout << "Enter your username: ";
    cin >> username;
	cout << endl;
    cout << "Enter your PIN: ";
    cin >> pin;
	cout << endl;
    if(checkUser(username, pin)){
        cout << "Login successful!" << endl;
        selectUser(username, pin);
    } else {
        cout << "Invalid username or PIN." << endl;
        loginExistingUser();
    }
}

bool UserList::checkUser(string username, int pin){
    UserListNode *current = head;
    while(current != nullptr){
        if(current->getUsername() == username && current->getPIN() == pin){
            return true;
        }
        current = current->getNext();
    }
    return false;
}



void UserList::initializeUserFile(){
	string entry_line;
    ifstream ifile;
    string userFileName;
    cout << "Enter the file you want to initialize the list of users with: " << endl;
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


void UserList::displayUsers(){
    UserListNode *current;
    	current = head;
    	while(current != nullptr){
    		cout << "Username: " << current->getUsername() << "    PIN: " << current->getPIN() << endl;
    		current = current->getNext();
    	}
    }


//Encryption
string UserList::encrypt_User(string input){
    string temp = "";
    for (int i = 0; i < input.length(); i++)
    {
        temp += char((int(input[i] + 110) % 95) + 33); //
    }
    cout << "Username Input: " << input << endl;
    cout << "Hashed Username Value:" << temp << endl;
    return temp;
}

string UserList::encrypt_PIN(int input){
    string temp = "";
    string strPIN = to_string(input);
    for (int i = 0; i < strPIN.length(); i++)
    {
        temp += char((int(strPIN[i] + 110) % 95) + 33);
    }
    cout << "PIN Input: " << input << endl;
    cout << "Hashed PIN Value:" << temp << endl;
    return temp;
}

void UserList::encrypt_Userfile(string fileName){

    fstream ifile;
    ifile.open(fileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1);
    }

    UserListNode* current = head;
    while(current != nullptr){
        ifile << encrypt_User(current->getUsername()) << "," << encrypt_PIN(current->getPIN()) << endl;
        current = current->getNext();
    }
}
