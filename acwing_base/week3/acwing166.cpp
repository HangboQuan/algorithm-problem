/*
//
// Created by quanhangbo on 2023/3/27 10:35.
//

#include<iostream>
#include<cstring>
using namespace std;

const int N = 10;
char g[N][N];
int gr[N][N];

// 按行遍历, 只记录列
bool col[N];
int path[N];
void dfs(int step) {

    if (step == 9) {
        for (int i = 0; i < 9; i ++ ) {
            for (int j = 0; j < 9; j ++ ) {
                printf("%d", gr[i][j]);
            }
        }
        puts("");
        return ;
    }
    for (int i = 0; i < 9; i ++ ) {
        // 什么时候放
        if (gr[step][i] == -1 && !col[i]) {
            gr[step][i] = i + 1;
            col[i] = true;
            dfs(step + 1);
            gr[step][i] = -1;
            col[i] = false;
        }
    }

}
int main(void) {
    char c;

    for (int i = 0; i < 9; i ++ ) {
        for (int j = 0; j < 9; j ++ ) {
            scanf("%c", &c);
            if (c == '.') gr[i][j] = -1;
            else gr[i][j] = c - '0';
        }
    }


    for (int i = 0; i < 9; i ++ ) {
        for (int j = 0; j < 9; j ++ ) {
            printf("%d ", gr[i][j]);
        }
        printf("\n");
    }
    dfs(0);
}*/
