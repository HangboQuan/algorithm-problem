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
        vector<int> ans;
        for (int i = 0; i < reward1.size(); i ++ ) {
            ans.push_back(reward1[i] > reward2[i] ? reward1[i] : reward2[i]);
        }
        sort(ans.rbegin(), ans.rend());

        arr[0] = ans[0];
        for (int i = 1; i < ans.size(); i ++ ) {
            arr[i] = arr[i - 1] + ans[i];
        }

        if (k % 2 == 1) {
            // even
            return arr[k - 1];
        } else {
            if (k * 2 <= reward1.size()) {
                return max(arr[k - 1], arr[k * 2 - 1]);
            }
            return arr[k - 1];
        }

        for (int i = 0; i < N; i ++ ) {
            cout << arr[i] << " ";
        }
        // 前缀和
        cout << endl;


        // if k is even, return top k

    }
};

int main(void) {
    Solution* s = new Solution;
    vector<int> vec1 = {2, 1};
    vector<int> vec2 = {1, 2};
    cout << s -> miceAndCheese(vec1, vec2, 2);
}