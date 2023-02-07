//
// Created by quanhangbo on 2023/2/4 20:18.
//
#include<iostream>
#include<queue>
using namespace std;
int main(void){
    /**
     * priority queue is a type of container adapter, specifically designed such that the first element of
     * the queue is either the greatest or the smallest of all elements in the queue, and elements are non-increasing(非自增)
     * or non-decreasing order. priority queue are built on the top of the max heap and use an array or vector
     * as an internal structure. In C++ STL, priority queue is the implementation of Heap data structure.
     */
     int arr[6] = {10, 4, 6, 8, 9, 7};
     priority_queue<int> pq;

     for(auto i : arr) {
         cout << i << " ";
     }
     cout << endl;

     for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++ ) {
         pq.push(arr[i]);
     }

     // 10 9 8 7 6 4
     while(!pq.empty()) {
         cout << pq.top() << " ";
         pq.pop();
     }
     cout << endl;
     // 小顶堆
     priority_queue<int, vector<int>, greater<int>> pq1;
     pq1.push(30);
     pq1.push(20);
     pq1.push(23);
     pq1.push(29);

     // 20 23 29 30
     while(!pq1.empty()) {
         cout << pq1.top() << " ";
         pq1.pop();
     }
     cout << endl;

}

