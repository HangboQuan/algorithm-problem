//
// Created by quanhangbo on 2023/4/5 19:40.
//

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 110;
// g 为原数组， d 为结果数组
int g[N][N];
int d[N][N];

int ans = 110;

typedef pair<int, int> PII;

//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, 1, 0, -1};
int matrix[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;

int bfs() {
    queue<PII> q;
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    // 初始化
    q.push({0, 0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++ ) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }

    }
    return d[n - 1][m - 1];

}

void dfs(int x, int y, int step) {
    if (x == n - 1 && y == m - 1) {
        if (step < ans) {
            ans = step;
        }
        return ;
    }

    for (int i = 0; i < 4; i ++ ) {
        int tx = x + matrix[i][0];
        int ty = y + matrix[i][1];

        if (tx >= 0 && tx < n && ty >= 0 && ty < m && g[tx][ty] == 0 && d[tx][ty] == -1) {
            d[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            d[tx][ty] = -1;
        }
    }
}

int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            scanf("%d", &g[i][j]);
        }
    }
    memset(d, -1, sizeof(d));
    cout << bfs() << endl;
    // 使用dfs 的话 无法通过 会报TLE
//    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}

