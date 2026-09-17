#pragma once

#include "CartItem.h"
#include <vector>

class ProductManager;

class Cart
{
  private:
    std::vector<CartItem> items;
    double subtotal = 0.0;

  public:
    void addItemToCart();
    double calculateSubtotal();
    void saveSale();
    void displaySales();
    void cancelSale(ProductManager &pm);
};
