//
// Created by quanhangbo on 2023/3/19 23:22.
//
// https://www.acwing.com/problem/content/4877/
// 给定n个num(n < 10^5), 判断num是否为美丽数(约数个数恰好为3的数), num < 10^12, 如果按照暴力做法枚举10^12的约数个数,
// 则会运行10^5 * 10^6 * sqrt(10^6) = 10^14次, 执行时间必定超1s
// 剪枝：
// 1. 约数只有3个的数字x只能是完全平方数, 排除1,n,第三个约数r = sqrt(x)
// 2. 根据算数基本定理：每个大于1的自然数, 只可写为2个或者以上质数的积, 质因子按照大小排列后, 写法仅有一种方式
//例: 6936 = 2^3 * 3 * 17^2  => r只能是质数
//最多计算次数：10^6 * sqrt(10^6) = 10^9, 可以通过

#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;

const int N = 1000010;
bool st[N];
int cnt = 1;

bool isPrime(int value) {
    for(int i = 2; i <= sqrt(value); i ++ ) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

void init_primes() {
    st[cnt ++] = false;
    for(int i = 2; i < N; i ++ ) {
        st[cnt ++] = isPrime(i);
    }
}

int main(void) {
    int n;
    init_primes();
    scanf("%d", &n);
    while(n --) {
        LL x;
        // 注意输入longlong类型的是%lld, 而不是%IId
        scanf("%lld", &x);
        LL result = sqrt(x);
        if (result * result == x && st[result]) puts("YES");
        else puts("NO");
    }
}


