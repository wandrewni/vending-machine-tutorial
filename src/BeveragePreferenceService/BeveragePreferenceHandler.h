#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  string getBeverage(const BeverageType type) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

string BeveragePreferenceServiceHandler::getBeverage(const BeverageType type) {
     // Your implementation goes here
     printf("getBeverage\n");
    // randomly select a weather
    if (type == BeverageType::type::HOT) {
        switch (rand()%3) {
            case 0:
                return "cappuccino";
            case 1:
                return "latte";
            case 2:
                return "espresso";
        }
    } else {
        switch (rand()%3) {
            case 0:
                return "lemonade";
            case 1:
                return "ice tea";
            case 2:
                return "soda";
        }
    }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

