//
// Created by quanhangbo on 2023/1/26 21:20.
//
#include<iostream>
#include<queue>

using namespace std;

void showq(queue<int> gq) {
    queue<int> g = gq;
    while(!g.empty()) {
        cout << '\n' << g.front();
        g.pop();
    }
    cout << '\n';
}
int main(void) {
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    showq(gquiz);
}
