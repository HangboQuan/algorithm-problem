//
// Created by quanhangbo on 2021/11/8 21:22.
//
// 题目链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& a, int l, int r, int target){
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if(a[l] != target){
        return -1;
    }
    return l;
}
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i ++ ){
        int n = target - nums[i];
        int index = binary_search(nums, i + 1, nums.size() - 1, n);
        if(index != -1){
            return vector<int>{i + 1, index + 1};
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> ans = {0, 0, 3, 4};
    vector<int> res = twoSum(ans, 0);
    cout << res[0] << " " << res[1] << endl;
}
