//
// Created by quanhangbo on 2023/3/22 12:48.
//

// 并查集
#include<iostream>
using namespace std;
const int N = 100010;
int p[N]; // 祖先节点
int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++ ) {
        p[i] = i;
    }
    while(m -- ) {
        int a, b;
        char op[2];
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'M') {
            p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}