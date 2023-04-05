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

typedef pair<int, int> PII;
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

int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            scanf("%d", &g[i][j]);
        }
    }

    cout << bfs() << endl;
    return 0;
}