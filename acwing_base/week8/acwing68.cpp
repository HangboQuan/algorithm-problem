//
// Created by quanhangbo on 2021/11/1.
//
// https://www.acwing.com/problem/content/64/
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        // 使用二分
        if(nums.empty()){
            return 0;
        }
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] != mid){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(r == nums[r]){
            r++;
        }
        return r;
    }
};

