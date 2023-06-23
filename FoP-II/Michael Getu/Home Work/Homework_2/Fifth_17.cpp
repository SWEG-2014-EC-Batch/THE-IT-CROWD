#include <iostream>
#include <cmath>
using namespace std;

double calculateWindChill(double temperature, double windSpeed) {
    if (temperature > 10 || temperature < -50) {
        cout << "Invalid temperature. Temperature must be between -50 and 10 degrees Celsius." << endl;
        return -1.0;
    }

    double windChill = 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
    return windChill;
}

int main() {
    double temperature, windSpeed;
    cout << "Enter temperature in celcius: ";
    cin >> temperature;
    cout << "Enter wind speed: ";
    cin >> windSpeed;

    double windChill = calculateWindChill(temperature, windSpeed);
    if (windChill != -1.0) {
        cout << "Wind Chill Index: " << windChill << endl;
    }

    return 0;
}
