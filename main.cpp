#include <iostream>
#include <string>
#include "UserList.h"
using namespace std;

int main() {
	string temp = "testing123";
	string temp2 = encrypt_User(temp);
	cout << temp2 << endl;
	/*UserList listOfUsers;
	listOfUsers.initializeUserFile();
	bool loop = true;
	bool validLogin = false;
	while(loop == true){
		int userOption;
		cout << "\nOptions:" << endl;
		cout << "1. Login/Create Account" << endl;
		cout << "2. Exit Program" << endl;
		cout << "Select an option number: ";
		cin >> userOption;
		cout << endl;
		switch (userOption){
			case 1:{
				listOfUsers.login(); //make where sucessful login turns validLogin true
				if(validLogin == true){
				int userOption2 = 1;
					while(userOption2 != 0){
						string passFile;
						cout << "Please input the name of your 'Password' file: " << endl;
						cin >> passFile; // make catches
						cout << "Options: " << endl << "0 - Exit" << endl << "1 - Add Password" << endl << "2 - View/Edit Password" << endl << "3 - Delete Password" << endl;
						cin >> userOption2; // make catches
						switch(userOption2){
							case 0: break;
							case 1: //add password
							case 2: //view/edit
							case 3: //delete
						}
					}
				}
				else{
					cout << "Login Error: Please Try Again." << endl;
				}
				break;
			}
			case 2:{
				cout << "Exiting Application." << endl;
				loop = false;
			}
		}
	}

	//ENCODING Encrypt.h
	//Encode "User" File
	//encrypt_Userfile();
	//Encode "Password" File
	//encrypt_Passfile();*/
	return 0;
}
