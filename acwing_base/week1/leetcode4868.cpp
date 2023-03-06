//
// Created by quanhangbo on 2023/3/6 21:26.
//

#include<iostream>
#include<cstring>
#include<algorithm>

typedef long long LL;
const int INF = 1000;

int n;
int ans = INF;
using namespace std;


void dfs(LL x, int d) {

    bool st[10] = {0};
    int cnt = 0;
    for(LL i = x; i; i /= 10) {
        cnt ++;
        if (!st[i % 10]) {
            st[i % 10] = true;
        }
    }

    // 剪枝
    if (d + n - cnt >= ans) {
        return ;
    }

    // 剪枝
    if (cnt == n) {
        ans = d;
        return ;
    }
    for (int i = 9; i >= 2; i -- ) {
        if (st[i]) {
            dfs(x * i, d + 1);
        }
    }

}


int main(void) {
    int x;
    cin >> n >> x;
    dfs(x, 0);

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}