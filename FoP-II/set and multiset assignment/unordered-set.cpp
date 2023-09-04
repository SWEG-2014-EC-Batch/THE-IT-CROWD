#include<bits/stdc++.h>
using namespace std;

int main() {

    unordered_set <int> num;

    num.insert(1);
    num.insert(2236);
    num.insert(23);
    num.insert(354);
    num.insert(46);
    num.insert(54);
    num.insert(7);

    unordered_set <int>:: iterator it, it1;

    cout << "Unordered set elements"<<endl;

    for (it = num.begin(); it !=num.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    it1 = num.find(7);

    num.erase(it1);
    cout << "Unordered set elements" <<endl;
    for (it = num.begin(); it !=num.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}







