#include <iostream>
using namespace std;
//approach 1
int sum(int x, int y);
//approach 2
int sum2(int x[],int length);
int main(){
    //approach 1
    int array[]={1,2,3,4,5,6,7,8,9};
    cout<<"approach 1: "<<sum(array[0],array[8])<<endl;
    //approach 2
    cout<<"approach 2: "<<sum2(array,9)<<endl;
    return 0;
}

int sum(int x, int y){
    return x+y;
}

int sum2(int x[], int length){
    return x[0]+x[length-1];
}
