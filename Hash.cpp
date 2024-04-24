#include <iostream>
#include <fstream>
#include <math.h>
#include "Hash.h"
using namespace std;

double hash_PIN(int input){
    //temp hasing funtion
    double temp = log(13017 * sqrt((4 * input))) + sin(input * 10); // Take out after
    cout << "PIN Input: " << input << endl;
    cout << "Hashed PIN Value:" << temp << endl;
    return temp;
}
double hash_Pass(string pass, int hashed_PIN);

void hash_Userfile(string file);
void hash_Passfile(string file);