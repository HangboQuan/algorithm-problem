//
// Created by quanhangbo on 2022/4/26 20:13.
//

#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N], q[N];

int main(void){

    int n, k;
    scanf("%d%d", &n, &k);

    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    for(int i = 0; i < n; i ++ ){

        if(hh <= tt && i - k + 1 > q[hh]) hh ++;

        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[ ++tt] = i;

        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");


    hh = 0, tt = -1 ;
    for(int i = 0; i < n; i ++ ){
        if(hh <= tt && i - k + 1 > q[hh]) hh ++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[ ++tt] = i;

        if(i >= k - 1) printf("%d ", a[q[hh]]);
    }

    return 0;
}