//
// Created by quanhangbo on 2023/2/16 21:46.
//

#include<iostream>
#include<string>
using namespace std;

int main(void) {

    string str("make america great again");
    for(string :: iterator it = str.begin(); it != str.end(); it ++ ) {
        cout << (*it);
    }
    cout << endl;
    // access first character m
    cout << str.front() << endl;
    // access last character n
    cout << str.back() << endl;
    // a
    cout << str.at(5) << endl;
    str += ", hello";
    // make america great again, hello
    cout << str << endl;
    // make america great again, hello world
    str.append(" world");
    cout << str << endl;

    string str1("123");
    // convert string to integer
    int value = stoi(str1);
    cout << value << endl;

    string str2("2147483647");
    long value1 = stol(str2);
    cout << value1 << endl;



}