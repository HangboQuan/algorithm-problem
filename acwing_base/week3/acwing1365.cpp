//
// Created by quanhangbo on 2023/4/24.
//

#include<iostream>
using namespace std;

const int N = 40;
int w[N];
int n;

/**
 * 暴力可以算出正确答案，但是会TLE，当N=31是超时  正确的解决方法是动态规划
 * @param step
 * @param leftSum
 * @param rightSum
 * @return
 */
int dfs(int step, int leftSum, int rightSum) {
    if (step > n) {
        return leftSum == rightSum;
    }
    int res = 0;
    res += dfs(step + 1, leftSum + w[step], rightSum);
    res += dfs(step + 1, leftSum, rightSum + w[step]);
    return res;
}
int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) w[i] = i;
    // 从第0个位置开始选
    cout << dfs(1, 0, 0) / 2;
}