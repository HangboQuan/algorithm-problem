//
// Created by quanhangbo on 2021/11/11 22:59.
//

// 题目链接：https://leetcode-cn.com/problems/intersection-of-two-arrays/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> vec;
        for(int i = 0; i < nums1.size(); i ++ ){
            int target = nums1[i];
            int index = binary_search(nums2, target);
            if(index != -1){
                vec.push_back(nums1[i]);
            }
        }
        unordered_set<int> s(vec.begin(), vec.end());
        vector<int> res;
        for(auto v = s.begin(); v != s.end(); v ++ ){
            res.push_back(*v);
        }
        return res;
    }

    int binary_search(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(nums[l] != target){
            return -1;
        }
        return l;
    }


    // 利用set去重
    /*vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for(auto& num : nums1){
            s1.insert(num);
        }
        for(auto& num : nums2){
            s2.insert(num);
        }
        return check(s1, s2);
    }

    vector<int> check(unordered_set<int> s1, unordered_set<int> s2){
        if(s1.size() > s2.size()){
            return check(s2, s1);
        }
        vector<int> vec;
        for(auto& num : s1){
            // count方法判断num存在s2中返回1，否则返回0
            if(s2.count(num)){
                vec.push_back(num);
            }
        }
        return vec;
    }*/

    // 排序 + 双指针
    /*vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1 = 0, index2 = 0;
        vector<int> vec;
        while(index1 < nums1.size() && index2 < nums2.size()){
            if(nums1[index1] == nums2[index2]){
                if(!vec.size() || nums1[index1] != vec.back()){
                    vec.push_back(nums1[index1]);
                }
                index1 ++;
                index2 ++;
            }else if(nums1[index1] < nums2[index2]){
                index1 ++;
            }else{
                index2 ++;
            }
        }
        return vec;
    }*/
};