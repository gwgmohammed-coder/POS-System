#include "../Headers/Product.h"
#include <iostream>

void Product::setProductId(int ID)
{
  productId = ID;
}

int Product::getProductId() const
{
  return productId;
}

void Product::setProductName(const std::string& name)
{
  productName = name;
}

std::string Product::getProductName() const
{
  return productName;
}

void Product::setcategory(const std::string& cata)
{
  category = cata;
}

std::string Product::getcategory() const
{
  return category;
}

void Product::setPrice(double pric)
{
  price = pric;
}

double Product::getPrice() const
{
  return price;
}

void Product::setStockQuantity(int quantity)
{
  stockQuantity = quantity;
}

int Product::getstockQuantity() const
{
  return stockQuantity;
}

void Product::display() const
{
  std::cout<<"The Product's ID: " << productId <<"\tName: " << productName <<"\tCategory: " << category <<"\n";
  std::cout<<"The Product's Price: " <<price <<"\tStock Quantity: " << stockQuantity <<"\n";
}
