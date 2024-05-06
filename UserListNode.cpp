#include <iostream>
#include "UserListNode.h"
#include "Encrypt.h"
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

UserListNode* UserListNode::getNext(){
    return next;
}
UserListNode* UserListNode::getPrevious(){
    return previous;
}

void UserListNode::setPIN(int newPIN){
    this->PIN = newPIN;
}

void UserListNode::setUsername(string newUsername){
    this->username = newUsername;
}

void UserListNode::setNext(UserListNode* newNext){
    this->next = newNext;
}
void UserListNode::setPrevious(UserListNode* newPrevious){
    this->previous = newPrevious;
}