/*
Weather Client
You are going to develop a program that gets the statistics about weather in the current city
using information from a certain server. The goal is to calculate statistics using the data from weather server.
To communicate with the weather server you have to implement interface IWeatherServer,
which provides the raw string from the real server for the requested day and time.
The real server (i.e. "weather.com") gets the requests in this format:
"<date>;<time>", for example:
"31.08.2018;03:00"
The server answers on requests with string like this:
"20;181;5.1"
This string contains the weather for the requested time and means next:
"<air_temperature_in_celsius>;<wind_direction_in_degrees>:<wind_speed>".
Wind direction value may be in range from 0 to 359 inclusively, temperature may be negative.
The task:
1. Implement fake server, because interacting with real network is inacceptable within the unit tests.
To do this, you need to use real server responses. Fortunately, you've collected some results for the several dates from the weather server.
Each line means "<request>" : "<response>":
"31.08.2018;03:00" : "20;181;5.1"
"31.08.2018;09:00" : "23;204;4.9"
"31.08.2018;15:00" : "33;193;4.3"
"31.08.2018;21:00" : "26;179;4.5"
"01.09.2018;03:00" : "19;176;4.2"
"01.09.2018;09:00" : "22;131;4.1"
"01.09.2018;15:00" : "31;109;4.0"
"01.09.2018;21:00" : "24;127;4.1"
"02.09.2018;03:00" : "21;158;3.8"
"02.09.2018;09:00" : "25;201;3.5"
"02.09.2018;15:00" : "34;258;3.7"
"02.09.2018;21:00" : "27;299;4.0"
IMPORTANT:
* Server returns empty string if request is invalid.
* Real server stores weather only for times 03:00, 09:00, 15:00 and 21:00 for every date. Do not use other hours in a day.
2. Implement IWeatherClient using fake server.
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>

struct Weather
{
    short temperature;
    unsigned short windDirection;
    double windSpeed;
    bool operator==(const Weather& right) const
    {
        return temperature == right.temperature &&
               windDirection == right.windDirection &&
               std::abs(windSpeed - right.windSpeed) < 0.01;
    }
};

class IWeatherServer
{
public:
    virtual ~IWeatherServer() { }
    // Returns raw response with weather for the given day and time in request
    virtual std::string GetWeather(const std::string& request) = 0;
};

// Implement this interface
class IWeatherClient
{
public:
    virtual ~IWeatherClient() { }
    virtual double GetAverageTemperature(IWeatherServer& server, const std::string& date) = 0;
    virtual double GetMinimumTemperature(IWeatherServer& server, const std::string& date) = 0;
    virtual double GetMaximumTemperature(IWeatherServer& server, const std::string& date) = 0;
    virtual double GetAverageWindDirection(IWeatherServer& server, const std::string& date) = 0;
    virtual double GetMaximumWindSpeed(IWeatherServer& server, const std::string& date) = 0;
};

// TO DO list + test list:
// 1. Function ParseWeatherString parse string from server and create WeatherStruct
// 1.1 Correct string with positive temperature
// 1.2 Correct string with negative temperature
// 1.3 Empty string
// 1.4 String with invalid wind direction degree
// 1.5 Incorrect formatting
// 1.6 Acceptence
// 2. Method IWeatherServer::GetWeather Get weather struct from date string
// 2.1 Correct dates 03:00, 09:00, 15:00 and 21:00
// 2.2 Incorrect format
// 2.3 Incorrect time
// 2.4 Acceptence
// 3. Create server mock
// 4. Create WeatherClient
// 4.1. All functions: Get correct value
// 4.2. All functions: Get another correct value
// 4.3. All functions: Invalid input data

Weather ParseWeatherString(const std::string& input)
{
    Weather weather {0, 0, 0};
    size_t index1 = input.find(";", 0);
    size_t index2 = input.find(";", index1 + 1);
    if (index1 != -1 && index2 != -1)
    {
        weather.temperature = std::stol(input.substr(0, index1 + 1));
        weather.windDirection = std::stoul(input.substr(index1 + 1, index2));
        weather.windSpeed = std::stod(input.substr(index2 + 1));
    }
    return weather;
}

TEST(Weather, ParseResponseCorrect)
{
    Weather w = {20, 181, 5.1};
    EXPECT_EQ(w, ParseWeatherString("20;181;5.1"));
}

TEST(Weather, ParseResponseCorrect2)
{
    Weather w = {-24, 142, 7.1};
    EXPECT_EQ(w, ParseWeatherString("-24;142;7.1"));
}

TEST(Weather, ParseResponseEmpty)
{
    Weather w = {0, 0, 0};
    EXPECT_EQ(w, ParseWeatherString(""));
}

TEST(Weather, ParseResponseIncorrectDirection)
{
    Weather w = {0, 0, 0};
    EXPECT_EQ(w, ParseWeatherString("24;400;7.1"));
}
