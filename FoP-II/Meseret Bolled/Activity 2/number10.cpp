#include <iostream>
using namespace std;

void inputFeetAndInches(int& feet, int& inches){
    cout << "Enter length in feet: ";
    cin >> feet;
    cout << "Enter length in inches: ";
    cin >> inches;
}

void inputMetersAndCentimeters(int& meters, float& centimeters){
    cout << "Enter length in meters: ";
    cin >> meters;
    cout << "Enter length in centimeters: ";
    cin >> centimeters;
}

void convertFeetAndInchesToMetersAndCentimeters(int feet, int inches, int& meters, float& centimeters){
    float total_inches = feet * 12 + inches;
    float total_meters = total_inches * 0.0254;
    meters = (int) total_meters;
    centimeters = (total_meters - meters) * 100.0;
}

void convertMetersAndCentimetersToFeetAndInches(int meters, float centimeters, int& feet, int& inches){
    float total_cm = meters * 100.0 + centimeters;
    float total_inches = total_cm;
    feet = (int) total_inches ;
    inches = (int) total_inches % 12;
}

void outputMetersAndCentimeters(int meters, float centimeters){
    cout << meters << " meters and " << centimeters << " centimeters." << endl;
}

void outputFeetAndInches(int feet, int inches){
    cout << feet << " feet and " << inches << " inches." << endl;
}

int main(){
    int choice;
    int feet, inches, meters, f, i;
    float centimeters;
    do{
        cout << "What do you want to convert?" << endl;
        cout << "1. Feet and Inches to Meters and Centimeters" << endl;
        cout << "2. Meters and Centimeters to Feet and Inches" << endl;
        cout << "0. Exit Program" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                inputFeetAndInches(feet, inches);
                convertFeetAndInchesToMetersAndCentimeters(feet, inches, meters, centimeters);
                outputMetersAndCentimeters(meters, centimeters);
                break;
            case 2:
                inputMetersAndCentimeters(meters, centimeters);
                convertMetersAndCentimetersToFeetAndInches(meters, centimeters, f, i);
                outputFeetAndInches(f, i);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(choice != 0);
    return 0;
}
