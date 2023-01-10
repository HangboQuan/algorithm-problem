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
bool even(const int& value);
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

    /**
     * forward_list in STL is a singly linked list implementation. // forward是用单向链表实现的
     * forward_list :: before_begin(): The function returns an iterator that points to the position before the first
     * element of the forward_list.
     */

    forward_list<int> f1 = {20, 30, 40, 50};
    auto it = f1.before_begin();
    // inserting element before the first element
    f1.insert_after(it, 10);

    // loop to print the elements of the list
    // 10 20 30 40 50
    for(auto it = f1.begin(); it != f1.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;

    forward_list<string> f2 = {"dennis", "ritchie", "huge", "peter", "tom"};
    // forward_list :: cbefore_begin(): The function returns an constant iterator that points to the position before the first element of the forward_list
    auto it2 = f2.cbefore_begin();
    f2.insert_after(it2, "dollar");
    // dollar dennis ritchie huge peter tom
    for(auto it = f2.begin(); it != f2.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;
    // forward_list :: unique(): like normal list, unique operation on forward list

    // forward_list :: splice_after(): the function transfers the elements in the range of first + 1 to last from
    // a given forward_list. The elements are inserted after the element pointed to by position in the param
    // 传递从开始元素的下一个到元素末尾到被给定的forward_list
    // forward_list.name.splice_after(position iterator, forward_list_name, first iterator, last iterator)

    forward_list<int> forward_list3 = {11, 22, 33, 44};
    forward_list<int> forward_list4 = {4, 9};

    // 4 params
    // position: specifies the position in the forward_list after which the new elements are to be inserted
    // forward_list_name: specifies the list from which elements are to be inserted
    // first: specifies the iterator after which insertion is to be done
    // last: specifies the iterator till which insertion is to be done
    forward_list4.splice_after(forward_list4.begin(), forward_list3, forward_list3.begin(), forward_list3.end());
    // 4 22 33 44 9
    for(auto it = forward_list4.begin(); it != forward_list4.end(); ++ it) {
        cout << *it << " ";
    }
    cout << endl;

    forward_list<int> forward_list5 = {11, 22, 33, 44};
    forward_list<int> forward_list6 = {3, 10};
    forward_list6.splice_after(forward_list6.begin(), forward_list5, forward_list5.before_begin(), forward_list5.end());

    // 3 11 22 33 44 10
    for(auto it = forward_list6.begin(); it != forward_list6.end(); it ++ ) {
        cout << *it << " ";
    }
    cout << endl;

    // list :: remove(): the function is used to remove all the values from the list that correspond(对应) to the value given as param to the function
    // param: the value of the element to be removed is passed as the param
    list<int> list8{1, 2, 3, 3, 3, 3, 4};
    list8.remove(3);
    list8.remove(2);
    // do not throw exception
    list8.remove(10);
    // 1 4
    for(auto x : list8) {
        cout << x << " ";
    }
    cout << endl;

    // list :: remove_if(): the function is used to remove all the values from the list that correspond true to the
    // predicate or condition given as parameter to the function
    list<int> list9{1, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    list9.remove_if(even);
    for(auto x : list9) {
        cout << x << " ";
    }
    cout << endl;

    /**
     * emplace(position, value) : This function is used to insert an element at the specified position.
     * emplace_back(value) : This function adds value at end of list. it is different from push_back() by the fact
     * that it directly creates elements at position, whereas push_back() first makes a temporary copy and copies from there.
     * thus emplace_back(value) is faster in implementation than push_back() in most situations.
     * emplace_front(value) : This function adds value at begining of the List.
     */

    list<int> list10 ;
    list<int> :: iterator it10 = list10.begin();
    for(int i = 1; i <= 5; i ++ ) {
        list10.emplace_back(i);
    }
    // 1 2 3 4 5
    for(int& x : list10) {
        cout << x << " ";
    }
    cout << endl;

    for(int i = 1; i <= 5; i ++ ) {
        list10.emplace_front(i * 2);
    }
    // 10 8 6 4 2 1 2 3 4 5
    for(int& x : list10) {
        cout << x << " ";
    }
    cout << endl;
    // using advance() to advance iterator position 使用advance()来推进迭代器的位置
    advance(it10, 2);
    // 10 200 8 6 4 2 1 2 3 4 5
    list10.emplace(it10, 200);
    for(int& x : list10) {
        cout << x << " ";
    }
    cout << endl;

}
bool even(const int& value) {
    return value % 2 == 0;
}
