#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include "weather.h"
#include "utils.h"

#define API_KEY "YOUR_API_KEY"
#define CURRENT_WEATHER_URL "http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s"
#define FORECAST_URL "http://api.openweathermap.org/data/2.5/forecast/daily?q=%s&cnt=7&appid=%s"

char* get_current_weather(const char* city) {
    char url[256];
    snprintf(url, sizeof(url), CURRENT_WEATHER_URL, city, API_KEY);

    char* response = http_get(url);
    if (!response) return NULL;

    struct json_object* parsed_json;
    struct json_object* main;
    struct json_object* temp;
    struct json_object* humidity;
    struct json_object* weather;
    struct json_object* description;

    parsed_json = json_tokener_parse(response);
    json_object_object_get_ex(parsed_json, "main", &main);
    json_object_object_get_ex(main, "temp", &temp);
    json_object_object_get_ex(main, "humidity", &humidity);
    json_object_object_get_ex(parsed_json, "weather", &weather);
    weather = json_object_array_get_idx(weather, 0);
    json_object_object_get_ex(weather, "description", &description);

    char* weather_info = malloc(256);
    snprintf(weather_info, 256, "Temperature: %.2f°C\nHumidity: %d%%\nCondition: %s\n",
             json_object_get_double(temp) - 273.15,
             json_object_get_int(humidity),
             json_object_get_string(description));

    free(response);
    return weather_info;
}

char* get_weather_forecast(const char* city) {
    char url[256];
    snprintf(url, sizeof(url), FORECAST_URL, city, API_KEY);

    char* response = http_get(url);
    if (!response) return NULL;

    struct json_object* parsed_json;
    struct json_object* list;
    struct json_object* day;
    struct json_object* temp;
    struct json_object* weather;
    struct json_object* description;

    parsed_json = json_tokener_parse(response);
    json_object_object_get_ex(parsed_json, "list", &list);

    char* forecast_info = malloc(1024);
    strcpy(forecast_info, "");

    for (int i = 0; i < json_object_array_length(list); i++) {
        day = json_object_array_get_idx(list, i);
        json_object_object_get_ex(day, "temp", &temp);
        json_object_object_get_ex(day, "weather", &weather);
        weather = json_object_array_get_idx(weather, 0);
        json_object_object_get_ex(weather, "description", &description);

        char day_info[256];
       
