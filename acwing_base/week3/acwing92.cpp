//
// Created by quanhangbo on 2023/3/30 17:28.
//

#include<iostream>
using namespace std;
const int N = 20;
int n;
bool vis[N];
int path[N];

void dfs(int step, int bit) {
    if (step == bit){
        for (int i = 0; i < bit; i ++ ) {
            if (path[i] != 0) {
                printf("%d ", path[i]);
            }
        }
        puts("");
        return ;
    }
    for (int i = 1; i <= n; i ++ ) {
        if(!vis[i] && step < bit) {
            path[step] = i;
            vis[i] = true;
            dfs(step + 1, bit + 1);
            vis[i] = false;
            path[step] = 0;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    dfs(0, 1);
    return 0;
}