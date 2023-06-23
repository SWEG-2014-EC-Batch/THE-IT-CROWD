#include <iostream>
#include <cstring>
using namespace std;
char statement[90];
char vowelPrinter(char x);
int main(){
    cin.getline(statement,90);
    //cycling through the different character stored in the string
    for (int i=0;i<strlen(statement)-1;i++){
        //checking if this character is a vowel
        if(toupper(statement[i])=='A'||toupper(statement[i])=='E'||toupper(statement[i])=='I'||toupper(statement[i])=='O'||toupper(statement[i])=='U'){
            //print what is returned b the function
            cout<<vowelPrinter(statement[i]);
        }
    }
    return 0;
}

char vowelPrinter(char x){
    //return the vowel character that is passed in to the function
    return x;
}
