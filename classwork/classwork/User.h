#pragma once
#include <iostream>
using namespace std;
class User{
private:
    int id;
    string username;
    string password;
    string role;
public:
	User();
	User(int id, string username, string password, string role);
    int getid();
    void setid(int id);
    string getusername();
    void setusername(string username);
    string getpassword();
    void setpassword(string password);
    string getrole();
    void setrole(string role);
    void CreateUser();
    void DisplayUser();
    int UserOption();
    void UserPage();
};

