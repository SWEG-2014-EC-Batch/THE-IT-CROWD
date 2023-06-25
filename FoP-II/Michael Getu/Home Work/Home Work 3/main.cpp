#include<iostream>
#include"Local_Library.h"
using namespace std;

int main() {
    char word1[100], word2[100];
    int vow_count, cons_count, str_len;

    cout <<"Question (1):"<<endl;
    
    cout<<"Length of string, vowel and consonant count"<<endl;
    cout << "Enter a string: ";
    cin.getline(word1, 100);
    str_len = string_length(word1);
    cout << "The string Length is: "<<str_len<<endl;
    cout << "Number of vowels and consonants in the string"<<endl;
    vowel_consonant(word1, vow_count, cons_count);
    cout << "The number of vowels is: "<<vow_count<<endl;
    cout << "The number of Consonants is: "<<cons_count<<endl;

    cout << "Question (2):"<<endl;

    cout <<"Reverse of a string"<<endl;
    cout << "Enter a string: ";
    cin.getline(word1, 100);
    string_reverse(word1);
    cout << "The reverse of the string is: "<<word1<<endl;

    cout << "Question (3):"<<endl;

    cout << "String Comparision"<<endl;
    cout << "Enter first string: ";
    cin.getline(word1, 100);
    cout << "Enter second string: ";
    cin.getline(word2, 100);
    int return_val = string_compare(word1, word2);
    cout << "The compare value is: "<<return_val<<endl;

    cout << "Question (4):"<<endl;

    cout << "String Conversion to upper"<<endl;
    cout << "Enter first string: ";
    cin.getline(word1, 100);
    to_upper(word1);
    cout << "The upper string is: "<<word1<<endl;

    cout << "Question (5):"<<endl;

    cout << "String Conversion to lower"<<endl;
    cout << "Enter first string: ";
    cin.getline(word1, 100);
    to_lower(word1);
    cout << "The lower string is: "<<word1<<endl;
  
return 0;
}
