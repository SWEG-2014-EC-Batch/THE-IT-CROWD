#include<iostream>
using namespace std;

int count = 5;
void read_array(int arr[], int size);
void print_array(int arr[], int size);
int add_array(int arr[], int size);

int main() {
    int array[count];
    read_array(array, count);
    cout << "The array is: "<<endl; 
    print_array(array, count);
    int edge_sum = add_array(array, count);
    cout << "\nThe edge sum of the Array is: "<< edge_sum<<endl;
    return 0;
}

void read_array(int arr[], int size) {
    for (int i=0; i< size; i++) {
        cout << "Enter array element "<<i+1<<":";
        cin >> arr[i];
    }
}

void print_array(int arr[], int size) {
    for (int i=0; i< size; i++) {
        cout << arr[i]<<" ";
    }
}

int add_array(int arr[], int size) {
    int sum = arr[0] + arr[size-1];
    return sum;
}
