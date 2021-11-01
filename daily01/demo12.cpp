//
// Created by quanhangbo on 2021/10/30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<int> analysisHistogram(vector<int> &heights, int cnt){
        sort(heights.begin(), heights.end());
        int n = heights.size(), i, j;
        for(i = j = 0; i + cnt <= n; i ++){
            if(heights[i + cnt - 1] - heights[i] < heights[j + cnt - 1] - heights[j]){
                j = i;
            }
        }
        vector<int> ans;
        for(i = 0; i < cnt; i ++){
            ans.push_back(heights[i + j]);

        }
        return ans;
    }

    int main(){

    }
};

