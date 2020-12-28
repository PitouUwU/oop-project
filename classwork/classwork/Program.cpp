#include "Program.h"
#include <istream>
#include <fstream>
#include "User.h"
#include "Admin.h"
#include "UserManager.h"
using namespace std;

void Program::Start() {
    UserManager usermanager;
    int option = 0;
    do {
        option = Option();
        switch (option) {
        case 1:
            usermanager.SaveUser();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong input\n";
        }
    } while (option != 3);
}
int Program::Option() {
    system("CLS");
    int option;
    cout << "Welcome to ...\n";
    cout << "1. Sign up\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Please choose an option: ";
    cin >> option;
    return option;
}

void Program::login() {
    fstream fp;
    User* user = new User();
    string name, pass;
    cout << "Enter your username: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> pass;
    if (name == "admin" && pass == "admin") {
        Admin admin;
        admin.adminpage();
    }
    bool found = false;
    fp.open("user.txt", ios::in);
    while (fp.read((char*)user, sizeof(User))) {

        if (user->getusername() == name && user->getpassword() == pass) {
            user->UserPage();
            break;
        }
    }
    cout << "Incorrect username or password\n";
    system("pause");
    fp.close();

}