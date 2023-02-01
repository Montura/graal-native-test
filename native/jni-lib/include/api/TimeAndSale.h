#pragma once

#include <string>

struct TimeAndSale {
  std::string eventSymbol;
  int64_t eventTime;
  int64_t eventFlags;
  int64_t time;
  int64_t timeNanos;
  int32_t timeNanoPart;
  uint16_t exchangeCode;
  double price;
  int64_t size;
  double bidPrice;
  double askPrice;
  std::string exchangeSaleConditions;
  int32_t flags;
  std::string buyer;
  std::string seller;

  std::string toString() const {
    return std::string("TimeAndSale{") + eventSymbol +
           std::string(", eventTime=") + std::to_string(eventTime) +
           std::string(", eventFlags=") + std::to_string(eventFlags) +
           std::string(", time=") + std::to_string(time) +
           std::string(", timeNanos=") + std::to_string(timeNanos) +
           std::string(", timeNanoPart=") + std::to_string(timeNanoPart) +
           std::string(", exchangeCode=") + std::to_string(exchangeCode) +
           std::string(", price=") + std::to_string(price) +
           std::string(", size=") + std::to_string(size) +
           std::string(", bidPrice=") + std::to_string(bidPrice) +
           std::string(", askPrice=") + std::to_string(askPrice) +
           std::string(", exchangeSaleConditions=") + exchangeSaleConditions +
           std::string(", flags=") + std::to_string(flags) +
           std::string(", buyer=") + buyer +
           std::string(", seller=") + seller +
           "}";
  }
};