//
// Created by quanhangbo on 2021/11/16 0:09.
//
//题目链接:https://leetcode-cn.com/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {
        long num = (long)sqrt(c);
        for(int i = 0; i <= num; i ++ ){
            long t = c - i * i;
            long l = 0, r = num;
            while(l < r){
                long mid = l + r + 1 >> 1;
                if(mid * mid <= t){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            if(l * l == t){
                return true;
            }
        }
        return false;
    }
};