//
// Created by mille on 28-Sep-22.
//

#ifndef CPP_WORKSHOPS_CART_H
#define CPP_WORKSHOPS_CART_H

#include <vector>
#include <string>
#include <iostream>

namespace bookstore {
  class Cart {
    std::vector<std::string> items;

  public:
    void add(std::string const& item);

    bool contains(std::string const& item);

    bool containsTwiceOrMore(std::string item);

    std::string toString();
  };
}

#endif //CPP_WORKSHOPS_CART_H
