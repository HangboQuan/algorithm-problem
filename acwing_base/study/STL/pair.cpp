//
// Created by quanhangbo on 2023/1/4 22:20.
//

#include<iostream>
#include<utility>
#include<bits/stdc++.h>
using namespace std;

/**
 * C++ Standard Template Library
 * it is a set of C++ template class to provide common programming data structures and functions such as
 * lists, stacks, arrays, etc.
 *
 * STL has 4 components:
 * 1.Algorithms
 * 2.Containers
 * 3.Functions
 * 4.Iterators
 */

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

    // another valid syntax to declare pair or initialize a pair, This template function allows to
    // create a value pair without writing the types explicitly.
    pair<int, char> PAIR3 = {1, 'a'};
    pair<int, char> PAIR4 = make_pair(2, 'b');
    pair<string, double> PAIR5("Geeks", 1.23);
    // 1 a
    // 2 b
    // Geeks 1.23
    cout << PAIR3.first << " " << PAIR3.second << endl;
    cout << PAIR4.first << " " << PAIR4.second << endl;
    cout << PAIR5.first << " " << PAIR5.second << endl;

    // 交换两个pair对象，前提是pair的类型 This function swaps the contents of one pair object with the contents of
    // another pair object. The pairs must be of the same type.
    PAIR3.swap(PAIR4);
    cout << PAIR3.first << " " << PAIR3.second << endl;


    // tie() tie(int &, int &) = pair1
    // This function works the same as in tuples. It creates a tuple of lvalue references to its arguments,
    // to unpack the tuple values into separate variables. 类似于元组的数据结构，创建了一个左值引用的元组，把元组的值
    // 压缩为单个值? tie()的实际用处是什么?
    pair<int, int> pair1 = {1, 2};
    int a, b;
    tie(a, b) = pair1;
    // 引用赋值 1 2
    cout << a << " " << b << endl;

    pair<int, int> pair2 = {3, 4};
    // 3 2
    tie(a, ignore) = pair2;
    cout << a << " " << b << endl;

    pair<int, pair<int, char>> pair3 = {3, {4, 'a'}};
    int x, y;
    char z;
    x = pair3.first;
    // tie() => 通过引用来进行赋值
    tie(y, z) = pair3.second;
    // 3 4 a
    cout << x << " " << y << " " << z << endl;
    return 0;
}