//
// Created by quanhangbo on 2023/3/25 20:14.
//

#include<iostream>
using namespace std;

const int N = 10;
int path[N];
bool vis[N];
int n;

// 全排列
void dfs(int s) {
    if (s == n) {
        for (int i = 0; i < n; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return ;
    }

    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i]) {
            path[s] = i;
            vis[i] = true;
            dfs(s + 1);
//            path[s] = 0; 恢复原位，但是这里每次path[s]的值是被覆盖的，所以不用恢复也行
            vis[i] = false;
        }
    }

}


int main(void) {
    scanf("%d", &n);
    dfs(0);
    return 0;
}