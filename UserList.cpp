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


void UserList::login(){
    bool validChoice = false;
    while (validChoice == false){
        string userStringChoice;
        cout << "Are you a new or already existing user: " << endl;
        cout << "- New" << endl;
        cout << "- Existing" << endl;
        cout << "Choice: ";
        cin >> userStringChoice;

        transform(userStringChoice.begin(), userStringChoice.end(), userStringChoice.begin(), [](unsigned char c){ return std::tolower(c); });
        userStringChoice[0] = toupper(userStringChoice[0]); 

        if(userStringChoice == "New"){
            validChoice = true;
            int newPIN;
            string newUsername;
            cout << "Please Provide a PIN:";
            cin >> newPIN;
            cout << "Please Provide a Username:";
            cin >> newUsername;
            createNewUser(newPIN, newUsername);
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


void UserList::selectUser(){
	UserListNode *current;
	current = head;

	current = current->getNext();
	current = current->getNext();
	cout << "Username: " << current->getUsername() << "    PIN: " << current->getPIN() << endl;
	current->initializePasswordFile();
	bool done = true;
	while(done == true){
	int userChoice;
	cout << "Pick an option." << endl;
	cout << "1. Add password." << endl;
	cout << "2. Delete password." << endl;
	cout << "3. View All Passwords." << endl;
	cout << "4. View Specific Password." << endl;
	cin >> userChoice;

		switch(userChoice){
			case 1:{
				string userAddWebsite, userAddPassword;
				cout << "Enter the name of the website and the password." << endl;
				cout << "Website Name:" << endl;
				cin >> userAddWebsite;
				cout << "Password:" << endl;
				cin >> userAddPassword;

				current->addPassword(userAddPassword, userAddWebsite);
				break;
			}
			case 2:{
				string userDeleteWebsite, userDeletePassword;
				cout << "Enter the name of the website and the password." << endl;
				cout << "Website Name:" << endl;
				cin >> userDeleteWebsite;
				cout << "Password:" << endl;
				cin >> userDeletePassword;



				current->deletePassword(userDeletePassword, userDeleteWebsite);
				break;
					}
			case 3:{
				current->displayAllPasswords();
				break;
				}
			case 4:{
				string userDisplayWebsite;
				cout << "Enter the name of the website you want to see the password of" << endl;
				cout << "Website Name:" << endl;
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
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your PIN: ";
    cin >> pin;
    if(checkUser(username, pin)){
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or PIN." << endl;
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


void UserList::checkExistingNodes(){

}
