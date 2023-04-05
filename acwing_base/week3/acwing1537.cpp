//
// Created by quanhangbo on 2023/4/4 17:17.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n;
const int N = 10;
int path[N];
int arr[N];
bool vis[N];

void dfs(int step) {
    if (step == n) {
        for (int i = 0; i < n; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return ;
    }

    for (int i = 0; i < n; i ++ ) {
        if (!vis[i]) {
            path[step] = arr[i];
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
            path[step] = 0;
            while (arr[i] == arr[i + 1]) i ++;
        }
    }
}


int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    dfs(0);
    return 0;
}