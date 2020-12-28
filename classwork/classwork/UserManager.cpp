#include "UserManager.h"
#include "Admin.h"
#include <iostream>
#include <fstream>
#include "User.h"
using namespace std;

void UserManager::SaveUser() {
    fstream fp;
    fp.open("user.txt", ios::out | ios::app);
    User* user = new User();
    user->CreateUser();
    fp.write((char*)user, sizeof(*user));
    fp.close();
    cout << "User saved" << endl;
}

void UserManager::DisplayAllUsers() {
    cout << "Display all users: " << endl;
    User* user = new User();
    fstream fp;
    fp.open("user.txt", ios::in);
    while (fp.read((char*)user, sizeof(User))) {
        user->DisplayUser();
        cout << "-------------------------------\n";
    }
    fp.close();
    cout << "All user displayed" << endl;
    cout << "-------------------------------\n";
}

void UserManager::DisplayAUser(int id) {
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("user.txt", ios::in);
    while (fp.read((char*)user, sizeof(User))) {
        if (user->getid() == id) {
            user->DisplayUser();
            found = true;
            break;
        }
    }
    fp.close();

    if (found == false)
        cout << "ID not found\n";
    else {
        cout << "ID found\n";
        cout << "-------------------------------\n";
    }
}

void UserManager::UpdateUser(int id) {
    fstream fp;
    User* user = new User();
    bool found = false;
    fp.open("user.txt", ios::in | ios::out);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getid() == id) {
            user->DisplayUser();
            cout << "Update user detail: \n";
            user->CreateUser();
            int pos = -1 * static_cast<int>(sizeof(*user));
            fp.seekp(pos, ios::cur);
            fp.write((char*)user, sizeof(*user));
            found = true;
            break;
        }
    }
    fp.close();
    if (found == false)
        cout << "ID not found\n";
    else {
        cout << "User have been update\n";
        cout << "-------------------------------\n";
    }
}

void UserManager::DeleteUser(int id) {
    fstream fp;
    User* user = new User();
    fp.open("user.txt", ios::in);
    fstream fp2;
    fp2.open("temp.txt", ios::out | ios::app);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)user, sizeof(*user))) {
        if (user->getid() != id) {
            fp2.write((char*)user, sizeof(*user));
            break;
        }
    }
    cout << "User has been deleted\n";
    cout << "-------------------------------\n";
    fp2.close();
    fp.close();
    remove("user.txt");
    rename("temp.txt", "user.txt");
}