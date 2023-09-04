#include <iostream>

using namespace std;
template <typename T>
T add(T a, T b){
    return a+b;
}
int main(){
    int result1;
    double result2;

    result1 = add <int>(1,2);
    result2 = add <double>(2.2,3.3);

    cout<<result1<<endl<<result2<<endl;

    return 0;
}

