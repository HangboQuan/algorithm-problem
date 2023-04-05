//
// Created by quanhangbo on 2023/4/5 16:18.
//

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 25;
int path[N];
int arr[N];
bool vis[N];

int n, m;

void dfs(int step) {
    if (step == m) {
        for(int i = 0; i < m; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return ;
    }

    for (int i = 0; i < n; i ++ ) {
        if (!vis[i] && (step == 0 || path[step - 1] <= arr[i])) {
            path[step] = arr[i];
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
            path[step] = 0;
            // 剪枝
            while(arr[i] == arr[i + 1]) i ++;
        }
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    dfs(0);
    return 0;
}