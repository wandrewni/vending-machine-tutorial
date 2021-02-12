#ifndef VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/OrderBeverageService.h"
#include "../../gen-cpp/WeatherService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"

namespace vending_machine{

class OrderBeverageServiceHandler : virtual public OrderBeverageServiceIf {
 public:
  OrderBeverageServiceHandler(
		  ClientPool<ThriftClient<WeatherServiceClient>>*) ;
  ~OrderBeverageServiceHandler() override=default;

  BeverageType::type PlaceOrder(const location& l);
 private:
  ClientPool<ThriftClient<WeatherServiceClient>> *_weather_client_pool;
};

// Constructor
OrderBeverageServiceHandler::OrderBeverageServiceHandler(
		ClientPool<ThriftClient<WeatherServiceClient>> *weather_client_pool) {

     // Storing the clientpool
     _weather_client_pool = weather_client_pool;
}

// Remote Procedure "PlaceOrder"

BeverageType::type OrderBeverageServiceHandler::PlaceOrder(const location& l) {
     // Your implementation goes here
     printf("PlaceOrder\n");

    // 1. get the weather service client pool
    auto weather_client_wrapper = _weather_client_pool->Pop();
    if (!weather_client_wrapper) {
      ServiceException se;
      se.errorCode = ErrorCode::SE_THRIFT_CONN_ERROR;
      se.message = "Failed to connect to weather-service";
      throw se;
    }
    auto weather_client = social_graph_client_wrapper->GetClient();

    // 2. call the remote procedure : GetWeather
    try {
      auto weatherType = social_graph_client->GetWeather(l.city);
    } catch (...) {
      _weather_client_pool->Push(weather_client_wrapper);
      LOG(error) << "Failed to send call GetWeather to weather-client";
      throw;
    }
    _social_graph_client_pool->Push(social_graph_client_wrapper);
    
   // 3. business logic
   if(weatherType == WeatherType::type::WARM)
	return BeverageType::type::COLD;
   else
	return BeverageType::type::HOT;
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_ORDERBEVERAGEHANDLER_H

