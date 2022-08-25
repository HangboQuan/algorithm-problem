//
// Created by quanhangbo on 2022/8/25 10:42.
//

#include<iostream>
using namespace std;

// 朴素算法
// 思路：从主串s的第pos个字符和模式串p的第一个字符进行比较, 如果相等则继续逐个比较后续字符,
// 否则从主串的下一个字符起重新和模式进行比较

// 缺点: p = '00000000001' s = '000000000000000000000000000000000000000000000000000001'
// 会导致大量的回溯，时间复杂度o(n * m)
int indexOfString(string s, string p, int pos) {

    int i = pos, j = 0;
    while(i < s.length() && j < p.length()) {
        if(s[i] == p[j]) {
            i ++;
            j ++;
        }else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == p.length()) return i - p.length();
    else return -1;
}


int main(void) {
    string s, p;
    cin >> s >> p;
    cout << indexOfString(s, p, 1);
}