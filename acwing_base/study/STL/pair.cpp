//
// Created by quanhangbo on 2023/1/4 22:20.
//

#include<iostream>
#include<utility>
using namespace std;

/**
 * pair is used to combine together two values that may be of different data types. Pair provides a way to store
 * two heterogeneous(adj. 异构的，不同类型的) objects as a single unit. It is basically used if we want to store
 * tuples. The pair container is a simple container defined in <utility> header consisting of two data elements
 * or objects.
 * 1. the order is fixed (first, second)
 * 2.
 * syntax: pair<data_type1, data_type2> Pair_name
 * @return
 */
int main() {
    pair<int, char> PAIR1;
    PAIR1.first = 100;
    PAIR1.second = 'G';

    // 100 G
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;

    // if don't set init value, using default value
    pair<int, int> PAIR2;
    // 0 0
    cout << PAIR2.first << " " << PAIR2.second << endl;

    // another valid syntax to declare pair or initialize a pair
    pair<int, char> PAIR3 = {1, 'a'};
    pair<int, char> PAIR4 = make_pair(2, 'b');
    pair<string, double> PAIR5("Geeks", 1.23);
    // 1 a
    // 2 b
    // Geeks 1.23
    cout << PAIR3.first << " " << PAIR3.second << endl;
    cout << PAIR4.first << " " << PAIR4.second << endl;
    cout << PAIR5.first << " " << PAIR5.second << endl;
    return 0;
}