//
// Created by quanhangbo on 2023/3/6 21:07.
//

#include<iostream>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    int mod = n % k;
    if (mod == 0) {
        n = n + k;
    } else {
        n = n + abs(mod - k);
    }
    cout << n << endl;
}