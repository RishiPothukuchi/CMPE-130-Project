#include <iostream>
#include <string>
#include "Password.h"
using namespace std;


Password::Password(string newPassword, string newIdentifier){
	password = newPassword;
	identifier = newIdentifier;
}

Password::Password(){
	password = "";
	identifier = "";
}

string Password::getPassword(){
	return password;
}

string Password::getIdentifier(){
	return identifier;
}

void Password::setPassword(string passwordVal){
	password = passwordVal;

}

void Password::setIdentifier(string identifierVal){
	identifier = identifierVal;
}
