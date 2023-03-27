//
// Created by quanhangbo on 2023/3/26 20:26.
//

//#include<iostream>
//using namespace std;
//int n;
//
//const int N = 10;
//int path[N];
//bool vis[N];
//
//void dfs(int s) {
//    if (s == n) {
//        for (int i = 0; i < n; i ++ ) {
//            printf("%d", path[i]);
//        }
//        puts("");
//    }
//
//    for (int i = 1; i <= n; i ++ ) {
//        if (!vis[i]) {
//            path[s] = i;
//            vis[i] = true;
//            dfs(s + 1);
//            path[s] = 0;
//            vis[i] = false;
//        }
//    }
//}
//int main(void) {
//    scanf("%d", &n);
//    dfs(0);
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//int n;
//const int N = 10;
//char g[N][N];
//bool col[N], dx[N], udx[N];
//
//void dfs(int s) {
//    if (s == n) {
//        for (int i = 0; i < n; i++) {
//            puts(g[i]);
//        }
//        puts("");
//        return;
//    }
//    for (int i = 0; i < n; i ++) {
//        if (!col[i] && !dx[i + s] && !udx[i - s + n]) {
//            g[s][i] = 'Q';
//            col[i] = dx[i + s] = udx[i - s + n] = true;
//            dfs(s + 1);
//            g[s][i] = '.';
//            col[i] = dx[i + s] = udx[i - s + n] = false;
//        }
//    }
//
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
//    return 0;
//}


//
// Created by quanhangbo on 2023/3/26 20:26.
//

//#include<iostream>
//using namespace std;
//int n;
//
//const int N = 10;
//int path[N];
//bool vis[N];
//
//void dfs(int s) {
//    if (s == n) {
//        for (int i = 0; i < n; i ++ ) {
//            printf("%d", path[i]);
//        }
//        puts("");
//    }
//
//    for (int i = 1; i <= n; i ++ ) {
//        if (!vis[i]) {
//            path[s] = i;
//            vis[i] = true;
//            dfs(s + 1);
//            path[s] = 0;
//            vis[i] = false;
//        }
//    }
//}
//int main(void) {
//    scanf("%d", &n);
//    dfs(0);
//    return 0;
//}


#include<iostream>
using namespace std;

const int N = 10;
char g[N][N];
bool col[N], dx[N], udx[N];
int n;


void dfs(int s) {
    if (s == n) {
        for (int i = 0; i < n; i ++ ) {
//            for (int j = 0; j < n; j ++ ) {
//                printf("%c ", g[i][j]);
//            }
            puts(g[i]);
        }
        puts("");
        return ;
    }

//    for (int i = 0; i < n; i ++ ) {
//        if (!col[i] && !dx[s + i] && !udx[n - s + i]) {
//            g[s][i] = 'Q';
//            col[i] = dx[s + i] = udx[n - s + i] = true;
//            dfs(s + 1);
//            g[s][i] = '.';
//            col[i] = dx[s + i] = udx[n - s + i] = false;
//        }
//    }

    for (int i = 0; i < n; i ++ ) {
//        printf("%d ", n - s + i);
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
//    return 0;
}