#pragma once
class UserManager {
public:
    void SaveUser();
    void DisplayAllUsers();
    void DisplayAUser(int id);
    void UpdateUser(int id);
    void DeleteUser(int id);
};

