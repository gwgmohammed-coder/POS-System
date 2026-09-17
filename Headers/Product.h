#pragma once

#include <string>

class Product
{
  private:
    int productId;
    std::string productName;
    std::string category;
    double price;
    int stockQuantity;

  public:
    void setProductId(int ID);
    int getProductId() const;
    void setProductName(const std::string& name);
    std::string getProductName() const;
    void setcategory(const std::string& cata);
    std::string getcategory() const;
    void setPrice(double pric);
    double getPrice() const;
    void setStockQuantity(int quantity);
    int getstockQuantity() const;
    void display() const;
};
