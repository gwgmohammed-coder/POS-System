#include "../Headers/UserManager.h"
#include "../Headers/Helpers.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

void UserManager::addUser()
{
  std::cout<<"\t\t====YOU ARE ADDING A NEW USER====\n";
  std::string name, password;
  Role role;
  User newUser;
  std::cout <<"\nEnter the user's name: ";
  std::getline(std::cin, name);

  // User names are used for login, so duplicates should not be allowed.
  for(int i = 0; i < users.size(); i++)
  {
    if(users[i].getName() == name)
    {
      std::cout <<"\nThis user already exists.\n";
      return;
    }
  }

  if(name.empty())
  {
    std::cout <<"\nUser name cannot be empty.\n";
    return;
  }

  newUser.setName(name);

  std::cout <<"\nEnter the user's password: ";
  std::getline(std::cin, password);
  if(password.empty())
  {
    std::cout <<"\nPassword cannot be empty.\n";
    return;
  }
  newUser.setPassword(password);

  int userType;
  bool correctOp = false;
  while(!correctOp){
    userType = input("\nChoose '1' for Admin user\t '2' for Cashier: ");
    if(userType == 1)
    {
      role = Role::Admin;
      correctOp = true;
    }
    else if(userType == 2)
    {
      role = Role::Cashier;
      correctOp = true;
    }
    else{std::cout<<"\nIncorrect input. only choose '1' or '2'\n";}
  }
  newUser.setRole(role);
  users.push_back(newUser);
  system("cls");
  std::cout <<"\n\t\t\tUser Was Added Successfully!\n\n";
}

void UserManager::removeUser()
{
  std::string deleUser;
  std::cout<<"\t\t====YOU ARE REMOVING A USER====\n";
  std::cout<<"\nEnter the user's name: ";
  std::getline(std::cin, deleUser);
  bool isFound = false;
  for(int i = 0; i < users.size(); i++)
  {
    if(users[i].getName() == deleUser)
    {
      isFound = true;
      std::vector<User>::iterator it = users.begin() + i;
      system("cls");
      std::cout<<"\n\t\t\tUser: "<<users[i].getName() <<" was Deleted Successfully\n\n";
      users.erase(it);
      break;
    }
  }
  if(isFound == false)
  {
    system("cls");
    std::cout <<"\nUser Was Not Found!\n";
  }
}

Role UserManager::getRole()
{
  return rol;
}

bool UserManager::login()
{
  std::string name, pass;
  std::cout <<"\t\t====YOU ARE LOGGING IN====\n";
  std::cout <<"\nEnter the user's name: ";
  std::getline(std::cin, name);
  bool isFound = false;
  for(int i = 0; i < users.size(); i++)
  {
    if(users[i].getName() == name)
    {
      isFound = true;
      std::cout<<"\nEnter the password: ";
      std::getline(std::cin, pass);
      if(users[i].getPassword() == pass)
      {
        system("cls");
        std::cout<<"\n\t\t\tWelcome " << name <<" Enjoy Your Day!\n\n";
        rol = users[i].getRole();
        return true;
      }
      else{
        system("cls");
        std::cout<<"\nPassword is not correct!\n";
        return false;
      }
    }
  }
  if(isFound == false)
  {
    system("cls");
    std::cout<<"\nUser Was Not Found!\n";
    return false;
  }
  return false;
}

void UserManager::saveUsers()
{
  std::ofstream userFile("Data/users.txt");
  if(!userFile)
  {
    std::cout <<"\nUnable to save users.\n";
    return;
  }

  for(int i = 0; i < users.size(); i++)
  {
    userFile << users[i].getName() <<"|"<<users[i].getPassword()<<"|"<<roleToString(users[i].getRole()) <<"\n";
  }
  userFile.close();
}

void UserManager::loadUsers()
{
  std::ifstream userFile("Data/users.txt");
  if(!userFile)
  {
    std::cout <<"\nUnable to load users file.\n";
    return;
  }

  users.clear();
  std::string name, pass, role;
  while(std::getline(userFile, name, '|')){
    if(!std::getline(userFile, pass, '|')) break;
    if(!std::getline(userFile, role)) break;
    User previousUser;
    previousUser.setName(name);
    previousUser.setPassword(pass);
    previousUser.setRole(stringToRole(role));
    users.push_back(previousUser);
  }
}

void UserManager::updateInfo()
{
  std::string name, newName, newPass, newRole;
  std::cout<<"\t\t====YOU ARE UPDATING A USER'S INFO====\n";
  std::cout<<"\nEnter the user's name you want to update their information: ";
  std::getline(std::cin, name);
  system("cls");
  bool isFound = false;
  for(int i = 0; i < users.size(); i++)
  {
    if(users[i].getName() == name)
    {
      int operation;
      isFound = true;
      bool isEdited = false;
      while(!isEdited){
        operation = input("\nChoose '1' for Modifying the Name\n'2' for Modifying the Password\n'3' for Modifying the role\n'4' to Exit\n: ");
        system("cls");
        switch(operation)
        {
          case 1:
            std::cout<<"\nEnter the new user's name: ";
            std::getline(std::cin, newName);
            if(newName.empty())
            {
              std::cout <<"\nUser name cannot be empty.\n";
              break;
            }
            {
              bool duplicate = false;
              for(int j = 0; j < users.size(); j++)
              {
                if(j != i && users[j].getName() == newName)
                {
                  duplicate = true;
                  break;
                }
              }
              if(duplicate)
              {
                std::cout <<"\nThis user already exists.\n";
                break;
              }
            }
            users[i].setName(newName);
            break;

          case 2:
            std::cout<<"\nEnter the new user's password: ";
            std::getline(std::cin, newPass);
            if(newPass.empty())
            {
              std::cout <<"\nPassword cannot be empty.\n";
              break;
            }
            users[i].setPassword(newPass);
            break;

          case 3:
            std::cout<<"\nEnter the new user's role (Admin/Cashier): ";
            std::getline(std::cin, newRole);
            if(stringToRole(newRole) == Role::Unknown)
            {
              std::cout <<"\nInvalid role. Please enter Admin or Cashier.\n";
              break;
            }
            users[i].setRole(stringToRole(newRole));
            break;

          case 4:
            isEdited = true;
            break;
          default:
            system("cls");
            std::cout <<"\nWrong Choose! Try again.\n";
            break;
        }
      }
    }
  }
  if(isFound == false)
  {
    std::cout<<"\nUser Was Not Found!\n";
  }
}

void UserManager::displayAllUsers()
{
  for(int i = 0; i < users.size(); i++)
  {
    users[i].display();
  }
}
