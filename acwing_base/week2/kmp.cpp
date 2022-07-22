//
// Created by quanhangbo on 2022/7/21 9:05.
//


#include<iostream>
using namespace std;

const int N = 100005, M = 1000005;
char p[N], s[M];
int ne[N];

void general(){
    int n, m;
    cin >> n >> p + 1 >> m >> s + 1;

    // 朴素算法，时间复杂度为 o(n * m)
    bool flag = false;
    for(int i = 1; i <= m; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            if(s[i + j - 1] != p[j]){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        cout << "pattern success";
    }else{
        cout << "pattern not success";
    }
}

void kmp0(){
    int n, m;
    cin >> n >> p + 1 >> m >> s + 1;

    // 求ne数组
    // 这里只需关注模式串，把模式串当做主串和模式串 来进行kmp匹配， i指向主串，j指向模式串
    // 如果出现匹配的话，ne[i] = j, 原因为: kmp求的是 模式串前缀最长和后缀最长的长度(即ne[]),也即主串和模式串
    // 实配之后，主串i接下来应该与模式串的第j为来比较(j = ne[j])
    for(int i = 2, j = 0; i <= n; i ++ ){
        while(j && p[i] != p[j + 1]){
            j = ne[j];
        }
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    // kmp的匹配过程 时间复杂度 o(2M)
    for(int i = 1, j = 0; i <= m; i ++ ){
        // j != 0 && 匹配的时候 i,j 指针向后移
        while(j && s[i] != p[j + 1]) {
            j = ne[j];
        }

        if(s[i] == p[j + 1]) j ++;
        // 循环结束条件 j == 0 || s[i] != p[j + 1]
        if(j == n){
            // 匹配成功
            cout << i - n;
            // 不懂这里 这是什么意思？这句注释掉也没问题
            // j = ne[j];
        }

    }
}

int main(){
    //general();
    kmp0();
}
