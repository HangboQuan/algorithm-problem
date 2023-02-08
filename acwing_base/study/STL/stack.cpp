//
// Created by quanhangbo on 2023/2/7 19:51.
//

#include<iostream>
#include<stack>
using namespace std;

int main(void) {
    /**
     * Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new
     * element is added at one end(top) and an element removed from that end only.
     */

    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(23);
    stack.push(25);

    while(!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}
