//
// Created by quanhangbo on 2023/3/25 20:32.
//

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool col[N], dx[N], udx[N];


void dfs(int s) {
    if (s == n) {
        for (int i = 0; i < n; i ++ ) {
            puts(g[i]);
        }
        puts("");
        return ;
    }


    for (int i = 0; i < n; i ++ ) {
        if (!col[i] && !dx[n - s + i] && !udx[s + i]) {
            g[s][i] = 'Q';
            col[i] = dx[n - s + i] = udx[s + i] = true;
            dfs(s + 1);
            g[s][i] = '.';
            col[i] = dx[n - s + i] = udx[s + i] = false;
        }
    }


}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            g[i][j] = '.';
        }
    }

    dfs(0);
}

