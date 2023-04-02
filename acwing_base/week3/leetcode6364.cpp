//
// Created by quanhangbo on 2023/4/2 17:10.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100010;
int arr[N];

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size(), ans = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i ++ ) {
            diff[i] = reward1[i] - reward2[i];
            ans += reward2[i];
        }

        sort(diff.begin(), diff.end(), greater<int>());
        for (int i = 0; i < k; ++ i) {
            ans += reward1[i];
        }
        return ans;
    }
};

int main(void) {
    Solution* s = new Solution;
    vector<int> vec1 = {2, 1};
    vector<int> vec2 = {1, 2};
    cout << s -> miceAndCheese(vec1, vec2, 2);
}