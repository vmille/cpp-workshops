//
// Created by mille on 28-Sep-22.
//

#include "AbstractItem.h"

#include <cmath>

namespace bookstore {
  int AbstractItem::NOT_READY_TO_DELIVER = -1;

  AbstractItem::AbstractItem(std::string const& _name) : name(_name), readyToDeliver(false), deliveryCost(0) {
  }

  std::string AbstractItem::getName() {
    return name;
  }

  void AbstractItem::prepareDeliveryIn(Cart& cart) {
    if (!cart.contains(name)) {
      throw std::runtime_error("Can only calculate delivery costs for items in cart");
    }

    int gramms = itemWeight();
    calculateDeliveryCost(cart, gramms);
    markReadyToDeliver();
  }

  void AbstractItem::calculateDeliveryCost(Cart& cart, int gramms) {
    if (gramms <= 500) {
      deliveryCost = 10;
    }
    else {
      deliveryCost = std::sqrt(gramms);
    }
  }

  void AbstractItem::markReadyToDeliver() {
    readyToDeliver = true;
  }

  int AbstractItem::getDeliveryCost() {
    if (readyToDeliver) {
      return deliveryCost;
    }
    return NOT_READY_TO_DELIVER;
  }

  std::string AbstractItem::toString() {
    return name + " (" + std::to_string(getDeliveryCost()) + "EUR)";
  }
} // bookstore