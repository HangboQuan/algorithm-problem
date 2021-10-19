//
// Created by quanhangbo on 2021/9/21.
//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> nums;
void dfs(int k){

    if(nums.size() > m || nums.size() + (n - k + 1) < m)
        return;

    if(k == n + 1){
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        return ;
    }
    // 选择这个数
    nums.push_back(k);
    dfs(k + 1);
    // 回溯
    nums.pop_back();

    // 不选择这个数
    dfs(k + 1);
}

int main(void){
    cin >> n >> m;
    dfs(1);
    return 0;
}
