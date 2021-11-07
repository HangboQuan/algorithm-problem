//
// Created by quanhangbo on 2021/11/7 15:45.
//
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int arr[N];

// 二分
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++ ) scanf("%d", &arr[i]);

    while(m --){
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(arr[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(arr[l] != x){
            cout << "-1 -1" << endl;
        }else {
            cout << l << " ";
            int l = 0, r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(arr[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}
