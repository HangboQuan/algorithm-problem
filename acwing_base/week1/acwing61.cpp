//
// Created by quanhangbo on 2022/1/24 18:26.
//

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        int n = s.size();
        int a[100010];
        int v = 0;
        for(int i = 0, j = 0; i < n; i ++ ){
            s[a[i]] ++;
            while(j < i && s[a[i]] > 1){
                s[a[j]] --;
                j ++;
            }
            v = max(v, i - j + 1);
        }
        return v;

    }


    int longestSubstringWithoutDuplication1(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        int v = 0;
        for(int i = 0, j = 0; i < n; i ++ ){
            map[s[i]] ++;
            while(j < i && map[s[i]] > 1){
                map[s[j]] --;
                j ++;
            }
            v = max(v, i - j + 1);
        }
        return v;
    }
};