//
// Created by quanhangbo on 2021/11/12 0:04.
//

#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 用二分来做，遍历一个元素判断他最开始的位置和最末尾的位置，判断是否一致，如果一致则返回该值
        for(int i = 0; i < nums.size(); i ++ ){
            int num = nums[i];
            int index1 = binary_search_first(nums, num);
            int index2 = binary_search_end(nums, num);
            if(index1 == index2){
                return nums[i];
            }
        }
        return -1;
    }

    int binary_search_first(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int binary_search_end(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }


    /*int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() >= 2 && nums[0] != nums[1]){
            return nums[0];
        }

        for(int i = 3; i < nums.size(); i += 2 ){
            if(nums[i - 1] != nums[i]){
                return nums[i - 1];
            }
        }
        return nums[nums.size() - 1];
    }*/

    /*int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        for(auto a : nums){
            result ^= a;
        }
        return result;
    }*/
};
