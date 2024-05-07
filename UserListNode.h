#ifndef USERLISTNODE_H_
#define USERLISTNODE_H_

#include <iostream>
#include <string>
#include "Password.h"
using namespace std;

class UserListNode {
private:
    int PIN;
    string username;
    UserListNode* next;
    UserListNode* previous;
    Password* listOfPasswords;
    int sizeOfList;
    int numOfElements;

public:
    UserListNode(int newPIN, string newUsername);
    UserListNode();

    int hashFunction(string identifier, int arraySize);

    string initializePasswordFile();

    void addPassword(string password, string identifier);
    void deletePassword(string password, string identifier);

    int getPIN();
    void setPIN(int newVal);

    string getUsername();
    void setUsername(string newUsername);

    UserListNode* getNext();
    void setNext(UserListNode* nextUser);

    UserListNode* getPrevious();
    void setPrevious(UserListNode* prevUser);

    //Decryption
    string decrypt_Pass(string pass, string key);
    string decrypt_Web(string web, string key);

    //Encryption
    string encrypt_Pass(string pass, string key);
    string encrypt_Web(string web, string key);
    void encrypt_Passfile(string passFileName);


    void displayAllIdentifiers();
    void displayPassword(string wantedIdentifier);

    void deletePassList();

};

#endif
