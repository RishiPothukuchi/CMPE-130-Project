#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "UserList.h"
using namespace std;

UserList::UserList(){
    head = nullptr;
    tail = nullptr;
}

void UserList::initializeWithFile(){
    ifstream ifile;
    string userFileName;
    cout << "Enter the file you want to initialize the list of users with: ";
    cin >> userFileName;

    ifile.open(userFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1); 
    }

    // Code to read and store each row in file 
    // as a new UserListNode written here

    ifile.close();
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
            createNewUser();
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

void UserList::createNewUser(){

}

void UserList::loginExistingUser(){

}

void UserList::checkExistingNodes(){

}