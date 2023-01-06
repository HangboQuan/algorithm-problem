//
// Created by quanhangbo on 2023/1/5 22:22.
//
#include<iostream>
#include<vector>

using namespace std;
// Vectors are the sames as dynamic arrays with the ability to resize itself automatically when an element is inserted
// or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous
//(连续的) storage so that they can be accessed and traversed using iterator. In vectors, data is inserted at the end.
/**
 * begin(): returns an iterator pointing to the first element in the vector
 * end(): returns an iterator pointing to the theoretical element that follows the last element in the
 * rbegin(): returns a reverse iterator pointing to the last element in the vector. It moves from last to first element
 * rend(): returns a reverse iterator pointing to the theoretical element preceding the first element in the vector(considered as reverse end)
 * @return
 */
int main() {
    vector<int> a;
    for(int i = 1; i <= 5; i ++ ) {
        a.push_back(i);
    }

    for(auto i : a) {
        cout << i << " ";
    }

    cout << endl;
    for(auto i = a.begin(); i < a.end(); i ++ ) {
        cout << *i << " ";
    }

    cout << endl;
    for(auto i = a.end() - 1; i >= a.begin(); i -- ) {
        cout << *i << " ";
    }

    cout << endl;
    for(auto i =  a.rbegin(); i < a.rend(); i ++ ) {
        cout << *i << " ";
    }

    cout << endl;
    // begin()和cbegin()的区别是什么 -> const_iterator和iterator的区别是什么? iterator可以改元素值, const_iterator
    // 元素值值不可更改
    // cbegin(): return a constant iterator pointing to the first element in the vector.
    for(auto i = a.cbegin(); i < a.cend(); i ++ ) {
        cout << *i << " ";
    }
}
