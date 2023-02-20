//
// Created by quanhangbo on 2023/2/20 22:03.
//

#include<iostream>
#include<vector>
using namespace std;

// 超时
int subarraySum(vector<int>& nums, int k) {
    vector<int> preSum(nums.size() + 1, 0);
    for(int i = 0; i < nums.size(); i ++ ) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    int ans = 0;
    for(int i = 1; i <= nums.size(); i ++ ) {
        for(int j = 0; j < i; j ++ ) {
            if (preSum[i] - preSum[j] == k) {
                ans ++;
            }
        }
    }
    return ans;
}