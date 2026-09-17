#include "../Headers/ProductManager.h"
#include "../Headers/Helpers.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

Product ProductManager::searchInProducts(std::string nameOrID)
{
  for(int i = 0; i < products.size(); i++)
  {
    if(nameOrID == products[i].getProductName() || nameOrID == std::to_string(products[i].getProductId()))
    {
      return products[i];
    }
  }
  system("cls");
  std::cout<<"\nProduct was not found!\n";
  Product emptyProduct;
  emptyProduct.setProductName("");
  return emptyProduct;
}

void ProductManager::addProduct()
{
  Product newProduct;
  int id, quantity;
  std::string name1, category;
  double price;

  std::cout<<"\n\t\t====YOU ARE ADDING A NEW PRODUCT====\n";
  id = input("\nEnter the product's ID: ");
  if(id <= 0)
  {
    std::cout <<"\nProduct ID must be greater than 0.\n";
    return;
  }

  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getProductId() == id)
    {
      std::cout <<"\nThis product ID already exists.\n";
      return;
    }
  }

  newProduct.setProductId(id);

  std::cout<<"\nEnter the product's name: ";
  std::getline(std::cin, name1);
  if(name1.empty())
  {
    std::cout <<"\nProduct name cannot be empty.\n";
    return;
  }
  newProduct.setProductName(name1);

  std::cout<<"\nEnter the product's category: ";
  std::getline(std::cin, category);
  if(category.empty())
  {
    std::cout <<"\nProduct category cannot be empty.\n";
    return;
  }
  newProduct.setcategory(category);

  price = input("\nEnter the product's price: ");
  if(price < 0)
  {
    std::cout <<"\nProduct price cannot be negative.\n";
    return;
  }
  newProduct.setPrice(price);

  quantity = input("\nEnter the product's stock quantity: ");
  if(quantity < 0)
  {
    std::cout <<"\nStock quantity cannot be negative.\n";
    return;
  }
  newProduct.setStockQuantity(quantity);

  products.push_back(newProduct);
  system("cls");
  std::cout<<"\n\t\t\tProduct was Add Successfully\n\n";
}

void ProductManager::removeProduct()
{
  std::string nameID;
  std::cout <<"\n\t\t====YOU ARE REMOVING A PRODUCT====\n";
  std::cout <<"\nEnter the product name or ID: ";
  std::getline(std::cin, nameID);
  bool isFound = false;
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getProductName() == nameID || std::to_string(products[i].getProductId()) == nameID)
    {
      isFound = true;
      std::vector<Product>::iterator it = products.begin() + i;
      products.erase(it);
      system("cls");
      std::cout <<"\nDeletion was successful...\n";
      break;
    }
  }
  if(isFound == false)
  {
    system("cls");
    std::cout <<"\nProduct was not found.\n";
  }
}

void ProductManager::updateProductInfo()
{
  std::string nameID, newName, newCategory;
  int newID, choice, newStockQ;
  double newPrice;
  std::cout <<"\n\t\t====YOU ARE UPDATING A PRODUCT'S INFORMATION====\n";
  std::cout <<"\nEnter the product name or ID: ";
  std::getline(std::cin, nameID);
  bool isFound = false;
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getProductName() == nameID || std::to_string(products[i].getProductId()) == nameID)
    {
      isFound = true;
      bool keepEditing = true;
      while(keepEditing){
        choice = input("\nChoose '1' for Modefying the ID\n'2' for Modefying the Name\n'3' for modefying the Category\n'4' for Modefying the Price\n'5' for Modefying the Stock Quantity\n'6' to Exit\n: ");
        system("cls");
        switch(choice)
        {
          case 1:
            newID = input("\nEnter the New ID: ");
            if(newID <= 0)
            {
              std::cout <<"\nProduct ID must be greater than 0.\n";
              break;
            }
            {
              bool duplicate = false;
              for(int j = 0; j < products.size(); j++)
              {
                if(j != i && products[j].getProductId() == newID)
                {
                  duplicate = true;
                  break;
                }
              }
              if(duplicate)
              {
                std::cout <<"\nThis product ID already exists.\n";
                break;
              }
            }
            products[i].setProductId(newID);
            std::cout <<"\nID was changed successfully.\n";
            break;

          case 2:
            std::cout <<"\nEnter the New Name: ";
            std::getline(std::cin, newName);
            if(newName.empty())
            {
              std::cout <<"\nProduct name cannot be empty.\n";
              break;
            }
            products[i].setProductName(newName);
            std::cout <<"\nName was changed successfully.\n";
            break;

          case 3:
            std::cout <<"\nEnter the New Cagegory: ";
            std::getline(std::cin, newCategory);
            if(newCategory.empty())
            {
              std::cout <<"\nProduct category cannot be empty.\n";
              break;
            }
            products[i].setcategory(newCategory);
            std::cout <<"\nCategory was changed successfully.\n";
            break;

          case 4:
            newPrice = input("\nEnter the New Price: ");
            if(newPrice < 0)
            {
              std::cout <<"\nProduct price cannot be negative.\n";
              break;
            }
            products[i].setPrice(newPrice);
            std::cout <<"\nPrice was changed successfully\n";
            break;

          case 5:
            newStockQ = input("\nEnter the New Stock Quantity: ");
            if(newStockQ < 0)
            {
              std::cout <<"\nStock quantity cannot be negative.\n";
              break;
            }
            products[i].setStockQuantity(newStockQ);
            std::cout <<"\nStock Quantity was changed successfully.\n";
            break;

          case 6:
            keepEditing = false;
            break;

          default:
            system("cls");
            std::cout <<"\nInvalid Operation. Please Choose a Number from the List.\n";
            break;
        }
      }
      break;
    }
  }
  if(isFound == false)
  {
    std::cout <<"\nProduct was not found.\n";
  }
}

void ProductManager::saveProducts()
{
  std::ofstream productFile("Data/Products.txt");
  if(!productFile)
  {
    std::cout <<"\nUnable to save products.\n";
    return;
  }

  for(int i = 0; i < products.size(); i++)
  {
    productFile << products[i].getProductId() <<"|" << products[i].getProductName() <<"|"<<products[i].getcategory()<<"|"<<products[i].getPrice()<<"|"<<products[i].getstockQuantity()<<"\n";
  }
  productFile.close();
}

void ProductManager::loadProducts()
{
  std::ifstream productFile("Data/Products.txt");
  if(!productFile)
  {
    std::cout <<"\nUnable to load products file.\n";
    return;
  }

  products.clear();
  std::string name, category, ID, stockQ, price;
  while(std::getline(productFile, ID, '|')){
    std::getline(productFile, name, '|');
    std::getline(productFile, category, '|');
    std::getline(productFile, price , '|');
    std::getline(productFile, stockQ);
    Product previousProduct;
    previousProduct.setProductId(std::stoi(ID));
    previousProduct.setProductName(name);
    previousProduct.setcategory(category);
    previousProduct.setPrice(std::stod(price));
    previousProduct.setStockQuantity(std::stoi(stockQ));
    products.push_back(previousProduct);
  }
}

void ProductManager::increaseStock()
{
  int quantity;
  int newStock;
  std::string nameID;
  std::cout <<"\n===YOU ARE INCREASING THE STOCK===\n";
  std::cout <<"\nEnter the product's name or ID: ";
  std::getline(std::cin, nameID);
  bool isFound = false;
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getProductName() == nameID || std::to_string(products[i].getProductId()) == nameID)
    {
      isFound = true;
      quantity = input("\nHow many items of " + products[i].getProductName() + " do you want to increase?\n: ");
      system("cls");
      if(quantity <= 0)
      {
        std::cout <<"\nQuantity must be greater than 0.\n";
        break;
      }
      newStock = products[i].getstockQuantity() + quantity;
      products[i].setStockQuantity(newStock);
      std::cout <<"\n" << quantity <<"Item of " << products[i].getProductName() <<"was Added Successfully!\n";
      break;
    }
  }
  if(isFound == false)
  {
    system("cls");
    std::cout <<"\nProduct was not Found.\n";
  }
}

void ProductManager::decreaseStock()
{
  int quantity;
  int newStock;
  std::string nameID;
  std::cout <<"\n===YOU ARE DECREASING THE STOCK===\n";
  std::cout <<"\nEnter the product's name or ID: ";
  std::getline(std::cin, nameID);
  bool isFound = false;
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getProductName() == nameID || std::to_string(products[i].getProductId()) == nameID)
    {
      isFound = true;
      while(true){
        quantity = input("\nHow many items of " + products[i].getProductName() + " do you want to decrease?\n: ");
        system("cls");
        if(quantity > 0 && products[i].getstockQuantity() >= quantity)
        {
          newStock = products[i].getstockQuantity() - quantity;
          products[i].setStockQuantity(newStock);
          std::cout <<"\n" << quantity <<"Item of " << products[i].getProductName() <<"was decreased Successfully!\n";
          break;
        }
        else{std::cout<<"\nQuantity entered is not correct or more the the current stock! Try again.\n";}
      }
      break;
    }
  }
  if(isFound == false)
  {
    system("cls");
    std::cout <<"\nProduct was not Found.\n";
  }
}

bool ProductManager::autoDecreaseQuntity(std::string nameOrID, int quntity)
{
  int newQuantity;
  bool isFound = false;
  for(int i = 0 ; i < products.size(); i++)
  {
    if(nameOrID == products[i].getProductName() || std::to_string(products[i].getProductId())== nameOrID)
    {
      isFound = true;
      if(quntity > 0 && products[i].getstockQuantity() >= quntity)
      {
        newQuantity = products[i].getstockQuantity() - quntity;
        products[i].setStockQuantity(newQuantity);
        saveProducts();
        return true;
      }
      else {
        system("cls");
        std::cout<<"\nQuantity is insuficient.\n";
      }
    }
  }
  if(isFound == false) {
    system("cls");
    std::cout<<"\nProduct was not found!\n";
  }
  return false;
}

void ProductManager::autoIncreaseQuntity(std::string nameOrID, int quntity)
{
  int newQuantity;
  if(quntity <= 0)
  {
    return;
  }
  for(int i = 0 ; i < products.size(); i++)
  {
    if(nameOrID == products[i].getProductName() || nameOrID == std::to_string(products[i].getProductId()))
    {
      newQuantity = products[i].getstockQuantity() + quntity;
      products[i].setStockQuantity(newQuantity);
      saveProducts();
      return;
    }
  }
}

void ProductManager::displayAllProducts()
{
  loadProducts();
  std::cout <<"\n\t\t\t======FRUITS======\n";
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getcategory() == "Fruits")
    {
      products[i].display();
      std::cout<<std::endl;
    }
  }

  std::cout <<"\n\t\t\t======VEGETABLES======\n";
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getcategory() == "Vegetables")
    {
      products[i].display();
      std::cout<<std::endl;
    }
  }

  std::cout <<"\n\t\t\t======GROCERY======\n";
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getcategory() == "Grocery")
    {
      products[i].display();
      std::cout<<std::endl;
    }
  }

  std::cout <<"\n\t\t\t======OTHERS======\n";
  for(int i = 0; i < products.size(); i++)
  {
    if(products[i].getcategory() != "Fruits" && products[i].getcategory() != "Vegetables" && products[i].getcategory() != "Grocery")
    {
      products[i].display();
      std::cout<<std::endl;
    }
  }
}
