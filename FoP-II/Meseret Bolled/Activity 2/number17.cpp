#include <iostream>
#include <cmath>

using namespace std;

double windChill(double windSpeed, double temperature) {
    if (temperature >= 10) {
        return temperature;
    } else {
        double windChillIndex = 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
        return windChillIndex;
    }
}

int main() {
    double windSpeed, temperature;
    cout << "Enter the wind speed in m/sec: ";
    cin >> windSpeed;
    cout << "Enter the temperature in degrees Celsius: ";
    cin >> temperature;
    double windChillIndex = windChill(windSpeed, temperature);
    cout << "The windchill index is: " << windChillIndex << " degrees Celsius" << endl;
    return 0;
}
