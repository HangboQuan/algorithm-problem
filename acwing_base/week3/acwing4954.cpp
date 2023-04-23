//
// Created by quanhangbo on 2023/4/23.
//

#include<iostream>
using namespace std;

int n, l, r, x;
const int N = 15;
int w[N];

int dfs(int u, int cnt, int sum, int minw, int maxw) {
    if (u == n) {
        return cnt >= 2 && sum >= l && sum <= r && maxw - minw >= x;
    }
    int res = 0;
    // 不选
    res += dfs(u + 1, cnt, sum, minw, maxw);
    // 选
    res += dfs(u + 1, cnt + 1, sum + w[u], min(w[u], minw), max(w[u], maxw));
    return res;
}
int main(void) {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i ++ ) {
        cin >> w[i];
    }

    cout << dfs(0, 0, 0, 1e7, 0) << endl;
    return 0;
}