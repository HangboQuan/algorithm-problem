//
// Created by quanhangbo on 2021/12/19 16:13.
//
#include<iostream>
using namespace std;

const int N = 1010;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            scanf("%d", &a[i][j]);
            // 构建初始的差分矩阵
            insert(i, j, i, j, a[i][j]);
        }
    }

    while(q -- ){
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }


    // 求b数组的前缀和 即原a数组 += c的结果
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }
        puts("");
    }
    return 0;
}
