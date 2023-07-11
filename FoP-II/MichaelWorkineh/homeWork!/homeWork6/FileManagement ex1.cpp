#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void readFile(int[], int, char [], int);
int main(){
    int arraySize = 12, inputArray [arraySize];
    char fileName [90];
    cout<<"enter the file name only: ";
    cin.getline(fileName,90);
    readFile(inputArray,arraySize,fileName,strlen(fileName));
    for(int i = 0; i< arraySize; i++){
        cout<<inputArray[i]<<" ";
    }
    return 0;
}

void readFile(int num[], int arraySize, char fileName [], int nameSize){
    strcat(fileName,".txt");
    char location [] = "files/";
    strcat(location,fileName);
    fstream file;
    //"files/file1.txt"
    file.open (location, ios::in|ios::out);
    if(!file.is_open()){
            cout<<"\afile did not open"<<endl;
            return;
    }
    cout<<"file is opened!"<<endl;
    int i =0;
    while(file.eof() == false){
        file>>num[i];
        i++;
    }
    file.close();
}
