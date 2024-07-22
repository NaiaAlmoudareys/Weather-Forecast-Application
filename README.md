# Advanced Weather Forecast Application

## Project Description
A professional command-line application to get the current weather and 7-day forecast for a given city using the OpenWeatherMap API.

## Features
- Display current weather for a given city.
- Display a 7-day weather forecast.
- Simple command-line interface for user interaction.
- Error handling for invalid city names and API issues.
- Weather details including temperature, humidity, wind speed, and conditions.
- Data caching to minimize API calls.

## Technology Stack
- **Language:** C
- **API:** OpenWeatherMap API
- **Libraries:** cURL, JSON-C

## Installation

### Dependencies
- cURL
- JSON-C

### Setup
1. Install the dependencies using your package manager. For example, on Ubuntu:
    ```sh
    sudo apt-get install libcurl4-openssl-dev libjson-c-dev
    ```

2. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/advanced-weather-forecast.git
    cd advanced-weather-forecast
    ```

3. Compile the program:
    ```sh
    gcc -o weather src/main.c src/weather.c src/utils.c -lcurl -ljson-c
    ```

4. Run the program:
    ```sh
    ./weather
    ```

## Usage
1. Enter a city name when prompted.
2. The current weather information and 7-day forecast for the city will be displayed.

## Contributing
Feel free to fork this project and submit pull requests. All contributions are welcome!

## License
This project is licensed under the MIT License.
