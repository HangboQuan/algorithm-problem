//
// Created by quanhangbo on 2023/3/19 23:22.
//

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;

const int N = 100010;
int st[N];

// 初始化10^5以内的所有质数
void init_primes() {

}

int main(void) {
    int n;
    init_primes();
    scanf("%d", &n);
    while(n --) {
        LL x;
        scanf("&IId", &x);

        int result = sqrt(x);
        if (result * result == x && st[result]) puts("YES");
        else puts("NO");

    }

}
