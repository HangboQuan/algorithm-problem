//
// Created by quanhangbo on 2022/5/3 10:55.
//

/*#include<iostream>
using namespace std;

int main(void){
    int n, m;
    string p, s;
    scanf("%d%d", &n, &m);
    scanf("%s%s", &s, &p);

    for(int i = 0; i <= s.length(); i ++ ){
        string str = s.substr(i, i + n);
        if(str == p){
            printf("%d ", i);
        }
    }

    return 0;
}*/

#include<iostream>
using namespace std;

const int N = 10010, M = 100010;
int n, m;
int ne[N];
char s[M], p[N];
int main(void){
    // p为模式串, s为主串
    cin >> n >> p + 1 >> m >> s + 1;

    // 求ne[]过程
    for(int i = 2, j = 0; i <= n; i ++ ){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }


    // kmp匹配过程
    for(int i = 1, j = 0; i <= m; i ++ ){

        while(j && s[i] != p[j + 1]){
            j = ne[j];
        }
        if(s[i] == p[j + 1]) j ++;
        if(j == n){
            printf("%d ", i - n);
            j = ne[j];
        }

    }
}

