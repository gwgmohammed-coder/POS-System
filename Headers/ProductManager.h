#pragma once

#include "Product.h"
#include <string>
#include <vector>

class ProductManager
{
  private:
    std::vector<Product> products;

  public:
    Product searchInProducts(std::string nameOrID);
    void addProduct();
    void removeProduct();
    void updateProductInfo();
    void saveProducts();
    void loadProducts();
    void increaseStock();
    void decreaseStock();
    bool autoDecreaseQuntity(std::string nameOrID, int quntity);
    void autoIncreaseQuntity(std::string nameOrID, int quntity);
    void displayAllProducts();
};
