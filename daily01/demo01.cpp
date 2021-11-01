//
// Created by quanhangbo on 2021/9/20.
//
#include<iostream>
#include<vector>

using namespace std;


int getNumberOfK(vector<int>& nums , int k) {
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == k) {
            cnt++;
        }
    }
    return cnt;
}

int getNumberOfK2(vector<int>& nums , int k) {
    // 使用二分
    if(nums.empty()){
        return 0;
    }
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(nums[mid] != mid){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(r == nums[r]){
        r++;
    }
    return r;

}

void hello(){
    vector<int> ans = {0, 3, 2, 5, 8, 4, 7, 6};
    int n = ans.size();
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 2; j--){
            if(ans[j] < ans[j - 1]) {
                int t = ans[j - 1];
                ans[j - 1] = ans[j];
                ans[j] = t;
            }
        }
    }
    for(auto x : ans){
        cout << x << " ";
    }
}

void test(){
    int a, n;
    while(cin >> n && n > 1){
        cout << n;
    }
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    for(int i = 0; i < nums1.size(); i++){
        bool flag = false;
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[i] == nums2[j]){
                for(int k = j + 1; k < nums2.size(); k++){
                    if(nums2[k] > nums1[i]){
                        ans.push_back(nums2[k]);
                        flag = true;
                        break;
                    }
                }
                break;
            }
        }
        if(!flag){
            ans.push_back(-1);
        }
    }
    return ans;
}

int main(){
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> a = nextGreaterElement(nums1, nums2);
    for(int i = 0; i < a.size(); i ++){
        cout << a[i] << " ";
    }
    return 0;
}

