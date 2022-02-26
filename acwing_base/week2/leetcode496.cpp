//
// Created by quanhangbo on 2022/2/26 23:37.
//
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    int stk[1010], tt;
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> res;
        unordered_map<int, int> hashmap;
        for(int i = nums2.size() - 1; i >= 0; i -- ){
            while(tt && stk[tt] <= nums2[i]) tt --;
            if(tt) {
                ans.push_back(stk[tt]);
                hashmap.insert({nums2[i], stk[tt]});
            }else{
                ans.push_back(-1);
                hashmap.insert({nums2[i], -1});
            }

            stk[++ tt] = nums2[i];
        }
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < nums1.size(); i ++ ){
            res.push_back(hashmap[nums1[i]]);
        }
        return res;
    }


};

