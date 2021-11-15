//
// Created by quanhangbo on 2021/11/15 23:28.
//

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
// 题目链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower/
// 1 <= n <= 2^31 - 1
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l < r){
            // 注意这里写 l + r + 1 >> 1会超时，原因是数据范围l + r会溢出
            int mid = l + (r - l + 1) / 2;
            if(guess(mid) >= 0){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }

    int guess(int num){
        int pick = 6;
        if(num < pick) return -1;
        else if(num > pick) return 1;
        else return 0;
    }
};