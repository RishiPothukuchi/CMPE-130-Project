#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
//#include <cryptopp/sha.h>

#include "Encrypt.h"
#include "UserListNode.h"
using namespace std;

string encrypt_PIN(int input){
    //temp hasing funtion, simply return the function for final iteration
    string temp = "";
    string strPIN = to_string(input);
    for (int i = 0; i < strPIN.length(); i++)
    {   
        temp += char((int(strPIN[i]*130) % 94) + 33);
    }
    cout << "PIN Input: " << input << endl;
    cout << "Hashed PIN Value:" << temp << endl;
    return temp;
}

string encrypt_Pass(string pass, string hashed_PIN){
    int pass_val = 0;
    int count = 0;
    string temp = "";
    for (int i = 0; i < pass.length(); i++){
        pass_val = int(pass[i]);
        temp += char(((pass_val * int(hashed_PIN[count])) % 94) + 33);
        count++;
        count = count % hashed_PIN.length();
    }
    cout << "String value: " << pass << endl;
    cout << "Hashed password value: " << temp << endl;
    return temp;
}

string encrypt_Web(string web){
    string temp = "";
        for (int i = 0; i < web.length(); i++){
        temp += char((((int(web[i]) * 17 )) % 94) + 33);
    }
    cout << "String value: " << web << endl;
    cout << "Hashed website value: " << temp << endl;
    return temp;
}

/*
void encrypt_Userfile(UserListNode* userHead, ifstream file){
    //read linked list
    UserListNode* current = head;
    while(current->next != nullptr){

    }
}

void encrypt_Passfile(PassListNode* passHead, string passFileName){
    fstream ifile;
    string tempWeb = "";
    string hTempWeb = "";
    string tempPass = "";
    string hTempPass = "";

    ifile.open(passFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1); 
    }
    
    PassListNode* current = passHead 
    while (current->next != nullptr){
        tempWeb = current->getWeb();
        hash_Web(tempWeb); // Add hash website function
        
        tempPass = current->getPass();
        hash_Pass(tempPass);

        ifile << hTempWeb << "," << hTempPass << endl;
    }

    ifile.close();
}
*/

//temp test for writing to file
void encrypt_Passfile(string web, string pass, int PIN, string outputFile){ 
    ofstream file(outputFile);
    string hashed_pin = encrypt_PIN(PIN);
    string temp_web = "";
    string temp_pass = "";

    temp_web = encrypt_Web(web); // Add hash website function
    temp_pass = encrypt_Pass(pass, hashed_pin);

    file << temp_web << "," << temp_pass << endl;
    file.close();
}