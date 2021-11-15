//
// Created by quanhangbo on 2021/11/14 22:36.
//
#include<vector>
using namespace std;
class Solution {
public:
    // int findMin(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums[0];
    // }

    /*
        二分：二分并不一定是有序区间 但是只要能将问题转为两部分：一部分满足某属性 一部分不满足某属性
        对于此题：假设最小值为x,则可以发现x的右侧区间<必<= nums[nums.size() - 1]; x的左侧区间 >= nums[nums.size() - 1]

    */
    int findMin(vector<int>& nums){
        /* 此种写法 把mid包含在性质中 是错的
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[r]){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return nums[l];*/
        int l = 0, r = nums.size() - 1;
        while(l < r){
            // 此种情况是将mid 不包含在性质中
            int mid = l + r >> 1;
            if(nums[mid] <= nums[r]){
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        return nums[l];

    }
};