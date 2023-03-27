//
// Created by quanhangbo on 2023/3/25 20:32.
//

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 10;
//
//int n;
//char g[N][N];
//bool col[N], dx[N], udx[N];
//
//
//void dfs(int s) {
//    if (s == n) {
//        for (int i = 0; i < n; i ++ ) {
//            puts(g[i]);
//        }
//        puts("");
//        return ;
//    }
//
//
//    for (int i = 0; i < n; i ++ ) {
//        // cout << n - s + i << endl;
//        // 这里为什么不会数组越界异常呢？很奇怪？
//        if (!col[i] && !dx[n - s + i] && !udx[s + i]) {
//            g[s][i] = 'Q';
//            col[i] = dx[n - s + i] = udx[s + i] = true;
//            dfs(s + 1);
//            g[s][i] = '.';
//            col[i] = dx[n - s + i] = udx[s + i] = false;
//        }
//    }
//}
//
//int main(void) {
//    scanf("%d", &n);
//    for (int i = 0; i < n; i ++ ) {
//        for (int j = 0; j < n; j ++ ) {
//            g[i][j] = '.';
//        }
//    }
//
//    dfs(0);
//}

#include<iostream>
using namespace std;
const int N = 20;
int n;

char g[N][N];
bool row[N], col[N], dx[N], udx[N];
void dfs(int x, int y, int s) {
    if (y == n){
        y = 0;
        x ++;
    }

    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i ++ ) {
                puts(g[i]);
            }
            puts("");
        }
        return ;
    }

    // 两种情况 放皇后 or 不放皇后
    dfs(x, y + 1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dx[x + y] && !udx[y - x + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dx[x + y] = udx[y - x + n] = true;
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dx[x + y] = udx[y - x + n] = false;
    }



}
int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            g[i][j] = '.';
        }
    }
    // 分别代表下标值 和 存放的皇后数
    dfs(0, 0, 0);
    return 0;
}

