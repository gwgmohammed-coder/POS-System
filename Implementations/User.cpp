#include "../Headers/User.h"
#include <iostream>

std::string roleToString(Role role)
{
  switch(role)
  {
    case Role::Admin:
      return "Admin";
    case Role::Cashier:
      return "Cashier";
    case Role::Unknown:
      break;
  }
  return "Unknown";
}

Role stringToRole(std::string role)
{
  // Windows text files can leave a carriage return at the end of the role.
  if(!role.empty() && role.back() == '\r') role.pop_back();

  if(role == "Admin")
  {
    return Role::Admin;
  }
  else if(role == "Cashier")
  {
    return Role::Cashier;
  }
  return Role::Unknown;
}

void User::setName(const std::string& name)
{
  userName = name;
}

void User::setPassword(const std::string& pass)
{
  password = pass;
}

void User::setRole(const Role& rol)
{
  role = rol;
}

std::string User::getName() const
{
  return userName;
}

std::string User::getPassword() const
{
  return password;
}

Role User::getRole() const
{
  return role;
}

void User::display() const
{
  std::cout<<"Name: " << userName << "\tPassword: " << password <<"\tRole: " << roleToString(role) <<"\n";
}
