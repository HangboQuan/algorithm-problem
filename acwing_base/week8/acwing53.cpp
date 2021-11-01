//
// Created by quanhangbo on 2021/11/1.
//

// https://www.acwing.com/problem/content/49/
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int> v;
        for(int i = 0; i < k; i ++ ){
            v.push_back(input[i]);
        }
        return v;
    }
};

