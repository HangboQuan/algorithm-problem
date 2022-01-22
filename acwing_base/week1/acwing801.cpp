//
// Created by quanhangbo on 2022/1/22 12:04.
//

#include<iostream>
using namespace std;

/**
 * 位运算：
 *      求n的第k位数字：n >> k & 1
 *      返回n的最后一位1：lowbit(n) = n & -n
 * @param x
 * @return
 */
/*求出最右面的1的位置*/
int lowbit(int x){
    return x & -x;
}
int main(void){

    int n;
    cin >> n;

    while(n -- ){
        int x;
        cin >> x;

        int res = 0;
        while(x){

            x -= lowbit(x);
            res ++;
        }
        cout << res << " ";
    }
    return 0;
}