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

/**
 * Queues are a type of container adaptors that operate in a first in first out type of arrangement. Elements are inserted
 * at the back and deleted from the front.
 * @return
 */
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

    // emplace(): this function is used to insert a new element into the queue container, the new element is added to the end of the queue
    queue<int> myqueue;
    myqueue.emplace(1);
    myqueue.emplace(2);
    myqueue.emplace(3);
    myqueue.emplace(4);
    myqueue.emplace(5);

    while(!myqueue.empty()) {
        cout << myqueue.front() << " ";
        myqueue.pop();
    }
    cout << endl;
    // swap(): this function is used to exchange the contents of two queues but the queues must be of same type, although size may differ
    queue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue<int> queue2;
    queue2.push(-9);
    queue2.push(-6);
    queue2.push(-2);
    queue2.push(-1);
    queue1.swap(queue2);
    while(!queue1.empty()) {
        cout << queue1.front() << " ";
        queue1.pop();
    }
    cout << endl;
    while(!queue2.empty()) {
        cout << queue2.front() << " ";
        queue2.pop();
    }
}
