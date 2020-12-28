#include "User.h"
#include <iostream>
#include <string>
#include "Program.h"

using namespace std;

User::User() {
    id = 0;
    username = "";
    password = "";
    role = "";
}
User::User(int id, string username, string password, string role) {
    this->id = id;
    this->username = username;
    this->password = password;
    this->role = role;
}
int User::getid() {
    return id;
}
void User::setid(int id) {
    this->id = id;
}
string User::getusername() {
    return username;
}
void User::setusername(string username) {
    this->username = username;
}
string User::getpassword() {
    return password;
}
void User::setpassword(string password) {
    this->password = password;
}
string User::getrole() {
    return role;
}
void User::setrole(string role) {
    this->role = role;
}

void User::CreateUser() {
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Username: ";
    cin.ignore();
    cin >> username;
    cout << "Enter password: ";
    cin.ignore();
    cin >> password;
    cout << "Enter role: ";
    cin.ignore();
    getline(cin, role);
}

void User::DisplayUser() {
    cout << "ID: " << id << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Role: " << role << endl;
}

int User::UserOption() {
    int option;
    cout << "Please place your order\n";
    cout << "1. Hat 10$\n";
    cout << "2. T-shirt 15$\n";
    cout << "3. Jean 20$\n";
    cout << "4. Check out\n";
    cout << "5. Log out\n";
    cout << "Please choose an item: ";
    cin >> option;
    return option;
    return 0;
}
void User::UserPage() {
    Program program;
    system("CLS");
    cout << "Welcome to ... shopping!\n";
    int option = 0;
    int total = 0;
    int hat = 0, shirt = 0, jean = 0;
    do {
        option = UserOption();
        switch (option) {
        case 1:
            total += 10;
            hat++;
            break;
        case 2:
            total += 15;
            shirt++;
            break;
        case 3:
            total += 20;
            jean++;
            break;
        case 4:
            cout << "Your total cost is: " << total << "$\n";
            cout << "Including:\n";
            cout << "Hat: " << hat << "x\n";
            cout << "T-shirt: " << shirt << "x\n";
            cout << "Jean: " << jean << "x\n";
            system("pause");
            //can add option for payment here
            break;
        case 5:
            program.Start();
            break;
        default:
            cout << "Wrong input\n";
        }
        system("CLS");
    } while (option != 5);
}