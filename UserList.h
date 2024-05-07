#ifndef USERLIST_H_
#define USERLIST_H_

#include <iostream>
#include "UserListNode.h"
using namespace std;

class UserList {
private:
    UserListNode* head;
    UserListNode* tail;
    int* PassArray;

public:
    UserList();
    void initializeUserFile();
    void login();
    void deleteUser(string username);
    void loginExistingUser();
    void createNewUser(int PIN, string username);

    bool checkUser(string username, int pin);
    void selectUser(string username, int pin);

    //Decryption
    string decrypt_User(string input, string key);
    string decrypt_PIN(string input);

    //Encryption
    string encrypt_User(string input, string key);
    string encrypt_PIN(int input);
    void encrypt_Userfile(string fileName);

    void displayUsers();

    void deleteUserList();
};

#endif
#pragma once
