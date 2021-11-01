//
// Created by quanhangbo on 2021/11/1.
//

// https://www.acwing.com/problem/content/submission/71/
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i ++ ){
            for(int j = 0; j < nums.size(); j ++ ){
                if(nums[i] + nums[j] == target){
                    return vector<int>{nums[i], nums[j]};
                }
            }
        }
    }
};
