#include <iostream>
#include "UserListNode.h"
using namespace std;


UserListNode::UserListNode(int newPIN, string newUsername){
    PIN = newPIN;
    username = newUsername;
    next = nullptr;
    previous = nullptr;
}

int UserListNode::getPIN(){
    return PIN;
}

string UserListNode::getUsername(){
    return username;
}