//
// Created by quanhangbo on 2023/3/30 9:34.
//

#include<iostream>
using namespace std;

const int N = 30;
int n, m;
int path[N];
bool vis[N];

void dfs(int step) {
    if (step == m) {
        for (int i = 0; i < m; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return ;
    }

    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i]) {
            if (m == 0 || path[step - 1] < i) {
                path[step] = i;
                vis[i] = true;
                dfs(step + 1);
                vis[i] = false;
                path[step] = 0;
            }
        }
    }
}

int main(void) {
    scanf("%d%d", &n, &m);
    dfs(0);
    return 0;
}