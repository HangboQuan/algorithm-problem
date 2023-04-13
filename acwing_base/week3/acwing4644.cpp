//
// Created by quanhangbo on 2023/4/13 22:50.
//

#include<iostream>
using namespace std;

const int N = 200010;
int n;
int arr[N];
int sum[N];

// 前缀和
int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i -- ) {
        sum[i] = sum[i + 1] + arr[i];
    }

    long long res = 0L;
    for (int i = 0; i < n; i ++ ) {
        res += arr[i] * (sum[i] - arr[i]);
    }
    cout << res << endl;
}