#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    //syntax of of a set
    set<int> num;
    // value insertion into a set
    num.insert(10);
    num.insert(4);
    num.insert(3);
    num.insert(4);
    num.insert(32);
    num.insert(324);

    // naming of variables in a set
    set <int> :: iterator i, i1, i2;
    cout << "Elements: "<<endl;

    // by default set sorts its elements 
    // Set also removes duplicates
    /*
    getting values from a set, 
    */
    for (i = num.begin(); i !=num.end(); i++) {
        cout << *i << " ";
    }
    // finding elements in a set container
    i1 = num.find(4);
    i2 = num.find(10);
    //removing elements from a set
    num.erase(i1, i2);
    cout << "\nElements after erase"<<endl;
    for (i = num.begin(); i !=num.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}