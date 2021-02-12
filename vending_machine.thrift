namespace cpp vending_machine
namespace py vending_machine


struct location{
	1: i64 location_id;
	2: i64 city;
}

enum WeatherType{
	WARM,
	COLD
}

enum BeverageType{
	HOT,
	COLD
}

service OrderBeverageService{
	BeverageType PlaceOrder(
		1: location l
	)
}

service UpdateWeatherService{
	void UpdateWeather(
		1: i64 city,
		2: WeatherType w
	)
}

service WeatherService{
	WeatherType GetWeather(
		1: i64 city
	)
}
