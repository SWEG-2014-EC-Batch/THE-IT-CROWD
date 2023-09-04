#include<bits/stdc++.h>
using namespace std;

int main() {

    // same decleration with set
    multiset <int> num;
    num.insert(1);
    num.insert(2);
    num.insert(3);
    num.insert(2);
    num.insert(5);
    num.insert(3);
    num.insert(4);
    num.insert(7);
    num.insert(8);
    num.insert(9);
    num.insert(10);
    // declaring a variable
    multiset <int> :: iterator it, it1, it2;
    cout << "MUltiset element"<<endl;
    for (it = num.begin(); it !=num.end(); it++) {
        cout << *it<<" ";
    }
    cout << endl;
    
    // finding elements (same as set syntax)
    it1 = num.find(3);
    it2 = num.find(4);
    // removing eleements
    num.erase(it1, it2);
    cout << "Multiset after removal of elements"<<endl;
    for (it = num.begin(); it != num.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}