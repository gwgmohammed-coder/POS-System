#include "../Headers/CartItem.h"
#include <iostream>

CartItem::CartItem(std::string name, int id, std::string cate, double price)
{
  productName = name;
  productID = id;
  category = cate;
  productPrice = price;
  requiredQuantity = 0;
}

void CartItem::setRequiredQuantity(int quantity)
{
  requiredQuantity = quantity;
}

int CartItem::getRequiredQuantity() const
{
  return requiredQuantity;
}

std::string CartItem::getProductName() const
{
  return productName;
}

int CartItem::getProductID() const
{
  return productID;
}

std::string CartItem::getProductCategory() const
{
  return category;
}

double CartItem::getProductPrice() const
{
  return productPrice;
}

void CartItem::displayItem()
{
  std::cout<<"\nID: " << getProductID() <<"\tName: "<< getProductName() <<"\tCategory: " << getProductCategory() <<"\tPrice Per Item: "<< getProductPrice() <<"\tQuantity: " << getRequiredQuantity()<<"\n";
}
