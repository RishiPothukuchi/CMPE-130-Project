#ifndef USERLIST_H_
#define USERLIST_H_

#include <iostream>
#include "UserListNode.h"
using namespace std;

class UserList{
private:
    UserListNode *head;
    UserListNode *tail;

public:
    UserList();
    void initializeWithFile();
    void login();
    void createNewUser();
    void loginExistingUser();
    void checkExistingNodes();

};

#endif