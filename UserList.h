#ifndef USERLIST_H_
#define USERLIST_H_

#include <iostream>
#include "UserListNode.h"
using namespace std;

class UserList{
private:
    UserListNode *head;
    UserListNode *tail;
    int *PassArray; // for password dynamic array


public:
    UserList();
    void initializeWithFile();
    void createNewUser(string username, int PIN);
    void deleteUser(string username);
    //void loginExistingUser(string username, int PIN);
    //void checkExistingNodes(string username, int PIN);

};

#endif