#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
//97
int main(){
    ifstream file;
    file.open("files/file8.txt", ios::in);

    if(!file.is_open()){
        cout<<"file could not be opend"<<endl;
        return 0;
    }
    char data [100];
    file>>data;
    cout<<"CHARACTER OCCURRENCES"<<endl;
    for(int i=0;i<26;i++){
        int counter=0;
        for (int j=0; j<strlen(data); j++){
            if(data[j]==char(97+i)){
                counter++;
            }
        }
        cout<<char(97+i)<<'\t'<<'\t'<<counter<<endl;
    }
    return 0;
}


