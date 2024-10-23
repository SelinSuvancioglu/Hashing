// Selin Suvancioglu 20190205026
#include <iostream>
#include <string>
#include "md5.h"
#include <fstream>
using namespace std;
 
using std::cout; using std::endl;
 

void ReadDatabase(),TakeInputs(),LoginControl(string p),SignUp(),Menu();
string Database, code, ControledUsername, ControledPassword, TheHash;
string username, password;
int theValue;

int main(int argc, char *argv[])
{
    //SignUp();
    //TakeInputs();
    Menu();
}

 void ReadDatabase() {
  
  ifstream Database("database.txt"); // Database is assigned database.txt
  while (Database >> ControledUsername >> ControledPassword) { // ControledUsername = the username in database, ControledPassword = hash of the password in database, 
    // read line by line because of while
    // firstly read database file. Secondly read usernames in database and finally read their hash codes in database
    if (username == ControledUsername){ // Compare the entered value with the value in the database
        TheHash = ControledPassword; // TheHash is holding the hash code of the password of the account we want to enter
    }
  }
}

void TakeInputs(){

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    LoginControl(password);
}
void SignUp(){
    ofstream Database;
    Database.open("database.txt", std::ofstream::app);
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    Database << username << " " << md5(password)<<endl;
    Database.close();
}
void LoginControl(string p){
    ReadDatabase();
    if (md5(p) == TheHash){ // control to is hash of entered password equal to hash of password of account
        cout << "Login successful" << endl;
    }
    else{
        cout << "wrong password or username\n";
    }
    cout << md5(p) << endl;
}
void Menu(){
    cout << "1-Sign up"<<endl;
    cout << "2-Login"<<endl;
    cout << "3-Quit"<<endl;
    cin >> theValue;
    switch (theValue) {
     case 1:
        SignUp();
        Menu();
        break;
     case 2:
        TakeInputs();
        Menu();
        break;
     case 3:
        exit(0);
     default:
        cout << "Program give a error";
        exit(0);
  }
}
