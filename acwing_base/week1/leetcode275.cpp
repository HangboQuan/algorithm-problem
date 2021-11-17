//
// Created by quanhangbo on 2021/11/17 22:44.
//
//题目链接：https://leetcode-cn.com/problems/h-index-ii/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& c) {
        int l = 0, r = c.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            // 右边的长度大于中点位置
            if(c.size() - mid <= c[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return c[l] >= c.size() - l ? c.size() - l : 0;
    }
};

