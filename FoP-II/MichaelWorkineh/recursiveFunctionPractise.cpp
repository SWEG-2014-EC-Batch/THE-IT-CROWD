#include<iostream>
#include<cstring>
using namespace std;
void reverser(char str[], char reverseStr[], int strLength,int i);
int main(){
    char str[90], reverseStr[90];
    cin.getline(str,90);
    reverser(str , reverseStr, strlen(str),0);
    if(strcmp(str,reverseStr)==0){
        cout<<"it is a palindrome"<<endl;
    }
    else{
        cout<<"it isn't a palindrome"<<endl;
    }
    return 0;
}
void reverser(char str[], char reverseStr[], int strLength,int i){
    if(i==strLength){
        reverseStr[i]='\0';
        return;
    }
    else{
        reverseStr[strLength-1-i]=str[i];
         return reverser(str , reverseStr, strLength,i+1);
    }
}
