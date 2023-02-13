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

    map<int, int> gquiz1;

    // initialization map
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 20));
    gquiz1.insert(pair<int, int>(4, 10));
    gquiz1.insert(pair<int, int>(5, 30));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1[7] = 20;

    map<int, int> :: iterator itr;
    for (itr = gquiz1.begin(); itr != gquiz1.end(); itr ++ ) {
        cout << itr -> first << " " << itr -> second << endl;
    }
    // 下面2个值 都是40 element access
    cout << gquiz1[1] << endl;
    cout << gquiz1.at(1) << endl;
    cout << "-----------------------" << endl;
    // copy gquiz1 map
    // find(): searches the container for an element with a key equivalent to k and returns an iterator to
    // it if found. otherwise it returns an iterator to map.end()
    map<int, int> gquiz2 (gquiz1.begin(), gquiz1.end());

    // 左开右闭
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); itr ++ ) {
        cout << itr -> first << " " << itr -> second << endl;
    }

    // count elements with a specific key
    cout << gquiz2.count(3) << endl;

    map<char, int> myMap;
    map<char, int> :: iterator itLow, itUp;
    myMap['a'] = 20;
    myMap['b'] = 40;
    myMap['c'] = 60;
    myMap['d'] = 80;
    myMap['e'] = 100;

    // lower_bound(): binary search >=
    // upper_bound(): binary search >
    itLow = myMap.lower_bound('b');
    itUp = myMap.upper_bound('d');
    // del [itLow, itUp)
    myMap.erase(itLow, itUp);

    // a 20
    // e 100
    for (map<char, int> :: iterator it = myMap.begin(); it != myMap.end(); it ++ ) {
        cout << it->first << " " << it->second << endl;
    }


    // if not found, return an iterator to end
    pair<map<char, int> :: iterator, map<char, int> :: iterator> its;
    its = myMap.equal_range('a');
    // when the parm is 'a', the result is a 20 e 100
    // when the parm is 'b', the result is e 100 e 100
    cout << its.first -> first << " " << its.first -> second << endl;
    cout << its.second -> first << " " << its.second -> second << endl;

    // unordered_map unsorted


}