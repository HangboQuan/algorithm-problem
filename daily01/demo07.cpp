//
// Created by quanhangbo on 2021/10/25.
//

// Acwing周赛：https://www.acwing.com/problem/content/description/4003/
#include<iostream>
#include<cmath>
using namespace std;
int main(void){
    int T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        cout << n - max(a + 1, n - b) + 1 << endl;
    }
    return 0;
}

