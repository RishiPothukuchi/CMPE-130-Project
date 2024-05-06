#ifndef USERLISTNODE_H_
#define USERLISTNODE_H_

#include <iostream>
#include <string>
using namespace std;

class UserListNode{
private:
    int PIN;
    string username;
    UserListNode *next;
    UserListNode *previous;

public:
    UserListNode(int newPIN, string newUsername);
    UserListNode();
    int getPIN();
    string getUsername();
    UserListNode* getNext();
    UserListNode* getPrevious();

    void setPIN(int PIN);
    void setUsername(string username);
    void setNext(UserListNode* newNext);
    void setPrevious(UserListNode* newPrev);

    friend void hash_Userfile(UserListNode* head, ifstream file);
};

#endif