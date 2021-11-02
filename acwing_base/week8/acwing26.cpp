//
// Created by quanhangbo on 2021/11/2.
//
class Solution {
public:
    /*int NumberOf1(int n) {
        if(n == 0) return 0;
        int cnt = 0;
        if(n < 0){
            cnt = 1;
            n = 2147483647 + n + 1;
        }

        while(n != 0){
            if(n % 2 == 1){
                cnt++;
            }
            n /= 2;
        }
        return cnt;
    }*/

    int NumberOf1(int n){
        unsigned int _n = n;
        int s = 0;
        while(_n){
            s += _n & 1;
            _n >>= 1;
        }
        return s;
    }
};
