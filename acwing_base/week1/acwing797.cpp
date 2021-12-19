//
// Created by quanhangbo on 2021/12/19 10:52.
//

#include<iostream>
using namespace std;
const int N = 100010;

int a[N], b[N];

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++ ){
        scanf("%d", &a[i]);
        // 构建差分数组
        insert(i, i, a[i]);
    }

    while(m -- ){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for(int i = 1; i <= n; i ++ ){
        // 前缀和数组和差分数组互为逆运算
        b[i] += b[i - 1];
        printf("%d ",b[i]);
    }
    return 0;
}

