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
    r.pop();
    while(!r.empty()) {
        if(s.empty() || s.top() <= t) {
            cout << t << endl;
            s.push(t);
            t = r.top();
            r.pop();

        } else {
            r.push(s.top());
            s.pop();
        }

    }
    s.push(t);



//    while (!s.empty()) {
//        cout << s.top() << endl;
//        s.pop();
//    }
    return s;
}

int main(void) {
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(3);

    stack<int> su = insertSort(s);
    while(!su.empty()) {
        cout << su.top() << " ";
        su.pop();
    }
}