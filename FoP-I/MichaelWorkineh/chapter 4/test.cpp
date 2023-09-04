#include <iostream>

using namespace std;
template <typename T>
T biggest(T a, T b){
    return (a>b)? a: b;
}
int main(){
    cout<<biggest(1,2)<<endl<<biggest('a', 'b');
    return 0;
}
