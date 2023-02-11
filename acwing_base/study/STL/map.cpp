//
// Created by quanhangbo on 2023/2/10 20:11.
//
#include<iostream>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>
/**
 * Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a
 * mapped value. No two mapped values can have the same key vales
 */
using namespace std;
int main(void) {
    map<string, int> m;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;

    map<string, int> :: iterator it = m.begin();
    while (it != m.end()) {
        cout << "key: " << it -> first << ", value: " << it -> second << endl;
        ++ it;
    }
}