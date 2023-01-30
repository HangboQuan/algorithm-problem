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

}
