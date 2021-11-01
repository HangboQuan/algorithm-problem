//
// Created by quanhangbo on 2021/10/25.
//
//Acwing周赛：https://www.acwing.com/problem/content/description/4004/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;
int a[N], b[N], cnt[N];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    while(k--){
        int x, y;
        cin >> x >> y;
        // 预处理矛盾关系
        if(a[x] > a[y]){
            cnt[x]++;
        }
        if(a[x] < a[y]){
            cnt[y]++;
        }
    }

    // 使用二分排序，找到b数组的元素在a数组出现的位置
    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; i++){
        int l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(b[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }

        cout << r - 1 - cnt[i] << " ";

    }



    return 0;

    while(hair--);
}

