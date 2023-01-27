//
// Created by quanhangbo on 2023/1/26 21:20.
//
#include<iostream>
#include<queue>

using namespace std;

void showq(queue<int> gq) {
    queue<int> g = gq;
    while(!g.empty()) {
        cout << g.front() << '\n';
        // deletes the first element of the queue
        g.pop();
    }
    cout << '\n';
}
int main(void) {
    queue<int> gquiz;
    // adds the element at the end of the queue
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    showq(gquiz);

    cout << gquiz.size() << endl;
    // returns a reference to the first element of the queue
    cout << gquiz.front() << endl;
    cout << gquiz.back() << endl;
}
