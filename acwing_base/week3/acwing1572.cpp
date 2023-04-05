//
// Created by quanhangbo on 2023/4/5 14:53.
//

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 20;

int path[N];
int arr[N];
bool vis[N];
int n;

void dfs(int step, int len) {
    if (step == len) {
        for (int i = 0; i < len; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return ;
    }

    for (int i = 0; i < n; i ++ ) {
        if (!vis[i] && (step == 0 || path[step - 1] <= arr[i])) {
            path[step] = arr[i];
            vis[i] = true;
            dfs(step + 1, len);
            vis[i] = false;
            path[step] = 0;
            while (arr[i] == arr[i + 1]) i ++;
        }
    }
}
int main(void) {
    printf("\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);
    for (int i = 1; i <= n; i ++ ) {
        dfs(0, i);
    }
    return 0;
}