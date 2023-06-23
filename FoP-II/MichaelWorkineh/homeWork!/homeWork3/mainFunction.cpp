#include <iostream>
#include "stringLibrary.h"

using namespace std;
int main(){
    char input1[90],input2[90];

    //Question a) finding a string's length
    cout<<"input for Question a"<<endl;
    cin.getline(input1,90);
    cout<<stringLength(input1)<<endl;

    //Question b) reversing the a string
    cout<<"input for Question b"<<endl;
    cin.getline(input1,90);
    reverseString(input1);
    for(int i=0; i<stringLength(input1);i++){
        cout<<input1[i];
    }
    cout<<endl;

    //Comparing if 2 strings is are the same(returning 1 if so) or not(returning 0 in that case)
    cin.getline(input1,90);
    cin.getline(input2,90);
    cout<<compareString(input1,input2)<<endl;

    //Question c)Comparing if the first string length is greater than second string
    cout<<"input for Question c"<<endl;
    cin.getline(input1,90);
    cin.getline(input2,90);
    cout<<compareStrLength(input1,input2)<<endl;

    //Question d)Comparing changing all string elements to uppercase
    cout<<"input for Question d"<<endl;
    cin.getline(input1,90);
    makeUpper(input1);
    for(int i=0; i<stringLength(input1);i++){
        cout<<input1[i];
    }

    //Question d)Comparing changing all string elements to uppercase
    cout<<"input for Question e"<<endl;
    cin.getline(input1,90);
    makeSmall(input1);
    for(int i=0; i<stringLength(input1);i++){
        cout<<input1[i];
    }
    return 0;
}
