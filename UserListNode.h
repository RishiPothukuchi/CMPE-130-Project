#ifndef USERLISTNODE_H_
#define USERLISTNODE_H_

#include <iostream>
#include <string>
#include "Password.h"
using namespace std;

class UserListNode{
private:
    int PIN;
    string username;
    UserListNode *next;
    UserListNode *previous;
    Password *listOfPasswords;
    int sizeOfList;
    int numOfElements;

public:
    UserListNode(int newPIN, string newUsername);
    UserListNode();

    int hashFunction(string password, int loopIdx, int arraySize);

    void initializePasswordFile();

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

    //friend void hash_Userfile(UserListNode* head, ifstream file);
    //Pass Encryption
    string encrypt_Web(string website);
    string encrypt_Pass(string pass, string hashed_PIN);
    void encrypt_Passfile(Password* passHead, string passFileName);


	void displayPasswords();

};

#endif
