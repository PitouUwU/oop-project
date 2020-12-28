#include "Admin.h"
#include "UserManager.h"
#include "Program.h"
#include <iostream>
using namespace std;


void Admin::adminpage() {
    system("CLS");
    UserManager usermanager;
    Program program;
    int option = 0;
    do {
        option = adminoption();
        switch (option) {
        case 1:
            usermanager.DisplayAllUsers();
            adminpage();
            break;
        case 2:
            usermanager.DisplayAllUsers();
            int update;
            cout << "Enter use id that you want to update:";
            cin >> update;
            usermanager.UpdateUser(update);
            adminpage();
            break;
        case 3:
            usermanager.DisplayAllUsers();
            int del;
            cout << "Enter use id that you want to delete:";
            cin >> del;
            usermanager.DeleteUser(del);
            adminpage();
            break;
        case 4:
            program.Start();
        default:
            cout << "Wrong input\n";
        }
    } while (option != 4);

}

int Admin::adminoption() {
    int option;
    cout << "Welcome dumb admin!\n";
    cout << "1. Display all user\n";
    cout << "2. Update user\n";
    cout << "3. Delete user\n";
    cout << "4. Logout\n";
    cout << "Please choose an option: ";
    cin >> option;
    return option;

    return 0;
}
