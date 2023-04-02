//
// Created by quanhangbo on 2023/4/2 16:40.
//

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int N = 210;

int arr[N];

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        for (auto x : nums) {
            arr[x] ++;
        }
        vector<vector<int>> result;
        bool con = false;
        int n = 0;
        while(!con) {
            vector<int> ans;

            for (int i = 0; i < N; i ++ ) {
                if (arr[i] != 0) {
                    ans.push_back(i);
                    arr[i] -= 1;
                }
            }
            result.push_back(ans);
            int i = 0;
            for (; i < N; i ++ ) {
                if (arr[i] != 0) {
                    con = false;
                    break;
                }
            }
            if (i == N) con = true;
        }
        return result;
    }
};

int main(void) {
    Solution* s = new Solution;
    vector<int> nums = {1,3,4,1,2,3,1};
    s -> findMatrix(nums);
}
