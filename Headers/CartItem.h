#pragma once

#include <string>

class CartItem
{
  private:
    std::string productName;
    int productID;
    std::string category;
    double productPrice;
    int requiredQuantity;

  public:
    CartItem(std::string name, int id, std::string cate, double price);
    void setRequiredQuantity(int quantity);
    int getRequiredQuantity() const;
    std::string getProductName() const;
    int getProductID() const;
    std::string getProductCategory() const;
    double getProductPrice() const;
    void displayItem();
};
