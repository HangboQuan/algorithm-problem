//
// Created by quanhangbo on 2022/2/21 23:10.
//
#include<iostream>
using namespace std;

const int N = 100010;
int stk[N], tt;
//欧几里得算法(辗转相除法)
/**
 * 即 证明gcd(a, b) = gcd(b, a % b)
 *
 * 证明：设c为a, b的公因子,则a = mc, b = nc, r = a % b存在k使得 r = a - kb, 则r = mc - knc = (m - kn)c
 * gcd(b, a % b) = gcd(nc, (m - kn)c) = gcd(n, (m - kn))c
 * gcd(a, b) = gcd(mc, nc) = gcd(m, n)c(c != 0)
 * 则gcd(m, n) = gcd(n, m - kn) => gcd(m, n) = gcd(n, m % n)
 */
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int gcd2(int a, int b){
    while(b != 0){
        int c = a;
        a = b;
        b = c % b;
    }
    return a;
}
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


    // 给定任意的两个数求最大公约数
    int a = 32, b = 20;
    int res = gcd2(a, b);
    cout << res << endl;
    return 0;
}