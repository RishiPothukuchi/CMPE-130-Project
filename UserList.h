#ifndef USERLIST_H_
#define USERLIST_H_

#include <iostream>
#include "UserListNode.h"
using namespace std;

class UserList{
private:
    UserListNode *head;
    UserListNode *tail;
    int *PassArray;

public:
    UserList();
    void initializeUserFile();
    void login();
    void deleteUser(string username);
    void loginExistingUser();
    void checkExistingNodes();
    void createNewUser(int PIN, string username);
    bool checkUser(string username, int pin);
    void selectUser();


    void displayUsers();
};

#endif
