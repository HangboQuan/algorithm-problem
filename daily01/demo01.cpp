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
int main(){
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    vector<int> ans(5, 1);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    string a = "123";
    cout << a.length() << a.size();
    a.replace(0, 1, "1");
    cout << a;

    cout << endl;
    vector<int> arr{1, 2, 3, 3, 3, 3, 4, 5};
    cout << getNumberOfK(arr, 3);

}
