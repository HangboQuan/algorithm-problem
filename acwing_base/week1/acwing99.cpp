//
// Created by quanhangbo on 2021/12/21 8:57.
//

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5010;
int a[N][N];

int main(){
    int n, r;
    scanf("%d%d", &n, &r);

    r = min(r, 5001);
    for(int i = 0; i < n; i ++ ){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        x ++, y ++;
        a[x][y] += w;
    }

    for(int i = 1; i <= 5001; i ++ ){
        for(int j = 1; j <= 5001; j ++ ){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    int result = 0;
    for(int i = r; i <= 5001; i ++ ){
        for(int j = r; j <= 5001; j ++ ){
            result = max(a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r], result);
        }
    }

    printf("%d", result);
    return 0;
}
