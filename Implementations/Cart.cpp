#include "../Headers/Cart.h"
#include "../Headers/ProductManager.h"
#include "../Headers/Helpers.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

void Cart::addItemToCart()
{
  std::string nameID;
  ProductManager PM;
  while(true){
    int quantity;
    PM.displayAllProducts();
    std::cout<<"\nEnter the Item's ID or Name(or type (confirm) to make the sale, (cancel) to cancel the sale): ";
    std::getline(std::cin, nameID);
    if(nameID == "confirm")
    {
      system("cls");
      break;
    }

    if(nameID == "cancel")
    {
      system("cls");
      cancelSale(PM);
      std::cout<<"\nSale was Canceled Successfully.\n";
      break;
    }

    Product p = PM.searchInProducts(nameID);
    if(p.getProductName() != "")
    {
      quantity = input("\nEnter required quantity: ");
      if(PM.autoDecreaseQuntity(nameID, quantity))
      {
        CartItem newItem(p.getProductName(), p.getProductId(), p.getcategory(), p.getPrice());
        newItem.setRequiredQuantity(quantity);
        items.push_back(newItem);
        system("cls");
        std::cout<<"\nAdded to Cart successfully.\n";
        std::cout<<"\n\t\t\t\t\t\t\t\t======CURRENT CART======\n\n";
        for(int i = 0; i < items.size(); i++)
        {
          std::cout <<"\n\t\t\t\t\t\t\tName: "<< items[i].getProductName() <<"  Quantity: "<< items[i].getRequiredQuantity() <<"  Price Per each: " <<items[i].getProductPrice()<<"$\n";
          subtotal = calculateSubtotal();
        }
        std::cout<<"\n\t\t\tSubtotal: " << subtotal <<"$\n\n";
      }
    }
  }
  if(!items.empty() && nameID != "cancel"){
    std::cout<<"\nSale was made Successfully!\n";
    saveSale();
  }
}

double Cart::calculateSubtotal()
{
  subtotal = 0;
  for( int i = 0; i < items.size(); i++)
  {
    subtotal += items[i].getRequiredQuantity() * items[i].getProductPrice();
  }
  return subtotal;
}

void Cart::saveSale()
{
  std::ofstream saleFile("Data/Sales.txt", std::ios::app);
  if(!saleFile)
  {
    std::cout <<"\nUnable to save sale.\n";
    return;
  }

  saleFile <<"=========SALE=========|\n";
  for(int i = 0; i < items.size(); i++)
  {
    saleFile << items[i].getProductID() <<"|"<<items[i].getProductName()<<"|"<<items[i].getProductCategory()<<"|"<<std::to_string(items[i].getProductPrice())<<"|"<<std::to_string(items[i].getRequiredQuantity())<<"\n";
  }
  saleFile<<"SUBTOTAL|" <<std::to_string(subtotal)<<"\n";
  items.clear();
  subtotal = 0.0;
  saleFile.close();
}

void Cart::displaySales()
{
  std::string id, name, category, price, quantity, sub;
  std::ifstream saleFile("Data/Sales.txt");
  if(!saleFile)
  {
    std::cout <<"\nUnable to open sales file.\n";
    return;
  }

  while(std::getline(saleFile, id, '|')){
    if(id == "\n" || id == "\r" || id.empty()) break;
    if(id == "=========SALE=========")
    {
      std::string line;
      std::getline(saleFile, line);
      std::cout<<"\n\t\t\t=========SALE=========\n";
      continue;
    }
    if(id =="SUBTOTAL" )
    {
      std::getline(saleFile, sub);
      std::cout <<"Subtotal: " << sub<<"$\n";
      continue;
    }
    name = "";
    std::getline(saleFile, name, '|');
    std::getline(saleFile, category, '|');
    std::getline(saleFile, price, '|');
    std::getline(saleFile, quantity);
    if(name == "") break;

    std::cout <<"ID: "<< id <<"\tName: " << name <<"\tCategory: "<<category <<"\tPrice: " <<price <<"$\tQuantity: "<< quantity <<"\n";
  }
}

void Cart::cancelSale(ProductManager &pm)
{
  for(int i = 0; i < items.size(); i++)
  {
    pm.autoIncreaseQuntity(std::to_string(items[i].getProductID()), items[i].getRequiredQuantity());
  }
  items.clear();
  subtotal = 0.0;
}
