#ifndef HASHPIN_H_
#define HASHPIN_H_
#include <iostream>
using namespace std;

string hash_PIN(int input);
string hash_Pass(string pass, string hashed_PIN);

void hash_Userfile(string file);
void hash_Passfile(string file);


#endif