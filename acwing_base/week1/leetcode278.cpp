//
// Created by quanhangbo on 2021/11/17 22:57.
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// 题目链接：https://leetcode-cn.com/problems/first-bad-version/
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(!isBadVersion(mid)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }

    bool isBadVersion(int mid){
        // 处理逻辑
        return NULL;
    }
};