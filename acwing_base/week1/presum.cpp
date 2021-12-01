//
// Created by quanhangbo on 2021/12/1 12:49.
//

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
/**
 * 给定数列：a1,a2,,,ai
 * si = a1+a2+,,,+ai
 * 前缀和的作用是求区间和，但是注意不要越界（可能会爆int）
 * @return
 */
int main(void){
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    int s[n + 1];
    for(int i = 1; i <= n; i ++ ) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }

    for(int i = 0; i < m; i ++ ){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}