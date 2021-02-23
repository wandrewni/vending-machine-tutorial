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

  void getBeverage(std::string& _return, const BeverageType::type type) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, const BeverageType::type type) {
     // Your implementation goes here
     printf("getBeverage\n");
    // randomly select a weather
    if (type == BeverageType::type::HOT) {
        switch (rand()%3) {
            case 0:
                _return = "cappuccino";
                break;
            case 1:
                _return = "latte";
                break;
            case 2:
                _return = "espresso";
                break;
        }
    } else {
        switch (rand()%3) {
            case 0:
                _return = "lemonade";
                break;
            case 1:
                _return = "ice tea";
                break;
            case 2:
                _return = "soda";
                break;
        }
    }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

