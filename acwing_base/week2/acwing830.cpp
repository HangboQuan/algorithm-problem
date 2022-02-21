//
// Created by quanhangbo on 2022/2/21 23:10.
//
#include<iostream>
using namespace std;

const int N = 100010;
int stk[N], tt;
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++ ){
        int x;
        scanf("%d", &x);
        while(tt && stk[tt] >= x) tt --;
        if(tt) cout << stk[tt] << " ";
        else cout << -1 << " ";

        stk[++ tt] = x;
    }
    return 0;
}