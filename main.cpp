#include <iostream>
#include <string>
#include "UserList.h"
#include "UserList.cpp"
#include "UserListNode.h"
#include "UserListNode.cpp"
using namespace std;

// void passwordMgr();

int main() {

	int login_select = 0;
	int pass_select = 1;
	string username = "";
	int PIN = 0;
	int hashedPIN = 0;
	bool valid = false;
	string pass_file;

	//READ INPUT FILE 

	//LOGIN/VERIFY
	cout << "Select an option: " << endl << "0 - Exit" << endl << "1 - Login" << endl << "2 - Create new user" << endl;
	cin >> login_select; // make catches

	cout << "Please enter your username" << endl;
	cin >> username; // make catches
	cout << "Please enter your PIN" << endl;
	cin >> PIN; // make catches

		// VERIFY
		// Hash the pin
		// Verify PIN

	//SELECTION
	if(valid == true){
		while(pass_select != 0){
			cout << "Please input the name of your 'Password' file: " << endl;
			cin >> pass_file; // make catches
			cout << "Please select an option" << endl << "0 - Exit" << endl << "1 - Add Password" << endl << "2 - View/Edit Password" << endl << "3 - Delete Password" << endl;
			cin >> pass_select; // make catches
			switch(pass_select){
				case 0: break;
				case 1: //addpassword
				case 2: // view/edit
				case 3: //delete
			}
		}
	}
	else{
		cout << "ERROR: Username or PIN is incorrect." << endl;
	}

	//ENCODING
		//Encode "User" File
		//Encode "Password" File
	// passwordMgr();
	UserList List1;
	List1.login();

	return 0;
}

