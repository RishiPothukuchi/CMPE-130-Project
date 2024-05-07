#ifndef PASSWORD_H_
#define PASSWORD_H_


#include <iostream>
#include <string>
using namespace std;


class Password {
private:
	string password;
	string identifier;

public:
	Password(string newPassword, string newIdentifier);
	Password();
	string getPassword();
	string getIdentifier();

	void setPassword(string passwordVal);
	void setIdentifier(string identifierVal);
};




#endif /* PASSWORD_H_ */
