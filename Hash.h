#ifndef HASHPIN_H_
#define HASHPIN_H_
#include <iostream>
using namespace std;

double hash_PIN(int input);
double hash_Pass(string pass, int hashed_PIN);

void hash_Userfile(string file);
void hash_Passfile(string file);


#endif