//
// Created by quanhangbo on 2023/2/17 10:24.
//

#include<iostream>
#include<vector>
#include<array>
using namespace std;
// [1, 7, 3, 6, 5, 6]
// exc: [0, 1, 8, 11, 17, 22, 28]
// pre sum前缀和 典型应用  https://leetcode.cn/problems/find-pivot-index/
int pivotIndex(vector<int>& nums) {
//    int size = nums.size() + 1;
//    int sum[nums.size() + 1] = {0};
//    array<int, nums.size() + 1> = {0};
//    int sum[7] = {0};
//
//    for (int i = 0; i < nums.size() - 1; i ++ ) {
//        cout << nums[i] << " " << sum[i] << " ";
//        sum[i + 1] = nums[i] + sum[i];
//    }
//
//    int len = nums.size();
//    for(int i = 1; i < sizeof(sum) / sizeof(sum[0]); i ++ ) {
//        int index = i;
//        cout << sum[index - 1] << " " << sum[len - 1] - sum[index + 1] << endl;
//        if (sum[index - 1] == sum[len - 1] - sum[index + 1]) {
//            return index;
//        }
//    }
//    return -1;
/**
 * convert this java code to C++
 * public int pivotIndex(int[] nums) {
        int[] sum = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i ++ ) {
            sum[i + 1] = nums[i] + sum[i];
        }

        for (int i = 0; i < nums.length; i ++ ) {
            if (sum[i] == sum[nums.length] - sum[i + 1]) {
                return i;
            }
        }
        return -1;
    }
 */
//    vector<int> sum(nums.size() + 1);
//    for (int i = 0; i < nums.size(); i ++ ) {
//        sum[i + 1] = nums[i] + sum[i];
//    }
//
//    for (int i = 0; i < nums.size(); i ++ ) {
//        if (sum[i] == sum[nums.size()] - sum[i + 1]) {
//            return i;
//        }
//    }
//    return -1;

    int sum = 0;
    int sumLeft = 0;
    for (int i = 0; i < size(nums); i ++ ) {
        sum += nums[i];
    }

    for (int i = 0; i < size(nums); i ++ ) {
        if (sumLeft * 2 + nums[i] == sum) {
            return i;
        }
        sumLeft += nums[i];
    }
    return -1;

}



int main(void) {
    vector<int> ans = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(ans);
}
