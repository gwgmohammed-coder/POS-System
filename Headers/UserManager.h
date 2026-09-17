#pragma once

#include "User.h"
#include <vector>

class UserManager
{
  private:
    std::vector<User> users;
    Role rol = Role::Unknown;

  public:
    void addUser();
    void removeUser();
    Role getRole();
    bool login();
    void saveUsers();
    void loadUsers();
    void updateInfo();
    void displayAllUsers();
};
