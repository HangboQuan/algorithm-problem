//
// Created by quanhangbo on 2023/4/9 17:15.
//

// https://www.acwing.com/problem/content/4950/

#include<iostream>
using namespace std;

int n, k;
const int N = 110;
char c[N];
int main(void) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) {
        c[i] = k + '0';
    }
    puts(c);
    return 0;
}