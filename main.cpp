#include <iostream>
#include <string>
#include "encrypt.h"
#include "UserList.h"
using namespace std;

// void passwordMgr();

int main() {
		UserList listOfUsers;
		listOfUsers.initializeUserFile();
		bool loop = true;
		while(loop == true){
			int userOption;
			cout << "\nOptions:" << endl;
			cout << "1. Login" << endl;
			cout << "2. Exit Program" << endl;
			cout << "Select an option number: ";
			cin >> userOption;
			cout << endl;
			switch (userOption){
				case 1:{
					listOfUsers.login();
					break;
				}

				case 2:{
					loop = false;
				}
			}
		}
	}




//int login_select = 0;
//int pass_select = 1;
//string username = "";
//int PIN = 0;
//string hashed_PIN = "";
//bool valid = false;
//string pass_file;
//
////Testing values
//int temp_PIN = 1234;
//string temp_web = "google";
//READ INPUT FILE ReadFile.h
	//LOGIN/VERIFY Verify.h
	/*cout << "Select an option: " << endl << "0 - Exit" << endl << "1 - Login" << endl << "2 - Create new user" << endl;
	cin >> login_select; // make catches

	cout << "Please enter your username" << endl;
	cin >> username; // make catches
	cout << "Please enter your PIN" << endl;
	cin >> PIN; // make catches*/

	//SELECTION Selection.h
	/*
	if(valid == true){
		while(pass_select != 0){
			cout << "Please input the name of your 'Password' file: " << endl;
			cin >> pass_file; // make catches
			cout << "Please select an option" << endl << "0 - Exit" << endl << "1 - Add Password" << endl << "2 - View/Edit Password" << endl << "3 - Delete Password" << endl;
			cin >> pass_select; // make catches
			switch(pass_select){
				case 0: break;
				case 1: //addpassword
				case 2: //view/edit
				case 3: //delete
			}
		}
	}
	else{
		cout << "ERROR: Username or PIN is incorrect." << endl;
	}

	//ENCODING Encrypt.h
		//Encode "User" File
		encrypt_Userfile();
		//Encode "Password" File
		encrypt_Passfile();
	return 0;
	*/
