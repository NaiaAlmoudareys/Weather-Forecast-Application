#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weather.h"
#include "utils.h"

int main() {
    char city[100];
    printf("Enter city name: ");
    scanf("%99s", city);

    char* current_weather = get_current_weather(city);
    char* forecast = get_weather_forecast(city);

    if (current_weather) {
        printf("\nCurrent Weather:\n%s\n", current_weather);
        free(current_weather);
    } else {
        printf("Error retrieving current weather information.\n");
    }

    if (forecast) {
        printf("\n7-Day Weather Forecast:\n%s\n", forecast);
        free(forecast);
    } else {
        printf("Error retrieving weather forecast information.\n");
    }

    return 0;
}
