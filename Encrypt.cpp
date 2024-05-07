#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "UserList.h"
using namespace std;

string UserList::encrypt_User(string input){
    string temp = "";
    for (int i = 0; i < input.length(); i++)
    {   
        temp += char((int(input[i] + 110) % 95) + 33); //
    }
    cout << "Username Input: " << input << endl;
    cout << "Hashed Username Value:" << temp << endl;
    return temp;
}

string encrypt_User_Key(string input){
    string temp = "";
    for (int i = 0; i < input.length(); i++)
    {   
        temp += (int(input[i]*1300) % 94) + 33;
    }
    return temp;
}

string encrypt_PIN(int input){
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

//Make a member of userlist.h so i can get head directly
void UserList::encrypt_Userfile(string fileName){

    fstream ifile;
    ifile.open(fileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1);
    }

    UserListNode* current = head;
    while(current != nullptr){
        ifile << encrypt_User(current->getUsername()) << "," << encrypt_PIN(current->getPIN()) << endl;
        current = current->getNext();
    }
}

void UserListNode::encrypt_Passfile(Password* passHead, string passFileName){
    
    fstream ifile;
    ifile.open(passFileName);
    if(ifile.fail()){
        cout << "File opening failed" << endl;
        exit(1); 
    }

    for(int i = 0; i < sizeOfList; i++){
        if((listOfPasswords[i].getIdentifier() != "") && (listOfPasswords[i].getIdentifier() != "Deleted") 
        && (listOfPasswords[i].getPassword() != "") && (listOfPasswords[i].getPassword() != "Deleted")){
        ifile << encrypt_Web(listOfPasswords[i].getIdentifier()) << "," << encrypt_Pass(listOfPasswords[i].getPassword(), encrypt_PIN(PIN)) << endl;
    }

    ifile.close();
}