//
// Created by quanhangbo on 2021/11/1.
//

// https://www.acwing.com/problem/content/63/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == k) {
                cnt++;
            }
        }
        return cnt;
    }


};

int main(void){
    vector<int> a = {1, 2, 3, 3, 3, 3, 4, 5};
    Solution s = Solution();
    cout << s.getNumberOfK(a, 3);
}