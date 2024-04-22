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
    int getPIN();
    string getUsername();
};

#endif