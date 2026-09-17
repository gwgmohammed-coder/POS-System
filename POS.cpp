#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Headers/Helpers.h"
#include "Headers/UserManager.h"
#include "Headers/ProductManager.h"
#include "Headers/Cart.h"

void displayScreens(const std::string& screenPath)
{
  std::string line;
  std::ifstream screenFile("Screens/" + screenPath); // Display the program's Screens.
  while(std::getline(screenFile, line)){
    std::cout << line <<"\n";
  }
}

int main()
{
  bool keepProgram = true, keepAdminMenu = true, keepUserScreen = true, keepProductScreen = true;
  bool keepInventoryScreen = true, keepCashierMenu = true;
  int mainOperation, userOperation, productOperation, inventoryOperation, casheirOperation;
  UserManager currentUser;
  ProductManager currentProduct;
  Cart currentCart;
  currentUser.loadUsers();
  currentProduct.loadProducts();
  while (keepProgram) { // To keep the program running untill the user chooses to close it.
    displayScreens("POS.txt");
    if(currentUser.login())
    {
      if(currentUser.getRole() == Role::Admin)
      {
        keepAdminMenu = true;
        while(keepAdminMenu){
          displayScreens("AdminMainScreen.txt");
          mainOperation = input("\nEnter Your Choise: ");
          system("cls");
          switch(mainOperation)
          {
            case 1:
              keepUserScreen = true;
              while(keepUserScreen){
                displayScreens("UserManagementScreen.txt");
                userOperation = input("\nEnter Your Choice: ");
                system("cls");
                switch(userOperation)
                {
                  case 1:
                    currentUser.addUser();
                    currentUser.saveUsers();
                    break;
                  case 2:
                    currentUser.removeUser();
                    currentUser.saveUsers();
                    break;
                  case 3:
                    currentUser.updateInfo();
                    currentUser.saveUsers();
                    break;
                  case 4:
                    currentUser.displayAllUsers();
                    break;
                  case 5:
                    keepUserScreen = false;
                    break;
                  default:
                    std::cout<<"\nWrong Operation. Try Again.\n";
                    break;
                }
              }
              break;

            case 2:
              keepProductScreen = true;
              while(keepProductScreen){
                displayScreens("ProductMangementScreen.txt");
                productOperation = input("\nEnter Your Choice: ");
                system("cls");
                switch(productOperation)
                {
                  case 1:
                    currentProduct.addProduct();
                    currentProduct.saveProducts();
                    break;
                  case 2:
                    currentProduct.removeProduct();
                    currentProduct.saveProducts();
                    break;
                  case 3:
                    currentProduct.updateProductInfo();
                    currentProduct.saveProducts();
                    break;
                  case 4:
                    currentProduct.displayAllProducts();
                    break;
                  case 5:
                    keepProductScreen = false;
                    break;
                  default:
                    std::cout<<"\nWrong Operation. Try Again.\n";
                    break;
                }
              }
              break;

            case 3:
              keepInventoryScreen = true;
              while(keepInventoryScreen){
                displayScreens("InventoryScreen.txt");
                inventoryOperation = input("\nEnter Your Choice: ");
                system("cls");
                switch(inventoryOperation)
                {
                  case 1:
                    currentProduct.increaseStock();
                    currentProduct.saveProducts();
                    break;
                  case 2:
                    currentProduct.decreaseStock();
                    currentProduct.saveProducts();
                    break;
                  case 3:
                    keepInventoryScreen = false;
                    break;
                  default:
                    std::cout<<"\nWrong Operation. Try Again.\n";
                    break;
                }
              }
              break;

            case 4:
              system("cls");
              currentCart.displaySales();
              break;
            case 5:
              keepAdminMenu = false;
              break;
            case 6:
              keepAdminMenu = false;
              keepProgram = false;
              break;
            default:
              std::cout<<"\nWrong Operation. Try Again.\n";
              break;
          }
        }
      }
      else if(currentUser.getRole() == Role::Cashier)
      {
        keepCashierMenu = true;
        while(keepCashierMenu){
          displayScreens("CashierMainScreen.txt");
          casheirOperation = input("\nEnter Your Choise: ");
          system("cls");
          switch(casheirOperation)
          {
            case 1:
              currentCart.addItemToCart();
              break;
            case 2:
              currentCart.displaySales();
              break;
            case 3:
              keepCashierMenu = false;
              break;
            case 4:
              keepCashierMenu = false;
              keepProgram = false;
              break;
            default:
              std::cout<<"\nWrong Operation. Try Again.\n";
              break;
          }
        }
      }
      else {
        std::cout<<"\nError!\n";
      }
    }
  }

  return 0;
}
