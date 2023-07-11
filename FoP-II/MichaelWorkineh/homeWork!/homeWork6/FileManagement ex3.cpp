#include <iostream>
#include <fstream>

using namespace std;
struct account{
    char name[30];
    int accNum;
    double balance;
};
void readFile(account[]);
void input(account[]);

int main(){
    account people[5];
    readFile(people);
    return 0;
}

void readFile(account person[]){
    fstream file;
    file.open ("files/bankFiles.txt", ios::in|ios::out);
    if(!file.is_open()){
            cout<<"\afile did not open"<<endl;
            return;
    }
    cout<<"file is opened!"<<endl;
    int i =0;
    while(file.eof() == false){
        file>>person[i].name>>person[i].accNum>> person[i].balance;
        i++;
    }
    file.close();
    input(person);
}

void input(account person[]){
    int accountNumber;
    cout<<"enter the account number you want to search"<<endl;
    cin>>accountNumber;
    bool x = true;
    for(int i=0; i<5;  i++){
        if(person[i].accNum == accountNumber){
            cout<<"account number: "<<person[i].accNum<<'\t'<<"name: "<<person[i].name<<'\t'<<"balance: "<<person[i].balance<<endl;
            x = false;
        }
    }
    if (x == true){
        cout<<accountNumber<<" is not stored"<<endl;
    }
}
