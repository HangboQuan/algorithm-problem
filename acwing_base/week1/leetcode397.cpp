//
// Created by quanhangbo on 2023/3/6 23:34.
//
#include<iostream>

using namespace std;
int ans;

// 有问题的dfs
void dfs(int n, int d) {
    if (n == 1) {
        ans = d;
        return;
    }


    if (n % 2 == 0) {
        dfs(n / 2, d + 1);
    } else {
        dfs(n + 1, d + 1);
        dfs(n - 1, d + 1);
    }
}


int integerReplacement(int n) {
    dfs(n, 0);
    return ans;
}
int main(void) {
    cout << integerReplacement(4);
}