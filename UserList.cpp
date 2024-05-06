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




void UserList::loginExistingUser(){

}

void UserList::checkExistingNodes(){

}
