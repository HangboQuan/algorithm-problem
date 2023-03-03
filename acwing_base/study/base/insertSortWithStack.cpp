//
// Created by quanhangbo on 2023/3/3 23:22.
//

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// 用两个栈实现插入排序
stack<int> insertSort(stack<int> r) {
    stack<int> s;
    int t = r.top();
    cout << t << endl;
    while(!r.empty()) {
        if(s.empty() || s.top() <= t) {

            s.push(t);
            t = r.top();
            r.pop();

        } else {
            r.push(s.top());
            s.pop();
        }
    }
    return s;
}

int main(void) {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(9);
    s.push(6);

    stack<int> su = insertSort(s);
    while(!su.empty()) {
        cout << su.top() << " ";
        su.pop();
    }
}