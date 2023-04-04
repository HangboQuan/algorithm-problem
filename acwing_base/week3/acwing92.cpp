//
// Created by quanhangbo on 2023/3/30 17:28.
//

// https://www.acwing.com/problem/content/94/ 递归实现指数型枚举
#include<iostream>
using namespace std;
const int N = 20;
int n;
bool vis[N];
int path[N];
/**
 * result:
1
2
3
1 2
1 3
2 3
1 2 3
 * @param step
 * @param len
 */
void dfs(int step, int len) {
    if (step == len) {
        for (int i = 0; i < len; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
    }

    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i] && (step == 0 || path[step - 1] < i)) {
            path[step] = i;
            vis[i] = true;
            dfs(step + 1, len);
            vis[i] = false;
            path[step] = 0;
        }
    }
}


int main(void) {
    printf("\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        dfs(0, i);
    }
    return 0;
}