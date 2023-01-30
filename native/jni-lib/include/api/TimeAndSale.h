#pragma once

#include <string>

struct TimeAndSale {
  std::string eventSymbol;
  int64_t eventTime;
  int64_t flags;
  int64_t time;
  int64_t timeNanos;
  int32_t timeNanoPart;
//  char exchangeCode;
//  double price;
//  double size;
//  double bidPrice;
//  double askPrice;
//  const char* exchangeSaleConditions;
//  int32_t eventFlags;
//  const char* buyer;
//  const char* seller;

  std::string toString() const {
    return std::string("TimeAndSale{") + eventSymbol +
           std::string(", eventTime=") + std::to_string(eventTime) +
           std::string(", flags=") + std::to_string(flags) +
           std::string(", time=") + std::to_string(time) +
           std::string(", timeNanos=") + std::to_string(timeNanos) +
           std::string(", timeNanoPart=") + std::to_string(timeNanoPart) +
//                      std::string(", bidTime=") + std::to_string(bidTime) +
//                      std::string(", bidExchange=") + bidExchangeCode +
           //           std::string(", bidPrice=") + std::to_string(bidPrice) +
           //           std::string(", bidSize=") + std::to_string(bidSize) +
           //           std::string(", askTime=") + std::to_string(askTime) +
           //           std::string(", askExchange=") + askExchangeCode +
           //           std::string(", askPrice=") + std::to_string(askPrice) +
           //           std::string(", askSize=") + std::to_string(askSize) +
           "}";
  }
};