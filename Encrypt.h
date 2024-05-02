#ifndef HASHPIN_H_
#define HASHPIN_H_
#include <iostream>
using namespace std;

string encrypt_PIN(int input);
string encrypt_Pass(string pass, string hashed_PIN);

void encrypt_Userfile(string file);
void encrypt_Passfile(string file);


#endif