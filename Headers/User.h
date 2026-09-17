#pragma once

#include <string>

enum class Role
{
  Admin,
  Cashier,
  Unknown
};

std::string roleToString(Role role);
Role stringToRole(std::string role);

class User
{
  private:
    std::string userName;
    std::string password;
    Role role;

  public:
    void setName(const std::string& name);
    void setPassword(const std::string& pass);
    void setRole(const Role& rol);
    std::string getName() const;
    std::string getPassword() const;
    Role getRole() const;
    void display() const;
};
