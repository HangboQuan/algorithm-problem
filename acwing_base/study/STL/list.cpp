//
// Created by quanhangbo on 2023/1/9 8:49.
//

#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/**
 * Lists are containers used in C++ to store data in a non-contiguous(不连续的) fashion(方式), Normally, Arrays and
 * Vectors are contiguous in nature, therefore the insertion and deletion operations are costlier as compared to
 * the insertion and deletion option in Lists.
 * List是非连续的存储结构，因此其插入和删除元素的花销更少
 * @return
 */
int main() {
    // empty(): this function is used to check if the list container is empty or not
    // size(): this function is used to the size of the list container or the number of elements in the list container
    // front(): this function is used to reference the first element of the list container. it can be used to fetch the first element of a list
    // back(): this function is used to reference the last element of the list container. it can be used to fetch the last element of a list

    list<int> list0 {};
    cout << list0.empty() << endl;
    if (list0.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    list<int> list1 {1, 5, 6, 3, 9, 2};
    cout << list1.size() << endl; // 6
    cout << list1.front() << endl; // 1
    cout << list1.back() << endl; // 2
    int sum = 0;
    while(!list1.empty()) {
        sum += list1.front();
        list1.pop_front();
    }
    cout << sum << endl; // 26

    /**
     * pop_front(): this function is used to pop or remove elements from a list from the front. the value is removed
     * from the list from the beginning, and container size is decreased by 1
     *
     * pop_back(): this function is used to pop or remove elements from a list from the last
     */

    list<int> list2 {9, 8, 7, 5, 3, 2};
    list2.pop_front();
    list2.pop_front();
    // 7 5 3 2
    for(auto x : list2) {
        cout << x << " ";
    }
    cout << endl;
    list2.pop_back();
    // 7 5 3
    for(auto x : list2) {
        cout << x << " ";
    }
    cout << endl;

    // push_front(): this function is used to push elements into a list from the front
    // push_back(): this function is used to push elements into a list from the back
    list<int> list3 {7, 9, 3, 4, 1, 8};
    list3.push_front(2);
    list3.push_front(0);
    list3.push_back(-1);
    list3.push_back(-2);
    // 0 2 7 9 3 4 1 8 -1 -2
    for(auto x : list3) {
        cout << x << " ";
    }
    cout << endl;

    list<int> list4;
    // 101 98 12 11 23 44
    list4.push_front(44);
    list4.push_front(23);
    list4.push_front(11);
    list4.push_front(12);
    list4.push_front(98);
    list4.push_front(101);

    list4.sort();
    // 11 12 23 44 98 101
    for(auto x : list4) {
        cout << x << " ";
    }
    cout << endl;

    // reverse(): this function is used to reverse a list container. it reverses the order of  elements in the list container
    /**
     * 1. if the list already has more than n elements, then the function erases the elements from the list except the first n element
     * 2. if the list less than n elements, adds the difference number of elements to the list with their default values
     * 3. the function also have 2 params n, val,this params is only the container's size less than n then adds elements to the list with their value assigned to val
     */
    list<string> list5 = {"Tom", "Dennis", "Tourist", "Trump"};
    list5.reverse();
    // Trump Tourist Dennis Tom
    for(auto x : list5) {
        cout << x << " ";
    }
    cout << endl;
    list5.sort();
    // Dennis Tom Tourist Trump
    for(auto it = list5.begin(); it != list5.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;

    // resize():
    list<int> list6 = {10, 12, 19, 34, 98, 101};
    list6.resize(3);
    // 10 12 19
    for(auto x : list6) {
        cout << x << " ";
    }
    cout << endl;
    // 10 12 19 0 0 0
    list6.resize(6);
    for(auto x : list6) {
        cout << x << " ";
    }
    cout << endl;
    // 10 12 19 0 0
    list6.resize(5, 20);
    for(auto x : list6) {
        cout << x << " ";
    }
    cout << endl;
    // 10 12 19 0 0 20
    list6.resize(6, 20);
    for(auto x : list6) {
        cout << x << " ";
    }
    cout << endl;

    // unique(): this function removes all consecutive duplicate elements from the list. it uses binary
    // predicate for comparison
    list<int> list7 = {1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 4};
    list7.unique();
    // 1 2 1 2 1 4
    for(auto x : list7) {
        cout << x << " ";
    }
    cout << endl;
}
