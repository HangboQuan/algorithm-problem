//
// Created by quanhangbo on 2023/4/6 22:03.
//

#include<iostream>
using namespace std;
int n, k;
string str;

int ans;

void dfs(int step, int k, int sum) {
    if (step >= n || k < 0) {
        if (k < 0) {
            ans = max(ans, sum);
        }
        return ;
    }

    int s = 0;
    for (int i = step; i < n; i ++ ) {
        s = s * 10 + (str[i] -'0');
        cout << s << " " << sum * s << endl;
        dfs(i + 1, k - 1, sum * s);
    }
}

int main(void) {
    scanf("%d%d", &n, &k);
    cin >> str;
    dfs(0, k, 1);
    cout << ans << endl;
    return 0;
}