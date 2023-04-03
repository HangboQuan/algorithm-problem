//
// Created by quanhangbo on 2023/4/2 16:40.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int N = 210;
int arr[N];
//class Solution {
//public:
//    vector<vector<int>> findMatrix(vector<int>& nums) {
//        for (auto x : nums) {
//            arr[x] ++;
//        }
//        vector<vector<int>> result;
//        bool con = false;
//        int n = 0;
//        while(!con) {
//            vector<int> ans;
//            for (int i = 0; i < N; i ++ ) {
//                if (arr[i] != 0) {
//                    ans.push_back(i);
//                    arr[i] -= 1;
//                }
//            }
//            result.push_back(ans);
//            int i = 0;
//            for (; i < N; i ++ ) {
//                if (arr[i] != 0) {
//                    con = false;
//                    break;
//                }
//            }
//            if (i == N) con = true;
//        }
//        return result;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> findMatrix(vector<int>& nums) {
//        int n = nums.size(), m, i, j;
//        vector<int> s(n + 1);
//        for (auto& x : nums) {
//            s[x] ++;
//        }
//        // max_element() 返回的是指向最大元素的迭代器
//        // *max_element() 返回的是最大值的具体数值
//        m = *max_element(s.begin(), s.end());
//        cout << m << endl;
//        vector<vector<int>> ans(m);
//        for (i = 0; i < m; i ++ ) {
//            for (int j = 0; j <= n; j ++) {
//                if (s[j]) {
//                    ans[i].push_back(j);
//                    s[j] --;
//                }
//            }
//        }
//        return ans;
//    }
//};

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> ctr;
        vector<vector<int>> ans;
        for(int x : nums) {
            ++ ctr[x];
        }

        for (auto& it : ctr) {
            // 不能没有这段 resize的代码
            if (ans.size() < it.second) {
                ans.resize(it.second);
            }
            for (int i = 0; i < it.second; i ++ ) {
                ans[i].push_back(it.first);
            }
        }
        return ans;
    }
};

int main(void) {
    Solution* s = new Solution;
    vector<int> nums = {1,3,4,1,2,3,1};
    vector<vector<int>> ans = (s -> findMatrix(nums));
    for(auto& x : ans) {
        for(auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}
